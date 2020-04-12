#ifndef LISP_H
#define LISP_H

#include <iostream>
#include <functional>
#include <map>
#include <string>
#include <vector>

#include "env.hpp"
#include "types.hpp"

using std::map;
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

    class Repl{
        public:
            Repl();
            void initEnv();
            Exp read(const string &s);
            Exp eval(Exp exp, Env &env);
            string print(Exp exp);
            string rep(const string &s, Env &env);
            ~Repl();
        private:
            Parser parser;
            Env env;
    };


    /* utils.cpp */
    bool isNumber(const string s);

    /* procedure.cpp */
    int add(const int x, const int y);
    int sub(const int x, const int y);
    int mul(const int x, const int y);
    int div(const int x, const int y);

}

#endif
