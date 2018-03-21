

    // Special Thanks to: Jesse Brown.
	#include <iostream>
	#include <stack>
	#include <string>
	#include <cstdlib>
	#include <map>
	#include <algorithm>
	#include <stdexcept>
	#include <unordered_map>
	#include <vector>
	#include <cmath>
    class Calculator;
    // tokens for representing both operators (char) and operands (double).
    struct TokenM { 
        virtual void evaluate (Calculator *) = 0; 
        virtual ~TokenM() {}
    };
 
    template< class T > class Token : public TokenM {
        T oken;
    public:
        // calculator 
        void evaluate (Calculator  *c);
        Token (T t) : oken(t) {}
    };
      // Represents an expression in RPN.
    class RPNform {
        std::vector< TokenM* > pancakes;
		public:
        // Append a token to the end.
        void push (TokenM *t) { 
			pancakes.push_back (t); 
		}
        //get next token.
        TokenM* pop () {
            TokenM *tk = pancakes.front ();
            pancakes.erase (pancakes.begin ());
            return tk;
        }
        bool empty () const { 
			return pancakes.empty(); 
		}
    };
     //  Convert to infix then RPN.
     class ShuntingYard {
        const std::string expr_;
        RPNform rpn1;
        std::stack< char > opStk;
        mutable std::map< char, int > opPrec;
        // Returns precedence value for the operator 
        int precedence (char op) const { return opPrec[op]; }
        // Returns precedence of the top of the stack 
        int stack_precedence () const { 
            if (opStk.empty ()) { 
				return -1; 
			}
            return precedence (opStk.top ());
        }
        void handleLeftP () { opStk.push ('('); }
        //Process all operators in current () and restore
        void handleRightP () {
            while ('(' != opStk.top ()) {
                rpn1.push (new Token< char >(opStk.top ()));
                opStk.pop ();
            }
            opStk.pop ();
        }
        // Process operators with precedence >= than op then add op 
        void Opr (char op) {
            while (! opStk.empty () &&
                    precedence (op) <= stack_precedence ()) {
                rpn1.push (new Token< char >(opStk.top ()));
                opStk.pop ();
            }
            opStk.push(op);
        }
        // Convert infix to RPN via shunting-yard
        RPNform convert(const std::string &infix) {
            const char * token = infix.c_str ();
            while (token && *token) {
                while (*token && isspace (*token)){
					 ++token;
			    }
                if (! *token) { 
                    break; 
                }
                if (isdigit(*token)) {
                    char * next_token = 0;
                    rpn1.push (new Token< double >(strtod (token, &next_token)));
                    token = next_token;
                } else {
                    char op = *token;
                    switch (op) {
                        case '(':
                            handleLeftP();
                            break;
                        case ')':
                            handleRightP();
                            break;
                        default:
                            Opr(op);
                    }
                    ++token;
                }
            }
            while (! opStk.empty()) {
                rpn1.push (new Token< char >(opStk.top()));
                opStk.pop();
            }
            
            return rpn1;
        }
    public:
        ShuntingYard (const std::string& infix) : expr_(infix) {
            opPrec['('] = -1;
            opPrec['^'] = 4;
            opPrec['+'] = 2; 
            opPrec['-'] = 2;
            opPrec['*'] = 3; 
            opPrec['/'] = 3;
        }
        RPNform to_rpn () { return convert(expr_); }
    };
    //Converts variables to their mapped values, if set, otherwise outputs error.
    std::string vconvert(std::string in, std::unordered_map<std::string,double> purp)
    {
    	int begin, end;
		std::string var;
		//std::cout<<in<<"\n";
        //scans expression for first letter of variable
		for(int i = 0; i<in.length();i++){
		   if(isalpha(in[i])){
			    begin = i;
			    //std::cout<<"begin"<<begin<<"\n";
			   // std::cout<<"length"<<in.length()<<"\n";
               //assumes the variable will continue until either the end of the expression or an operator is encountered
			   for(int j = begin; j<in.length(); j++){
				   if(in[j]=='+' || in[j]=='-' ||in[j]=='*' || in[j]=='/' || in[j]=='^'|| j== in.length()-1){
					   end = j;
					   if(j== in.length()-1){
						   end = begin+(j-begin)+1;
					   } 
					  // assigns the variable to it's own string when it's end is encountered.
					   var.assign(in,begin, end-begin);
                       // replace with the corresponding mapped value if it exists.
					   if(purp.find(var)!= 	purp.end()){
						   if(purp[var]<0.00){
							   in.replace(begin, end-begin, "(0"+std::to_string(purp[var])+")");
						   }
						   else
							   in.replace(begin, end-begin, std::to_string(purp[var]));
					   }
					   else{
						   
						   return "error1"; 
					   }
                       //moves iterator passed inserted value.
					   //i=std::to_string(purp[var]).length()+begin;
					   break;
					   
				   }
			   }
		   }
		}
		//std::cout<<in<<"\n";
		return in;
	};
  class Calculator {
        std::stack< double > operands;
        double pop() { 
            double d = operands.top();
            operands.pop();
            return d; 
        }
        void push (double d) {operands.push(d); }
        // Returns the top of the operand stack, most recent answer
        double result () const { return operands.top(); }
        // Empty the operand stack 
        void empty() { 
            while (! operands.empty ()) { operands.pop(); }
        }
    protected:
        // Process an operand 
        void process(double value) { push (value); } 
        // Process an operator 
        void process(char op) { 
            switch (op) {
                case '+':
                    push (pop() + pop());
                    break;
                case '*':
                    push (pop() * pop());
                    break;
                case '-':
                    {
                        double right = pop();
                        
                        push (pop() - right);
                    }
                    break;
                case '/':
                    {
                        double right = pop();
					    push (pop() / right);
                    }
                    break;
                case '^':
                    {
                        double right = pop();
                        push (pow(pop(), right));
                    }
                    break;
                default:
                    throw std::domain_error("Unknown Operator");
            }
        } 
    public:
        double calculate (const std::string& expr) { 
            ShuntingYard shunting(expr);
            RPNform rpn = shunting.to_rpn();
            empty();
            while (! rpn.empty()) { 
                TokenM * token = rpn.pop();
                token->evaluate(this);
                delete token;
            }
              return result ();
        }
        template< class T > friend class Token;
    };
    template< class T > 
    void Token< T >::evaluate (Calculator * c) 
    { 
		c->process(oken);
    }
    //ugly main function.
  int main () {
		double answer;
		std::unordered_map<std::string,double> mapo;
        Calculator c;
        while(true)
        {
		std::string holder;
        std::string input;
        std::string equal;
        std::string variable1;
        std::cin>>input;
        if(input == "quit"){
			exit(0);
		}
        if(input=="let")
        {
			std::cin>>variable1;
			std::cin>>equal;
			
			getline(std::cin, input);
			input.erase(std::remove( input.begin(), input.end(), ' '), input.end() );
			input = vconvert(input,mapo);
			//std::cout<<input<<"\n";
			if(input!="error1"){
				answer =c.calculate (input);
				if(std::isinf(answer)){
					std::cout<<"Division-By-Zero"<<"\n";
				}	
				else {	
					mapo[variable1]=answer;
				}
		   }
		   else{
			   std::cout<<"Undeclared-Variable"<<"\n";
			   }
			//std::cout<< mapo["x"]<<"\n";
		}
		else if(input!="let")
		{
		getline(std::cin, holder);
		input.erase(std::remove( input.begin(), input.end(), ' '), input.end() );
		input += holder;
       
        
        input = vconvert(input,mapo);
       // std::cout<<input<<"\n";
       
        
        if(input!="error1"){
			
			answer = c.calculate (input);
			if(std::isinf(answer)){
			std::cout<<"Division-By-Zero"<<"\n";
		    }
		
			 else {
              std::cout << c.calculate (input) << std::endl;
	         }
		}
		else{
			std::cout<<"Undeclared-Variable"<<"\n";
		}
        
	   }
	}
}

