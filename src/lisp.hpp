#ifndef LISP_H
#define LISP_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "types.hpp"

using std::list;
using std::string;
using std::vector;

namespace lisp{

    class Parser{
        public:
            Exp parse(const string &pgm);
        private:
            vector<string> tokens;
            vector<string> tokenize(const string &s);
            Exp readTokens(vector<string> &tokens);
            Atom makeAtom(const string token);
    };


    /* utils.cpp */
    bool isNumber(const string s);

}

#endif
