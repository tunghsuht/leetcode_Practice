class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i,j,swap_index;
        
        for(i=n-2;i>=0;i--){  // 若int i在此處宣告的話 下面在這迴圈以外的i會抓不到值!!要注意
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        
        if(i<0){ 
            reverse(nums.begin(), nums.end());
        }
        else{
         // 找尋i右側 大於i的最小值
            for(j=i+1;j<n;j++){
                int larger_than_i_min = INT_MAX;
                if(nums[j]>nums[i] && nums[j]<larger_than_i_min){
                    larger_than_i_min = nums[j];
                    swap_index = j; // 這邊要注意 一值WA是因為我沒記到要交換的索引值j
                }
            }
            swap(nums[i], nums[swap_index]);
            reverse(nums.begin() + i + 1, nums.end());
        }     
    }
};
// 
// 此題為 排出陣列數字中 下一個較大的值 
// 從陣列倒數第二個值開始一個個往前看，若是第 i 個值比第 i+1 個值來得更小，則從 i 開始往右側找尋比『第 i 個值』大的值當中的『最小值』
// 交換第 i 個值以及比第 i 個值大的最小值
// 從原本 i 的位置往右，將全部的值從最小到最大排序
// 如此一來，我們就能得到『下一個較大的排列』