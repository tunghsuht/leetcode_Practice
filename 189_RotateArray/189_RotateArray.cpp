class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){return;}  //記得考慮這些狀況!!沒考慮到會runtimeError(存在一些不合法的存取之類的 存取的數超過合法的限制)
        if(k>=n){
            k=k%n;
        }
        int j = n-k; // j為新陣列第一個值的原始陣列位置
        vector<int> output(n);
        for(int i=0; i<n; i++){
            if(i<j){
                output[i+k]=nums[i];
            }
            else{
                output[i-j]=nums[i];
            }
        }
        nums=output;
    }
};
// index: 0 1 2 3 4 5 6
// nums:  1 2 3 4 5 6 7
// output:5 6 7 1 2 3 4
// 新index:i-j | i+k