class Solution {
public:
    string removeStars(string s) {
        string s_new="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                s_new.push_back(s[i]);
            }
            else{
                s_new.pop_back();
            }
        }
        return s_new;
    }
};
// 題意：移除與星號最接近字元 （遇到星號就pop掉前一個
// 本來打算用stack但是會變先進後出 不符合輸出要求各式