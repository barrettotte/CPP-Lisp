#include <iostream>
#include "lisp.hpp"

using namespace std;
using lisp::Repl;

int main(){
    Repl *repl = new Repl();
    string line = "";

    cout << "========== CPP-Lisp ==========\n";
    cout << "       (CTRL+D to exit)\n> ";

    while(getline(cin, line)){
        cout << repl->rep(line) << "> ";
    }
    cout << endl;

    return 0;
}


