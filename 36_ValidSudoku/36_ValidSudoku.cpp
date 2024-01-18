class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_check[9][9]={0};  //用三個額外的陣列 分別檢查第i列/第j行/第?個block 的0-8的位置有沒有出現過 預設為0(false)
        bool col_check[9][9]={0};
        bool block_check[9][9]={0};

        //用迴圈依序跑過每一個位置 看3個檢查陣列之中 此數字的對照位置(0-8) 有沒有出現過
            for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                int num = board[i][j] - '0' -1;  //每隔都是字符的編碼-字符0的編碼=真正數值 再往左平移1位 1-9對照到0-8的位置
                int block_num = (i/3)*3 + j/3; 
                if(board[i][j]=='.') continue;
                if(row_check[i][num]||col_check[j][num]||block_check[block_num][num]){
                    return false;
                }
                else{
                    row_check[i][num]=col_check[j][num]=block_check[block_num][num] = 1;
                }


            }
        }
        return true;
        
    }
};