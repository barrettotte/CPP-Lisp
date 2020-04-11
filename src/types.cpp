#include "types.hpp"


namespace lisp{

    Number::Number(const string token){
        this->value = token;
    }

    Symbol::Symbol(const string token){
        this->value = token;
    }

    string Exp::toString(const size_t lvl){
        string s = "";

        if(this->value.length() > 0){
            s += "'" + this->value + "'\n";
        }
        if(this->children.size() > 0){
            s += "[\n";
            for(size_t i = 0; i < this->children.size(); i++){
                for(size_t j = 0; j <= lvl; j++){
                    s += "  ";
                }
                s += (this->children.at(i).toString(lvl+1));
            }
            for(size_t x = 0; x < lvl; x++){
                s += "  ";
            }
            s += "]\n";
        }
        return s;
    }

    Exp::~Exp(){
        this->children.clear();
    }

    void List::add(const Exp child){
        this->children.push_back(child);
    }

    Exp List::get(const size_t i){
        if(i > this->children.size()){
            std::cerr << "Index out of bounds.\n";
        }
        return this->children.at(i);
    }

}
