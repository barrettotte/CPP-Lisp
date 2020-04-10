#ifndef LISP_TYPES_H
#define LISP_TYPES_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

namespace lisp{

    class Exp{
        public:
            string toString(const size_t lvl);
            ~Exp();
        protected:
            string value;
            vector<Exp> children;
    };

    class Atom: public Exp{
        public:
        private:
    };

    class List: public Exp{
        public:
            void add(Exp child);
            Exp get(const size_t i);
        private:
    };

    class Symbol: public Atom{
        public:
            Symbol(const string token);
        private:
    };

    class Number: public Atom{
        public:
            Number(const string token);
        private:
    };

    class Env{
        public:
            Env();
        private:
    };

}

#endif
