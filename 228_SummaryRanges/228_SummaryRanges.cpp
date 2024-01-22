class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        int start=0, end=0;
        while(end<nums.size()){
            while(end+1<nums.size() && nums[end+1]==nums[end]+1 ){
                end++;
            }
            if(start==end){
                output.push_back(to_string(nums[end]));
            }
            else{
                output.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            }
            end++;
            start=end;

        }
        return output;
    }
};
// 題意：最小的有序範圍列表
// 例如0 1 2在區間0-2內 故顯示為0->2
// while迴圈檢查end+1是否在數組範圍內 同時檢查nums[end+1]是否等於nums[end]+1
// 若想等則代表他們是連續的數 就將end加1 繼續檢查下個數是否為連續