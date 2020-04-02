#include <iostream>
#include "repl.hpp"

using namespace std;


int main(){
    lisp::Repl *repl = new lisp::Repl();
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
