#include "lisp.hpp"

namespace lisp{

    Repl::Repl(){
        this->parser = Parser();
        initEnv();
    }

    void Repl::initEnv(){
        
    }
    
    Exp Repl::read(const string &s){
        return this->parser.parse(s);
    }

    Exp Repl::eval(Exp exp, Env &env){
        return exp;
    }

    string Repl::print(Exp exp){
        return exp.toString(0);
    }

    string Repl::rep(const string &s, Env &env){
        return print(eval(read(s), env));
    }
}
