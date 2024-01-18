class Solution {
public:
    vector<int> sortArrayByParity(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left<right){
            while(left<right && nums[left] %2 == 0)
            {
                left++;
            }
            while(left<right && nums[right] %2 ==1){
                right--;
            }
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};

// 原方法：（上面的把原來的更簡化）
// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         int left=0;
//         int right=nums.size()-1;
//         while(left<right){
//             if((nums[left] % 2 == 0) && (nums[right]%2==0)){ //雙偶
//                 left++;
//             }
//             else if((nums[left]%2!=0)&&(nums[right]%2==0)){ //左奇 右偶 換
//                 swap(nums[left], nums[right]);
//                 left++;
//                 right--;
//             }
//             else if((nums[left] % 2 != 0) && (nums[right]%2!=0)){ // 雙奇數 
//                 right--;
//             }
//             else{ // 左偶 右奇
//                 left++;
//                 right--;
//             }
//         }
//         return nums;
//     }   
// };