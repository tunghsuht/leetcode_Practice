class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> position;
        vector<int> output;
        
        if(s.size()==1){output.push_back(0);}

        for(int i=0; i<s.size(); i++){
            if(s[i] == c){
                position.push_back(i);
            }
        }
        for(int i=0; i<s.size(); i++){
            int curr_short = INT_MAX;  // 注意 此行放在迴圈外會wrong answer ! 放外面怕會保留到上一次函式調用的值
            for(int j=0; j<position.size();j++){
                curr_short = min(curr_short, abs(i-position[j]));
            }
            output.push_back(curr_short);            
        }
        return output;
    }
};
// 題意 : 找出字串中每個字元與目標字元之間的最短距離
// 搜尋目標字元在字串中的所有位置
// 遍歷整個字串，針對每個字元，計算它與目標字元之間的最短距離，並儲存到output陣列中。
// 返回output