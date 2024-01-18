class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end()); 
        int i=0,j=0;
        vector<int> output;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                if(output.size()>= 1 &&　nums1[i]==output[output.size()-1]){
                    i++;
                    j++;
                    continue;
                }
                output.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return output;
        
    }
};
// 題意:兩陣列取交集
// 先排序 
// 必三種狀況 nums1[i] 大於/等於/小於 nums2[j]
// 因為已經排序過 所以較小值那個位置再往後加1
// 非大於或小於的狀況就一定是等於了 直接把數字加到output
// 特別注意: output內的值不能重複 所以記得continue的那行要有