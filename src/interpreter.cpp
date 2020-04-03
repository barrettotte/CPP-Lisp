#include <iostream>
#include "repl/repl.hpp"

using namespace std;
using lisp::Repl;


int main(){
    Repl *repl = new Repl();
    string line = "";

    cout << "========== CPP-Lisp ==========\n";
    cout << "       (CTRL+D to exit)\n> ";

    while(getline(cin, line)){
        repl->rep(line);
        cout << line << "\n> ";
    }
    cout << endl;

    return 0;
}
