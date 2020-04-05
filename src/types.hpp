#ifndef LISP_TYPES_H
#define LISP_TYPES_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

namespace lisp{

    class LispType{
        public:
            virtual string print();
        private:
    };

    class LispList : public LispType{
        public:
            // TODO: constructor
            LispType at(const size_t i);
            void push_back(LispType x);
            string print() override;
            ~LispList();
        private:
            vector<LispType> value;
    };

    class LispAtom : public LispType{
        public:
            LispAtom(LispType v);
            string print() override;
        private:
            LispType value;
    };

    class LispNumber : public LispType{
        public:
            LispNumber(const int v);
            string print() override;
        private:
            int value;
    };

    class LispSymbol : public LispType{
        public:
            LispSymbol(const string s);
            string print() override;
        private:
            string value;
    };
    
    // TODO: string
    // TODO: nil
    // TODO: true / false
    // TODO: keyword
}

#endif
