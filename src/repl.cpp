#include "lisp.hpp"

namespace lisp{

    Repl::Repl(){
        this->parser = Parser();
    }
    
    Exp Repl::read(const string &s){
        return this->parser.parse(s);
    }

    Exp Repl::eval(Exp exp){
        return exp;
    }

    string Repl::print(Exp exp){
        return exp.toString(0);
    }

    string Repl::rep(const string &s){
        return print(eval(read(s)));
    }
}
