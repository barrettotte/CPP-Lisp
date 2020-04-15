#include <fstream>
#include <iostream>
#include "lisp.hpp"

using lisp::Env;
using lisp::Repl;

using std::cout;
using std::endl;


/* Deferrable:
    - reader - string, nil, true, false
    - macros
    - Exp types: keyword, vector, hashmap
    - comment support
*/

int main(int argc, char **argv){
    Repl repl;
    Env env = repl.getEnv();
    string line = "";

    if(argc == 2){
        cout << "Loading file " << argv[1] << endl;
        std::ifstream src(argv[1]);
        while(getline(src, line)){
            //cout << "reading '" << line << "'" << endl;
            cout << repl.rep(line, env);
        }
        src.close();
    } else if(argc == 1){
        cout << "========== CPP-Lisp ==========\n" << "      (CTRL+D to exit)\n> ";
        while(getline(std::cin, line)){
            cout << repl.rep(line, env) << "\n> ";
        }
    } else{
        cout << "Usage: lisp [filename]";
        return 1;
    }
    
    cout << endl;
    env.printEnv();

    return 0;
}


