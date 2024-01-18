class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // set<vector<int>> set; 原本用set+output兩空間 跟 沒檢查重複數字 會太慢 （可看前幾次submit結果）

        //先昇序排序 
        //要找三個數字 先檢查第一個數以及他的兩指針(i+1 & size-1) 三數相加大於零則代表大的太大 移動尾端指針 反之亦然
        //此題貌似當前數字可能會有不同的其他兩數的組合  eg.-1 -1 0 1 2 檢查第一個-1時 可以有0,1與-1,2 所以可加上第23行
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(i!=0 && nums[i]==nums[i-1]) continue; // 如果當前數字與前一個數字相同，跳過當前數字

            int second = i+1;
            int end = nums.size()-1;
            while(second<end){
                int sum = nums[i]+nums[second]+nums[end];
                if(sum == 0){
                    output.push_back({nums[i],nums[second],nums[end]});
                    second++;
                    end--;
                    while(second<end && nums[second]==nums[second-1]) second++; // 跳過重複的數字
                    while(second<end && nums[end]==nums[end+1]) end--;
                }
                else if(sum > 0){
                    end--;
                }
                else{
                    second++;
                }
            }
        }
        return output;
    }
};
