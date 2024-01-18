class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> discovered;
        for (int i = 0; i < nums.size(); i++) {
            int num_to_find = target - nums[i];
            if (discovered.find(num_to_find) == discovered.end()) {
                discovered[nums[i]] = i;
            } else {
                return vector<int>{discovered[num_to_find], i};
            }
        }
        return {};
    }
};