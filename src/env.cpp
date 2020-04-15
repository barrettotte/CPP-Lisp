#include "env.hpp"

namespace lisp{

    /******************* EnvSymbol.class *********************/

    EnvSymbol::EnvSymbol(){
        this->identifier = "?";
        this->type = TVoid;
    }

    EnvSymbol::EnvSymbol(const string identifier, const Procedure &v){
        this->identifier = identifier;
        this->v_p = v;
        this->type = TProcedure;
    }

    EnvSymbol::EnvSymbol(const string identifier, const int v){
        this->identifier = identifier;
        this->v_i = v;
        this->type = TInt;
    }

    EnvSymbol::EnvSymbol(const string identifier, const double v){
        this->identifier = identifier;
        this->v_d = v;
        this->type = TDouble;
    }

    EnvSymbol::EnvSymbol(const string identifier, const string v){
        this->identifier = identifier;
        this->v_s = v;
        this->type = TString;
    }

    EnvSymbol::EnvSymbol(const string identifier, const bool v){
        this->identifier = identifier;
        this->v_b = v;
        this->type = TBool;
    }

    bool EnvSymbol::isProcedure(){
        return this->type == TProcedure;
    }

    bool EnvSymbol::isInt(){
        return this->type == TInt;
    }

    bool EnvSymbol::isDouble(){
        return this->type == TDouble;
    }

    bool EnvSymbol::isString(){
        return this->type == TString;
    }

    bool EnvSymbol::isBool(){
        return this->type == TBool;
    }

    string EnvSymbol::asString(){
        switch(this->type){
            case TProcedure: return this->identifier + " x y";                
            case TString:    return this->v_s;                
            case TInt:       return std::to_string(this->v_i);
            case TDouble:    return std::to_string(this->v_d);
            case TBool:      return std::to_string(this->v_b);
            default:         return "void";
        }
    }

    EnvSymbolType EnvSymbol::getType(){
        return this->type;
    }

    string EnvSymbol::getIdentifier(){
        return this->identifier;
    }

    Procedure EnvSymbol::getProcedure(){
        return this->v_p;
    }

    int EnvSymbol::getInt(){
        return this->v_i;
    }

    double EnvSymbol::getDouble(){
        return this->v_d;
    }

    string EnvSymbol::getString(){
        return this->v_s;
    }

    bool EnvSymbol::getBool(){
        return this->v_b;
    }


    /******************* Env.class *********************/
    
    // workaround annoying default copy constructor...
    void Env::init(Env *outer){
        this->outer = outer;
    }

    EnvSymbol Env::get(const string k){
        Env *env = this->find(k);
        if(env){
            return env->data[k];
        }
        std::cerr << "Could not find symbol '" + k + "'\n";
        exit(1);
    }

    // find symbol in current env, or search recursively in outer environments
    Env* Env::find(const string k){
        std::map<string,EnvSymbol>::iterator res = this->data.find(k);
        if(res != this->data.end()){
            return this;    
        } else if(this->outer != nullptr){
            return this->outer->find(k);
        } 
        return nullptr;
    }

    void Env::set(const string k, const EnvSymbol &v){
        this->data[k] = v;
    }

    void Env::remove(const string k){
        this->data.erase(k); // returns a size_t == keys erased
    }

    void Env::printEnv(){
        std::map<string, EnvSymbol>::iterator itr;
        std::cout << "env {" << std::endl;
        for(itr = this->data.begin(); itr != this->data.end(); ++itr){
            std::cout << "  '" << itr->first << "': " << itr->second.asString() << std::endl;
        }
        std::cout << "}" << std::endl;
    }

    Env::~Env(){
        this->data.clear();
    }

}
