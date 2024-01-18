class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        for(;j<nums.size();j++){
            nums[j]=0;
        }
        
    }
};
// 題意:把陣列中的0全部移到最後面(非零都移到前面)
// j從0開始代表現在此位置要放誰 i從0開始檢查數字，若非零則可放到前面
// 最後將後面補0

// 用swap好像會runtimeError