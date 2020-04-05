#include <iostream>
#include "lisp.hpp"

using namespace std;

namespace lisp{

    string print_str(LispType t){
        return t.print();
    }

}