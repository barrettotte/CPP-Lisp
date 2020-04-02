#include "repl.hpp"

using std::string;

namespace lisp{
    
    string Repl::read(const string &s){
        return s;
    }

    string Repl::eval(const string &s){
        return s;
    }

    string Repl::print(const string &s){
        return s;
    }

    string Repl::rep(const string &s){
        return print(eval(read(s)));
    }

}
