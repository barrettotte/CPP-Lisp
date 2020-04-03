#ifndef LISP_REPL_H
#define LISP_REPL_H

#include <iostream>

using std::string;

namespace lisp{

    class Repl{
        public:
            string read(const string &s);
            string eval(const string &s);
            string print(const string &s);
            string rep(const string &s);
    };
}

#endif
