#ifndef LISP_H
#define LISP_H

#include <iostream>
#include <vector>
#include "types.hpp"

using std::string;
using std::vector;

namespace lisp{

    class Repl{
        public:
            LispType read(const string &s);
            LispType eval(LispType t);
            string print(LispType t);
            string rep(const string &s);
    };

    
    string print_str(LispType t);
    LispType read_str(const string &s);


    /* utils.cpp */
    void assert_withMsg(const bool cond, const string msg);
    void assert_parse(const char actual, const char expected);

}

#endif
