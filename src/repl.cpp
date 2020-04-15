#include "lisp.hpp"

namespace lisp{

    Repl::Repl(){
        this->parser = Parser();
        this->env.init(nullptr);
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
        } else if(exp.getChildrenSize() == 0){
            return exp;
        }

        if(exp.getChild(0).getValue() == "def!"){
            string identifier = exp.getChild(1).getValue();
            Exp def = eval(exp.getChild(2), env);
            EnvSymbol sym(identifier, def.getValue());
            env.set(identifier, sym);
            return def;
        }
        else if(exp.getChild(0).getValue() == "let*"){
            vector<Exp> children = exp.getChild(1).getChildren();
            Env letEnv;
            letEnv.init(&env);
            for(size_t i = 0; i < children.size(); i+=2){
                string identifier = children[i].getValue();
                Exp val = eval(exp.getChild(1).getChildren()[i+1], letEnv);

                EnvSymbol sym(identifier, val.getValue());
                letEnv.set(identifier, sym);
            }
            return eval(exp.getChild(2), letEnv);
        }

        Exp evaluated = evalAst(exp, env);
        EnvSymbol sym = env.get(exp.getChild(0).getValue());
        Procedure p = sym.getProcedure();
        Number result(std::to_string(
            p.invoke(evaluated.getChild(1).getValue(), evaluated.getChild(2).getValue())));

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

        env.set("+", symAdd);
        env.set("-", symSub);
        env.set("*", symMul);
        env.set("/", symDiv);
    }

}
