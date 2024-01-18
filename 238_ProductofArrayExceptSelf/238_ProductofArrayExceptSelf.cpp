class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> output;
//         int nums_len = nums.size();
//         for (int i = 0; i<nums_len; i++){
//             int product = 1;
//             for(int j=0; j<nums_len; j++){
//                 if(i == j) continue;
//                 product = product * nums[j];
//             }
//             output.push_back(product);
       
//         }
//          return output;
            //前面方法超時

            int n = nums.size();
            vector<int> output(n);
            output[0] = 1; //先算自己左邊的乘積，第一個人左邊沒有 所以設1（之後也可跟右邊相乘）
            for(int i=1; i<n; i++){
                //從第二個元素開始 i=1
                output[i] = output[i-1]* nums[i-1]; //你左邊的所有乘積等於前面那個人左邊的乘積再乘上他自己
            }
            //算右邊的乘積 從最尾端倒回去
            int right = 1;
            for(int i=n-1; i>=0; i--){
                output[i] = output[i]* right;
                right = right * nums[i];
            }
            return output;

    }
  
};