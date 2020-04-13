#include "lisp.hpp"

namespace lisp{

    Repl::Repl(){
        this->parser = Parser();
        initEnv();
    }

    Env Repl::getEnv(){
        return this->env;
    }
    
    Exp Repl::read(const string &s){
        return this->parser.parse(s);
    }

    Exp Repl::eval(Exp exp, Env &env){
        if(exp.getType() != LList){
            return evalAst(exp, env);
        }
        if(exp.getChildrenSize() == 0){
            return exp;
        }

        Exp evaluated = evalAst(exp, env);
        EnvSymbol sym = env.get(exp.getChild(0).getValue());
        Procedure p = sym.getProcedure();
        Number result(std::to_string(p.invoke(evaluated.getChild(1).getValue(), evaluated.getChild(2).getValue())));

        return result;
    }

    string Repl::print(Exp exp){
        return exp.toString(0);
    }

    string Repl::rep(const string &s, Env &env){
        return print(eval(read(s), env));
    }

    Exp Repl::evalAst(Exp &exp, Env &env){
        if(exp.getType() == LSymbol){
            EnvSymbol envsym = env.get(exp.getValue());
            Symbol sym(envsym.getString());
            return sym;
        }
        if(exp.getType() == LList){
            List l;
            for(size_t i = 0; i < exp.getChildrenSize(); i++){
                l.add(eval(exp.getChild(i), env));
            }
            return l;
        }
        return exp;
    }

    void Repl::initEnv(){
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
    }

}
