#include "lisp.hpp"

namespace lisp{

    // assert cond, output stderr and exit(1) if !cond
    void assert_withMsg(const bool cond, const std::string msg){
        if(!cond){
            std::cerr << msg << std::endl;
            exit(1);
        }
    }


    // Exit with error if character does not match expected
    void assert_parse(const char actual, const char expected){
        if(actual != expected){
            std::cerr << "Parse error: Expected '" << expected << "'.\n";
            exit(1);   
        }
    }

}
