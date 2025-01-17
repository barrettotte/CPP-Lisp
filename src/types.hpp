#ifndef LISP_TYPES_H
#define LISP_TYPES_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

namespace lisp{

    enum ExpType{
        LSymbol, LNumber, LList, LNil, LBool, LIgnore
    };

    class List;

    class Exp{
        public:
            string toString(const size_t lvl);
            ExpType getType();
            string getValue();
            Exp getChild(const size_t i);
            vector<Exp> getChildren();
            size_t getChildrenSize();
            List asList();
        protected:
            string value;
            vector<Exp> children;
            ExpType type;
    };

    class List: public Exp{
        public:
            List();
            List(vector<Exp> l);
            List(Exp *exp);
            void add(Exp child);
            Exp get(const size_t i);
            ~List();
    };

    class Atom: public Exp{
        public:
            Atom(const string token);
            Atom(Exp *exp);
    };

    class Symbol: public Atom{
        public:
            Symbol(const string token): Atom(token){this->type = LSymbol;};
    };

    class Number: public Atom{
        public:
            Number(const string token): Atom(token){this->type = LNumber;};
    };

    class Ignore: public Atom{
        public:
            Ignore(): Atom(""){this->type = LIgnore;}
    };

    class Nil: public Atom{
        public:
            Nil(): Atom("nil"){this->type = LNil;}
    };

    class Bool: public Atom{
        public:
            Bool(const string token): Atom(token){this->type = LBool;};
    };

}

#endif
