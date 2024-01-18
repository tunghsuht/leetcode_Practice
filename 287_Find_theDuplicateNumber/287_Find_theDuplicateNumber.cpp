class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n - 1;

        while(low < high){
            int mid = low + (high - low) / 2;
            int cnt = 0;

            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    cnt++;
                }
            }
            if(cnt <= mid){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
// 他人的方法
// nums = [1, 3, 4, 2, 2]。
// 1. low high為數字的範圍。（陣列長度為 5，數字範圍在1到4之間 所以low初始化為 1，high 初始化為 4。
// 2. 進入迴圈，首先計算 mid。初始情況下，mid 是 (1 + 4) / 2 = 2。
// 3. 統計陣列中小於等於 mid 的數字個數。在這例子中，小於等於 2 的數字有 3 個，所以 cnt 等於 3。
// 4. 接著比較 cnt 和 mid 的大小。cnt 大於 mid，代表重複數字在小於等於 2 的範圍內。
//    因此將 high 更新為 mid，即 high = 2。
// 5. 重新計算 mid。現在 mid 是 (1 + 2) / 2 = 1。
// 6. 統計陣列中小於等於 mid 的數字個數。在這例子，小於等於 1 的數字有 1 個，所以 cnt 等於 1。
// 7. 比較 cnt 和 mid 的大小，cnt 小於等於 mid，這意味著重複的數字可能在大於 1 的範圍內。
//     因此將 low 更新為 mid + 1，即 low = 2。
// 8. 最後一輪迴圈，low 等於 high，迴圈結束。
// 此時的 low 即為結果，表示找到了重複的數字，所以返回 low，即 2。