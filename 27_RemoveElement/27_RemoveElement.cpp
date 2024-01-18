class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
        
    }
};
// 用兩變數，j從頭開始 當作安排位置; i遍歷所有位置的值，不是刪除目標的話則可填到j的位置