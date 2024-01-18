class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> output;

        int i= 0;
        int j= n-1;
        sort(arr.begin(), arr.end());
        int m=arr[(n-1)/2];
        while(i<=j && output.size()<k){
            if(abs(arr[i]-m) < abs(arr[j]-m)){
                output.push_back(arr[j]);
                j--;
            }
            else if(abs(arr[i]-m) > abs(arr[j]-m)){
                output.push_back(arr[i]);
                i++;
            }
            else{
                output.push_back(max(arr[i], arr[j]));
                if(arr[i]>arr[j]){i++;}
                else{j--;}
            }
        }
        return output;
    }
};
// 題意: 排序後取中間數(n-1)/2，回傳:跟中間數差距最大的前K個數(差距需取決對值，若差距相同則取原值大者)
// 先排序 計算出中間值m ，因已排序，所以差距最大的一定在頭尾  所以i從頭開始 j從尾端開始比
// while迴圈條件: 最後進output的數一定是中位數 故ij最多就重疊而已 i不會大於j ; 且不用全比完因為只取前K個 
// arr[i]arr[j] 比完差距後，將strong者存入output，比贏的那端index移到下一個繼續往下比
