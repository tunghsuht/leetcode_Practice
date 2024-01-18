class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if((long long)nums[i]+(long long)nums[i+1]+(long long)nums[i+2]+(long long)nums[i+3]>target) break;
            if((long long)nums[i]+(long long)nums[n-3]+(long long)nums[n-2]+(long long)nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if((long long)nums[i]+(long long)nums[j]+(long long)nums[j+1]+(long long)nums[j+2]>target) break;
                if((long long)nums[i]+(long long)nums[j]+(long long)nums[n-2]+(long long)nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    long long sum=((long long)nums[left]+(long long)nums[right]+(long long)nums[i]+(long long)nums[j]);
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};