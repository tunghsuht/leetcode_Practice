// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<int> s;
//         int ans;
//         int top,top2;
//         for(int i=0;i<tokens.size();i++){
//             if(tokens[i]!='+' && tokens[i]!='-' && tokens[i]!='*' && tokens[i]!='/'){
//                 s.push(stoi(tokens[i]));
//             }
//             else{
//                 top=s.top();
//                 s.pop();
//                 top2=s.top();
//                 s.pop();
//                 if(tokens[i]=='+') ans= top+top2;
//                 else if(tokens[i]=='-') ans= top-top2;
//                 else if(tokens[i]=='*') ans= top*top2;
//                 else ans= top/top2;
//                 s.push(ans);
                
//             }
//         }
//         return s.top();
//     }
// };
// 掃到數字就push進stack，掃到運算符號就將stack最上面的兩個數字做該運算，把結果push回stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans;
        int top, top2;
        for (const string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                s.push(stoi(token));
            } else {
                top = s.top();
                s.pop();
                top2 = s.top();
                s.pop();
                if (token == "+") ans = top2 + top;
                else if (token == "-") ans = top2 - top;
                else if (token == "*") ans = top2 * top;
                else {
                    // Check for division by zero
                    if (top == 0) {
                        // Handle division by zero error, return some default value
                        return INT_MAX;
                    }
                    ans = top2 / top;
                }
                s.push(ans);
            }
        }
        return s.top();
    }
};
