#include <assert.h>
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
            string next();
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
    string Reader::next(){
        assert((this->position > (this->tokens.size()-1)) 
            && "Invalid token position, out of bounds.\n");
        return this->tokens.at(this->position++);
    }

    // Return token at current position without incrementing position
    string Reader::peek(){
        cout << "size = " << this->tokens.size() << endl;
        cout << "peeking at position " << this->position << endl;

        cout << "position > tokens.size() ? " << (this->position > (this->tokens.size())) << endl;

        //assert((this->position > (this->tokens.size())) 
        //    && "Invalid token position, out of bounds.\n");

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
    static vector<string> split(const string &s, const string &r);
    static void assert_parse(const char actual, const char expected);


    /********************* functions ************************/
    
    // TODO: desc
    LispType read_str(const string &s){
        auto tokens = tokenize(s);
        cout << "tokens read: " << tokens.size() << endl;
        for(auto i = 0; i < tokens.size(); i++){
            cout << i << ": " << tokens[i] << endl;
        }

        Reader reader(tokens);
        return read_form(reader);
    }


    // TODO: desc
    static LispType read_form(Reader &reader){
        cout << "read_form()" << endl;
        auto token = reader.peek();
        cout << "!!!";

        switch(token.at(0)){
            case '(':  return read_list(reader, LispList(), '(', ')');
            default:   return read_atom(reader);
        }
    }


    // TODO: desc
    static LispType read_list(Reader &reader, LispList list, const char start, const char end){
        auto token = reader.next();
        assert_parse(token.at(0), start);
        token = reader.peek();

        while(token.at(0) != end){
            assert((token.at(0) != EOF) 
                && "Unexpected end of file found while reading list.\n");
            list.push_back(read_form(reader));
            token = reader.peek();
        }
        reader.next();
        return list;
    }


    // TODO: desc
    static LispType read_atom(Reader &reader){
        regex intRegex("^[-+]?\\d+$");
        string token = reader.next();

        if(regex_match(token, intRegex)){
            return LispNumber(stoi(token));
        }
        return LispSymbol(token);
    }


    // Exit with error if character does not match expected
    static void assert_parse(const char actual, const char expected){
        if(actual != expected){
            cout << "Parse error: Expected '" << expected << "'.\n";
            exit(1);   
        }
    }


    // split string into list of tokens
    static vector<string> tokenize(const string &str){
        vector<string> tokens;
        const char * s = str.c_str();
        while(*s){
            while(*s == ' '){
                ++s;
            }
            if(*s == '(' || *s == ')'){
                tokens.push_back(*s++ == '(' ? "(" : ")");
            } else{
                const char * t = s;
                while(*t && *t != ' ' && *t != '(' && *t != ')'){
                    ++t;
                }
                tokens.push_back(string(s, t));
                s = t;
            }
        }
        return tokens;
    }


    // split string s by regex r
    vector<string> split(const string& input, const string& regex) {
        // passing -1 as the submatch index parameter performs splitting
        std::regex re(regex);
        std::sregex_token_iterator
            first{input.begin(), input.end(), re, -1},
            last;
        return {first, last};
    }

}
