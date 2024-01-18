class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        int i =0;
        int j =0;
        while(i<firstList.size() && j<secondList.size()){
            int sp=0;  // 決定兩者的開始點 start point
            int ep=0;  // 決定兩者的結束點 end point
            sp = max(firstList[i][0], secondList[j][0]); // 起始點 選兩陣列首較大者
            ep = min(firstList[i][1], secondList[j][1]); // 結束點 選兩陣列尾較小者
            if(sp<=ep){
                ans.push_back({sp,ep});  // 若重疊之起始點<=結束點 代表正常區間 則加入ans中
             }
            if(firstList[i][1]<=secondList[j][1]){  
                // 表示 firstList[i] 的區間結束點小於等於 secondList[j] 的區間結束點，所以移動 i 指標以處理下一個 firstList 的區間。
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
// 題意: 兩陣列所有交疊處