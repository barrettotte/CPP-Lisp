#include <iostream>
#include "lisp.hpp"

using lisp::Env;
using lisp::EnvSymbol;
using lisp::Procedure;
using lisp::Repl;

using std::cout;
using std::endl;


/* Deferrable:
    - reader - string, nil, true, false
    - macros
    - Exp types: keyword, vector, hashmap
    - comment support
*/

int main(){
    Repl repl;
    string line = "";
    Env env = repl.getEnv();

    cout << "========== CPP-Lisp ==========\n";
    cout << "       (CTRL+D to exit)\n> ";

    while(getline(std::cin, line)){
        cout << repl.rep(line, env) << "\n> ";
    }
    cout << endl;

    // Test function pointers:    
    cout << "1 + 2 = " << env.get("+").getProcedure().invoke(1,2) << endl;
    cout << "1 - 2 = " << env.get("-").getProcedure().invoke(1,2) << endl;
    cout << "1 * 2 = " << env.get("*").getProcedure().invoke(1,2) << endl;
    cout << "1 / 2 = " << env.get("/").getProcedure().invoke(1,2) << endl;
    env.printEnv();

    return 0;
}


