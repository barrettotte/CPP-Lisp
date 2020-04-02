#ifndef LISP_READER_H
#define LISP_READER_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

namespace lisp{

    class Reader{

        public:
            Reader read_str();
            string next();
            string peek();

        private:
            vector<string> tokenize(string s);

    };

}

#endif
