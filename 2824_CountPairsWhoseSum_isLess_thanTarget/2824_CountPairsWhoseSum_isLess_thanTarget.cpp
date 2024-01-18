class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result_count = 0;
        for(int i=0; i<=nums.size()-2; i++){
            // if(i>0 && nums[i]==nums[i-1]) continue;
            for(int p=i+1; p<nums.size();p++){
                if(nums[i]+nums[p]>=target) break;
                // if(p>i+1 && nums[p]==nums[p-1]) continue;
                if(nums[i]+nums[p]<target){
                    result_count++;
                }
                
            }
            
        }
        return result_count;
    }
};

