#include <regex>
#include "reader.hpp"

using std::string;
using std::vector;


namespace lisp{
    /******************* enum definitions ******************/
    enum class TokenType{
        // TODO:
    }

    /****************** class definitions ******************/
    class Reader{
        public:
            Reader(const vector<string> t);
            string next();
            string peek();
            ~Reader();
        private:
            vector<string> tokens;
            int position;
    };


    class Token{
        public:
            
    };


    /********************* Reader class *********************/
    Reader::Reader(const vector<string> t){ 
        this->tokens = t;
        this->position = 0;
    }


    Reader::~Reader(){
        this->tokens.clear();
    }


    /********************** Token class *********************/
    Token::Token(){
        
    }


    Token::~Token(){

    }


    /****************** function prototypes *****************/
    const vector<string> tokenize(const string &s);                 // convert string s to list of tokens
    const vector<string> split(const string &s, const string &r);   // split string s by regex r


    /********************* functions ************************/
    
    // TODO: desc
    string read_str(const string &s){
        auto tokens = tokenize(s);
        Reader *reader = new Reader(tokens);
        read_form(reader);
        return "";
    }


    // TODO: desc
    Token read_form(Reader *reader){
        auto t = reader->peek();
        switch(t){

        }
    }


    // split string into list of tokens
    const vector<string> tokenize(const string &s){
        auto regex = "[\\s,]*(~@|[\\[\\]{}()'`~^@]|\"(?:\\.|[^\\\"])*\"?|;.*|[^\\s\\[\\]{}('\"`,;)]*)";
        return split(s, regex);
    }


    // split string s by regex r
    const vector<string> split(const string &s, const string &r){
        std::regex re(r);
        std::sregex_token_iterator 
            first{s.begin(), s.end(), re, -1},
            last;
        return {first, last};
    }

}
