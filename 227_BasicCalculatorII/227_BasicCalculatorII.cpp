class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        s=s+'+'; // 多加一個符號 確保迴圈結束後最後一個數字也能被處理到
        long long int ans=0, curr=0;
        char pre_sign = '+'; // 先初始一個先前符號 以便後續程式執行

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                curr = curr*10 + (s[i]-'0'); // 因為輸入是字符 所以數字記得要用這種方式處理
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                if(pre_sign =='+'){
                    st.push(curr);
                }
                else if(pre_sign =='-'){
                    st.push(curr*(-1));
                }
                else if(pre_sign =='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*curr);
                }
                else{
                    int top=st.top();
                    st.pop();
                    st.push(top/curr);
                }
                curr=0; // 記得更新這兩者
                pre_sign=s[i];
            }
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
// 題意：做運算 須符合運算優先權
// 思路重點：
// 1. 只要是做運算，一定是看"當前數字以前的運算子"為何 再作運算。
// 例如 3*2+4 若要算3*2 則要掃到2的下一個非數符號(表示可以做運算了 看當前數字以前的運算子是* 所以作3*2)
// 2. 只有* / 需要先做，做完後說白了 四則運算就只剩全部相加（減法就是加上負數）。

// 依照上面思路，就可用 堆疊（存放處理好的數字 最後全部相加）, pre_sign(先前運算符號), curr（當前數字）來完成合作：
// 1. 若先前運算符號是+ 將當前curr數字正常放進堆疊; 若是- 則將curr乘上 -1 再放入堆疊。
// 2. 若遇到* / 就將當前curr數字跟堆疊頂端數字作運算 再將結果放入堆疊

