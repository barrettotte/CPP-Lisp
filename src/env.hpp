#ifndef LISP_ENV_H
#define LISP_ENV_H

#include <iostream>
#include <map>
#include <string>

using std::string;

namespace lisp{

    enum EnvSymbolType{
        TVoid, TProcedure, TInt, TDouble, TString, TBool
    };

    class Procedure{
        public:
            Procedure();
            Procedure(int (*f)(const int x, const int y));
            int invoke(const int x, const int y);
        private:
            int (*f)(const int x, const int y);
    };

    class EnvSymbol{
        public:
            EnvSymbol();
            EnvSymbol(const string identifier, const Procedure &v);
            EnvSymbol(const string identifier, const int v);
            EnvSymbol(const string identifier, const double v);
            EnvSymbol(const string identifier, const string v);
            EnvSymbol(const string identifier, const bool v);

            bool isProcedure();
            bool isInt();
            bool isDouble();
            bool isString();
            bool isBool();

            string asString();
            EnvSymbolType getType();
            string getIdentifier();

            Procedure getProcedure();
            int getInt();
            double getDouble();
            string getString();
            bool getBool();

        private:
            string identifier;
            EnvSymbolType type;
            Procedure v_p;
            int v_i;
            double v_d;
            string v_s;
            bool v_b;
    };

    class Env{
        public:
            EnvSymbol get(const string k);
            void update(const string k, const EnvSymbol &v);
            void remove(const string k);
            void printEnv();
            ~Env();
        private:
            std::map<string, EnvSymbol> env;
    };
     
}

#endif
