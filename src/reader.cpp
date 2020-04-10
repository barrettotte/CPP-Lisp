#include <iostream>
#include <regex>
#include <list>
#include "lisp.hpp"

using namespace std;

namespace lisp{

    /****************** class definitions ******************/
    class Reader{
        public:
            Reader(const vector<string> t);
            string fetch();
            string peek();
            ~Reader();
        private:
            vector<string> tokens;
            size_t position;
    };


    /********************* Reader class *********************/
    Reader::Reader(vector<string> t){ 
        this->tokens = t;
        this->position = 0;
    }

    // Return token at current position and increment position
    string Reader::fetch(){
        return this->tokens.at(this->position++);
    }

    // Return token at current position without incrementing position
    string Reader::peek(){
        return this->tokens.at(this->position);
    }
    
    Reader::~Reader(){
        this->tokens.~vector();
    }


    /****************** function prototypes *****************/
    
    static LispType read_form(Reader &reader);
    static LispType read_list(Reader &reader, LispList list, const char start, const char end);
    static LispType read_atom(Reader &reader);

    static vector<string> tokenize(const string &s);


    /********************* functions ************************/
    
    // TODO: desc
    LispType read_str(const string &s){
        auto tokens = tokenize(s);
        Reader reader(tokens);
        return read_form(reader);
    }


    // TODO: desc
    static LispType read_form(Reader &reader){
        auto token = reader.peek();
        
        switch(token.at(0)){
            case '(':  return read_list(reader, LispList(), '(', ')');
            default:   return read_atom(reader);
        }
    }


    // TODO: desc
    static LispType read_list(Reader &reader, LispList list, const char start, const char end){
        auto token = reader.fetch();
        assert_parse(token.at(0), start);
        token = reader.peek();

        while(token.at(0) != end){
            assert_withMsg((token.at(0) != EOF),
                "Unexpected end of file found while reading list.\n");

            list.push_back(read_form(reader));
            token = reader.peek();
        }
        reader.fetch();
        return list;
    }


    // TODO: desc
    static LispType read_atom(Reader &reader){
        regex intRegex("^[-+]?\\d+$");
        string token = reader.fetch();

        if(token.at(0) == ':'){
            return LispKeyword(token);
        } else if(regex_match(token, intRegex)){
            return LispNumber(stoi(token));
        }
        return LispSymbol(token);
    }


    // split string into list of tokens
    static vector<string> tokenize(const string &str){
        vector<string> tokens;
        const char * s = str.c_str();
        while(*s){
            while(*s == ' '){
                ++s; // skip whitespace
            }
            if(*s == '(' || *s == ')'){
                tokens.push_back(*s++ == '(' ? "(" : ")");
            } else{
                const char *t = s;
                while(*t && *t != ' ' && *t != '(' && *t != ')'){
                    ++t;
                }
                tokens.push_back(string(s, t));
                s = t;
            }
        }
        return tokens;
    }

}
