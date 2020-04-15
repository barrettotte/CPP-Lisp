#include "types.hpp"


namespace lisp{

    /***************** Exp.class ********************/
    ExpType Exp::getType(){
        return this->type;
    }

    string Exp::getValue(){
        return this->value;
    }

    Exp Exp::getChild(const size_t i){
        if(i > getChildrenSize()){
            std::cerr << "Index out of bounds.\n";
            exit(1);
        }
        return this->children[i];
    }

    size_t Exp::getChildrenSize(){
        return this->children.size();
    }

    vector<Exp> Exp::getChildren(){
        return this->children;
    }

    List Exp::asList(){
        return List(this);
    }

    string Exp::toString(const size_t lvl){
        string s = "";
        if(this->type == LNil){
            return s;
        } else if(this->type == LSymbol || this->type == LNumber){
            if(this->value.length() > 0){
                s += this->value + "\n";
            }
        } else{
            s += "(";
            if(this->children.size() > 0){
                s += "\n";
                for(size_t i = 0; i < this->children.size(); i++){
                    for(size_t j = 0; j <= lvl; j++){
                        s += "  ";
                    }
                    s += (this->children.at(i).toString(lvl+1));
                }
                for(size_t x = 0; x < lvl; x++){
                    s += "  ";
                }
            }
            s += ")\n";   
        }
        return s;
    }


    /***************** Atom.class *******************/
    Atom::Atom(const string token){
        this->value = token;
    }


    /***************** List.class *****************/
    List::List(){
        this->type = LList;
    }

    List::List(vector<Exp> l){
        this->type = LList;
        this->children = l;
    }

    List::List(Exp *exp){
        this->type = LList;
        this->children = exp->getChildren();
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

    List::~List(){
        this->children.clear();
    }

}
