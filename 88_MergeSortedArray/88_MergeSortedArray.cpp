class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for(int i=m; i<m+n; i++){
            nums1[i]=nums2[j];
            j++;
        }
        sort(nums1.begin(), nums1.end());
        
    }
};
// 兩個陣列合併，照大小排序
// 把陣列2一個個排到陣列1後面 再sort即可
// i從m開始 代表陣列1的最後面位置 把陣列2第1個值asign給他