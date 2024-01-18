class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        char stack_top;
        char n=s[s.size()-1];
        if(s.size()%2!=0){return false;}
        if(n=='('||n=='['||n=='['){return false;}
        if(s[0]==']'||s[0]=='}'||s[0]==')'){return false;}

        for(auto c:s){
            if(c!=')' && c!=']' && c!='}'){
                stack.push(c);
            }
            else if(stack.empty()){return false;}
            else if(c==')'){
                stack_top=stack.top();
                stack.pop();
                if(stack_top!='('){
                    return false;
                }
            }
            else if(c==']'){
                stack_top=stack.top();
                stack.pop();
                if(stack_top!='['){
                    return false;
                }
            }
            else{
                stack_top=stack.top();
                stack.pop();
                if(stack_top!='{'){
                    return false;
                }
            }
        }
        return (stack.empty()?true:false);
    }
};