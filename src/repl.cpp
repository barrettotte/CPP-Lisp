#include "lisp.hpp"

using std::string;

namespace lisp{
    
    LispType Repl::read(const string &s){
        return read_str(s);
    }

    LispType Repl::eval(LispType t){
        return t;
    }

    string Repl::print(LispType t){
        return print_str(t);
    }

    string Repl::rep(const string &s){
        return print(eval(read(s)));
    }

}
