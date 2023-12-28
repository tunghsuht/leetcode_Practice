class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty() ? true: false;
        
    }
};
// 題意：pop順序是否合法
// 兩指標 i當pushed陣列 j當popped陣列
// 把pushed[i]堆入堆疊直到頂端與popped[j]相同 pop到與堆疊頂端不同為止
// 結束若堆疊為空則代表合法