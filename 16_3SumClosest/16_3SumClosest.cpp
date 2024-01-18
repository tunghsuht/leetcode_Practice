class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //一樣可先排序 要找最接近目標的三個數 所以每個組合都要遍歷過  
        //ex: a b c d -> 檢查a與bcd、檢查b與cd、結束  所以要注意迴圈遍歷到size-2就好 
        //總和=自己+兩指針(自己的下一個 & 最後一個數)  相加太大則右指針左移 反之  
        // 檢查當前總和與當前差距 不斷更新
        sort(nums.begin(), nums.end());
        int preDiff = INT_MAX; // INT_MAX 表示 int 整數型別中最大可能的值
        int sum = 0;
        for(int i=0; i< nums.size()-2; i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int currSum = nums[i] + nums[left] + nums[right];
                int currDiff = abs(target - currSum);
                if(currDiff < preDiff){
                    sum = currSum;
                    preDiff = currDiff;
                }
                if(target > currSum){
                    left++;
                }
                else right--;
            }
        }
        return sum;
        
    }
};