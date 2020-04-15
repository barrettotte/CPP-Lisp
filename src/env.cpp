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
            case TVoid:      return "void";
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

    EnvSymbol Env::get(const string k){
        return this->env[k];
    }

    void Env::update(const string k, const EnvSymbol &v){
        this->env[k] = v;
    }

    void Env::remove(const string k){
        this->env.erase(k); // returns a size_t == keys erased
    }

    void Env::printEnv(){
        std::map<string, EnvSymbol>::iterator itr;
        std::cout << "env {" << std::endl;
        for(itr = this->env.begin(); itr != this->env.end(); ++itr){
            std::cout << "  '" << itr->first << "': " << itr->second.asString() << std::endl;
        }
        std::cout << "}" << std::endl;
    }

    Env::~Env(){
        this->env.clear();
    }

}
