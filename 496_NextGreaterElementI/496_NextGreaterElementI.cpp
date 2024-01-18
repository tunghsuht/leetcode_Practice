class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> um;
        vector<int> ans;
        for(int ele:nums2){
            while(!st.empty() && ele > st.top()){ // 注意 此處要用while而非if 
                um[st.top()]=ele;
                st.pop();
            }
            st.push(ele);
        }
        for(int ele:nums1){
            ans.push_back(um.count(ele)? um[ele]:-1); // 這邊可換成if寫法 然後也可用um.find 換個寫法即可
        }
        return ans;
    }
};
// 題意: 在nums1裡的數 對照到nums2中 找右邊第一個較大的數 若無則用-1代替
// 第一個for迴圈:
// 利用類似key-value的方式 配合stack 在nums2中依序找出每個值對應的右側較大值
// 假如是[2,1,3] 
// 遍歷nums2，假如現在第一,二個元素已被加入堆疊 若遍歷到3 且它比堆疊頂端(1)還大 就記錄進unorderedmap <1,3>，把頂端pop掉
// 依然比堆疊頂端(2)還大，則又可以記錄進unmap<2,3> 

// 第二個for迴圈:
// unordered map.count(要尋找的值) 會回傳找到的個數(紀錄map中是否存在的用意) 有存在就回傳該值對應的數
