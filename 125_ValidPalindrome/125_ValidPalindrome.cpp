class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start<=end){
            if(!isalnum(s[start])){start++; continue;}
            //檢查字元是否合法（為大小寫英文或數字）在範圍內回傳非0 都不是回傳0
            if(!isalnum(s[end])) {end--; continue;}
            
            //if(s[start]!= s[end]) return false;  這樣會超時
            if(tolower(s[start])!= tolower(s[end])) return false;
            else{
                start++;
                end--;
            }
        }return true;
        
        
    }
};