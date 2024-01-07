class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        //用來存儲處理後的有效路徑名稱。當遇到有效的目錄名或文件名時，將其加入堆疊中。堆疊頂部為目前處於的目錄或文件
        string curr; // 當最終簡化後的路徑字串
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                continue;
            }
            string temp_str;//暫時存目前處理的路徑段落的字串。當處理到斜槓前的有效字符時 將這些字符暫時保存於此
            while(i<path.size() && path[i]!='/'){
                temp_str = temp_str + path[i];
                i++;
            }
            if(temp_str=="."){ // 合法目錄
                continue;
            }
            else if(temp_str==".."){ // 若目前的字串是..則pop掉stack上層目錄
                if(!st.empty()){// 這條判斷式沒加會runtime error
                    st.pop();
                }
            }
            else{ // 不是上面兩種狀況的話就是正常路徑名稱 直接加入堆疊
                st.push(temp_str);
            }
        }
        while(!st.empty()){
            curr= "/" + st.top() + curr; // 將堆疊上面的陸續往字串前面加 再記得pop掉
            st.pop();
        }
        // 如果最後 curr 為空，表示沒有任何路徑信息，直接返回根目錄 /，否則返回簡化後的路徑curr
        if(curr.size()==0){
            return "/";
        }
        else{
            return curr;
        }
    }
};