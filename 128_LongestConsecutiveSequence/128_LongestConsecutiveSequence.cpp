class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         
        if(nums.size() == 0) return 0;

        sort(nums.begin(),nums.end()); //先照大小排序
        int current_consecutive_sequence = 1;  //目前連續長度 與 之前最長的  之後要相比
        int longest_consecutive_sequence = 1;
        for(int i=1; i<nums.size(); i++){  //i從第二個數字開始就好了 因為排序過了可以直接看跟前一個有無連續 ! (從0開始會RTE) !
            if(nums[i] != nums[i-1]){  //看有無跟前個數字重複
                if(nums[i] == nums[i-1]+1){
                    current_consecutive_sequence++;
                }
                else{ //跟前個數斷掉的話 就開始比 現在的長度 vs. 之前最長長度
                    longest_consecutive_sequence = max(current_consecutive_sequence, longest_consecutive_sequence);
                    current_consecutive_sequence = 1;  //數字斷掉的話代表又要再重新算 算完再重新比
                }
            }
        }
        return max(current_consecutive_sequence, longest_consecutive_sequence);
        //檢查到最後一個數字如果還有連續的話會停在 current_consecutive_sequence++;  所以不是return longest_consecutive_seq
    }
};