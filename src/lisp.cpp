#include "lisp.hpp"

using lisp::Env;
using lisp::EnvSymbol;
using lisp::Procedure;
using lisp::Repl;

using std::cout;
using std::endl;


int main(){
    // Repl *repl = new Repl();
    // string line = "";

    // cout << "========== CPP-Lisp ==========\n";
    // cout << "       (CTRL+D to exit)\n> ";

    // while(getline(cin, line)){
    //     cout << repl->rep(line) << "> ";
    // }
    // cout << endl;


    // Test function pointers:
    Env env;

    Procedure pAdd(&lisp::add);
    Procedure pSub(&lisp::sub);
    Procedure pMul(&lisp::mul);
    Procedure pDiv(&lisp::div);

    EnvSymbol symAdd("+", pAdd);
    EnvSymbol symSub("-", pSub);
    EnvSymbol symMul("*", pMul);
    EnvSymbol symDiv("/", pDiv);

    env.update("+", symAdd);
    env.update("-", symSub);
    env.update("*", symMul);
    env.update("/", symDiv);
    
    cout << "1 + 2 = " << env.get("+").getProcedure().invoke(1,2) << endl;
    cout << "1 - 2 = " << env.get("-").getProcedure().invoke(1,2) << endl;
    cout << "1 * 2 = " << env.get("*").getProcedure().invoke(1,2) << endl;
    cout << "1 / 2 = " << env.get("/").getProcedure().invoke(1,2) << endl;
    
    env.printEnv();

    return 0;
}


