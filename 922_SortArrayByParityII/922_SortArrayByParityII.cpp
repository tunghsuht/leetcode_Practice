class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        int even = 0, odd=1;
        while(even<n && odd<n){
            if(nums[even]%2 == 0){ //檢查偶索引是否為正確的值
                even=even+2;
            }
            else if(nums[odd]%2 == 1){  //檢查奇索引是否為正確的值
                odd=odd+2;
            }
            else{  // 只有在 nums[i] 且 nums[j] 皆不正確實時 才進行交換
                swap(nums[even],nums[odd]);  
            }
        }
        return nums;
    }
};
// 只有在 nums[i] 是奇數且 nums[j] 是偶數時才進行交換 所以一定要用if elseif else的搭配 不能兩個都是if




// 以下為看錯題目 單純奇偶穿插 不考慮索引
// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& nums) {
//         int n=nums.size();
//         if(n==2){return nums;}
//         for(int i=0; i<n-1; i++){
//             int j=i+1;
//             while((nums[i]+nums[j])%2==0){
//                 j++;
//             }
//             swap(nums[i+1], nums[j]);
//         }
//         return nums;
//     }
// };
// 題意: 一個陣列 一定含半奇半偶 輸出只要是奇偶穿插排列就可
// 思路: 唯獨奇偶相加會是奇數  相屬性相加一定為偶數
// i從頭開始 j為i+1  檢查當前的與下一個相加是否為偶數(同性質)  
// 相同屬性則j++到找到不同屬性為止 再與i+1的位置交換