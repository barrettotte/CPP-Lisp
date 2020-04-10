#include <iostream>
#include "lisp.hpp"

using namespace std;
using lisp::Parser;


int main(){
    string line = "";

    cout << "========== CPP-Lisp ==========\n";
    //cout << "       (CTRL+D to exit)\n> ";

    Parser parser = Parser();
    string pgm = "(begin (define r 10) (* pi (* r r)))";
    
    lisp::Exp exp = parser.parse(pgm);
    cout << exp.toString(0) << endl;

    cout << endl;
    return 0;
}


