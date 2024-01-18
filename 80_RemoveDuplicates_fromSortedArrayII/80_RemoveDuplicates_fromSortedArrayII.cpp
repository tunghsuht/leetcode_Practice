class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3){return n;} // 若陣列小於3就直接回傳

        int j=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!= nums[j-2]){ // 這邊特別注意 是j-2 不是i-2 ，j才是代表當前要填入的位置
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
// 題意: 相同數字最多出現2次，禁止額外增加空間，要對原陣列做處理
// 設定j代表現在這位置要填誰，從2開始(第三個位置)(因為前兩個數一定符合題意)
// i也從第三個位置開始，能填入的值一定不會跟前兩格一樣