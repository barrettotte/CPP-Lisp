#include "lisp.hpp"

namespace lisp{

    /**************** Procedure.class ********************/
    Procedure::Procedure(){
        this->f = nullptr;
    }

    Procedure::Procedure(int (*f)(const int x, const int y)){
        this->f = f;
    }

    int Procedure::invoke(const int x, const int y){
        return this->f(x, y);
    }


    /**************** Procedure Implementations ********************/

    int add(const int x, const int y){
        return x + y;
    }

    int sub(const int x, const int y){
        return x - y;
    }

    int mul(const int x, const int y){
        return x * y;
    }

    int div(const int x, const int y){
        if(y == 0){
            std::cerr << "Divide by zero detected.\n";
            exit(1);
        }
        return x / y;
    }

}
