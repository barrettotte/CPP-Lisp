#include <regex>
#include <string>
#include "lisp.hpp"

namespace lisp{

    // split string into tokens
    vector<string> Parser::tokenize(const string &in){
        string s = std::regex_replace(in, std::regex("\\("), " ( ");
        s = std::regex_replace(s, std::regex("\\)"), " ) ");

        std::istringstream iss(s);
        vector<string> tokens(
            std::istream_iterator<string>{iss}, 
            std::istream_iterator<string>()
        );
        return tokens;
    }

    // read an expression from a string
    Exp Parser::parse(const string &pgm){
        vector<string> tokens(tokenize(pgm));
        return readTokens(tokens);
    }

    // read expression from list of tokens
    Exp Parser::readTokens(vector<string> &tokens){
        if(tokens.size() == 0){
            std::cerr << "Unexpected EOF.\n";
            exit(1);
        }

        string token(tokens.at(0));
        tokens.erase(tokens.begin());

        if(token == "("){
            List l;
            while(tokens.front() != ")"){
                l.add(readTokens(tokens));
            }
            tokens.erase(tokens.begin());
            return l;

        } else if(token == ")"){
            std::cerr << "unexpected ')'.\n";
            exit(1);
        } else{
            return makeAtom(token);
        }
    }

    // make an atom depending on type
    Atom Parser::makeAtom(const string token){
        if(isNumber(token)){
            return Number(token);
        }
        return Symbol(token);
    }

}