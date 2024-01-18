// sol 2: time: O(n) 別人的方法 挺聰明：）
// 因為數字只有012 0全部排到最前面 2全部排到最尾端 1就一定會在中間了就排好了
// 初始化 low mid 指向陣列的起始位置，high 指向陣列的結尾位置
// 在迴圈中，只要 mid 指向的元素小於等於 high，就持續執行
// 若 nums[mid] 為 0，則將其與 nums[low] 進行交換，然後將 low 和 mid 同時右移一位 繼續往後檢查，表示在開頭放置了一個 0
// 若 nums[mid] 為 1，表示它已經處於正確位置，因此只需要將 mid 右移一位;（low就會在他前面）
// 若 nums[mid] 為 2，則將其與 nums[high] 進行交換，然後將 high 左移一位，表示將 2 放在了陣列的末尾
// 這樣，遍歷完成後，所有的 0 都位於開頭，所有的 2 都位於末尾，所有的 1 都位於中間，即達到了排序的目的
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int low=0;
       int mid=0;
       int high=nums.size()-1;
       while(mid<=high){
           if(nums[mid]==0){
               swap(nums[low], nums[mid]);
               low++;
               mid++;
           }
           else if(nums[mid]==1){
               mid++;
           }
           else if(nums[mid]==2){
               swap(nums[high], nums[mid]);
               high--;
           }
       };
    };
};
// sol 1: time: O(n^2)
// 題意：不能用sort函數完成昇序排序
// 外層迴圈來代表現在這個位置要排誰（目標是 我以右的 小於我的最小值）
// 內層迴圈來負責找出小於等於我的最小值 不斷用兩變數來記錄與比較當前最小值 並記錄當前最小值位置
// 最後將找到的值與當前位置交換
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int curr_min, curr_min_index;
//         for(int i=0; i<n; i++){
//             curr_min = nums[i];
//             curr_min_index = i;
//             for(int j=i+1;j<n;j++){
//                 if(nums[j] <= curr_min ){
//                     curr_min = nums[j];
//                     curr_min_index = j;
//                 }
//             }
//             swap(nums[i], nums[curr_min_index]);
//         }
        
//     }
// };


