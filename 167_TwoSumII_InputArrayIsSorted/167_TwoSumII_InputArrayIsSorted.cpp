class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        //要抓住有排序的特點下手 兩指針分別指向頭跟尾（最大與最小數） 
        //若相加大於目標 代表尾數太大（大的太大）-> 尾數往前調一格;小於目標則表小的太小 小的要大一點 ->小的往後調
        int index1 = 0; 
        int index2 = numbers.size()-1;

        while(index1 < index2){
            if(numbers[index1]+ numbers[index2] == target){
                return {index1+1,index2+1};
            }
            if(numbers[index1]+ numbers[index2] < target){
                index1++;
            }
            else{index2 --;}
        }
        return {};
    }
};