class Solution {
public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int ans = 0;
    int l = -1;
    int r = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= left) r = i;
      if (nums[i] > right) l = i;      
      ans += (r - l);
    }
    return ans;
  }
};
// 題意: 找出所有合法的"連續子陣列" 。  合法的條件:子陣列中的最大值需在left與right間
// 解法偏tricky 弔詭  個人想不太到