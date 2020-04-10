#include <assert.h>
#include <iostream>
#include "lisp.hpp"

using namespace std;

namespace lisp{

    string LispType::print(){ 
        return ""; 
    }

    /********************* LispList *********************/
    LispType LispList::at(const size_t i){
        assert((i >= 0 && i < this->value.size())
            && "Index out of bounds");
        return this->value.at(i);
    }

    void LispList::push_back(LispType x){
        this->value.push_back(x);
    }

    string LispList::print(){
        string s = "\n(";
        for(size_t i = 0; i < this->value.size()-1; i++){
            s += (this->value.at(i).print() + " ");
        }
        return s + "\n)";
    }

    LispList::~LispList(){
        this->value.clear();
    }


    /********************* LispAtom *********************/
    LispAtom::LispAtom(LispType v){
        this->value = v;
    }

    string LispAtom::print(){
        return "atom " + this->value.print();
    }


    /******************** LispKeyword *******************/
    LispKeyword::LispKeyword(const string v){
        this->value = v;
    }

    string LispKeyword::print(){
        return "keyword " + this->value;
    }


    /********************* LispNumber *******************/
    LispNumber::LispNumber(const int v){
        this->value = v;
    }

    string LispNumber::print(){
        return to_string(this->value);
    }


    /******************** LispSymbol ********************/
    LispSymbol::LispSymbol(const string v){
        this->value = v;
    }
    
    string LispSymbol::print(){
        return this->value;
    }

}
