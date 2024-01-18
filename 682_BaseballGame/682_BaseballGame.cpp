class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i = 0; i < operations.size();i++){
            if(s.empty()) s.push(stoi(operations[i])); // 因為數字不是string所以要用stoi()轉換
            else{
                if(operations[i] == "+"){
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.push(x);
                    s.push(x+y);
                }
                else if(operations[i] == "C"){
                    s.pop();
                }
                else if(operations[i] == "D"){
                    s.push(2*s.top());
                }
                else{
                    s.push(stoi(operations[i]));
                }
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};