class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int k = needle.size();
        
        for(int i=0; i<=n-k; i++){  // 倒數k個長度的字還不相同的話就不用比了
            int j=0;
            for(; j<k; j++){  // j代表needle的索引 若相同則j就會加1 比對下一個字 不同就跳出迴圈 拿下一個i來比 j則重新索引
                if(haystack[i+j] == needle[j]){
                    continue;
                }
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j==k){
                return i;
            }
        }
        return -1;
        
    }
};