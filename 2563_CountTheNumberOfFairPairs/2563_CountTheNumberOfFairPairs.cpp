class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        auto beg = nums.begin(), end = nums.end();
        sort(beg, end);
        for(int i = 0; i < nums.size()-1; ++i){
            ans += upper_bound(beg + i+1, end, upper - nums[i]) - lower_bound(beg + i+1, end, lower - nums[i]);
                        //搜尋區間  從這   到這   找到第一個"大於"此的直             從這     到這   找第一個"大於等於"此的值    
        }
        return ans;
    }
};
// 用最一般的雙層for迴圈會LTE

// 已排序
// 假如i=0
// [0,1,4,4,5,7]
//    ^       ^   (找的區間)   
// 找到的第一個大於upper-nums[i]的值 與 第一個大於等於lower-nums[i]的值 一定等於nums[i]可以配對的組數            