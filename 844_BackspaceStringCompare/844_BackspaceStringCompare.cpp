class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
    
    string processString(string str) {
        string result;
        for (char c : str) {
            if (c != '#') {
                result.push_back(c);
            } else if (!result.empty()) {
                result.pop_back();
            }
        }
        return result;
    }
};
// 題意：＃代表倒退刪除鍵 操作完後檢查兩字串有無相等
// 先建立一個結果的string，在processString函式處理完字串後將結果傳回backspaceCompare比較

