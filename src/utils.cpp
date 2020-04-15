#include "lisp.hpp"


namespace lisp{

    bool isNumber(const string s){
        for(size_t i = 0; i < s.length(); i++){
            if(i == 0 && s[i] == '-'){
                continue; // detect negative number
            }
            if(!isdigit(s[i]) && s[i] != '.'){
                return false;
            }
        }
        return true;
    }

}
