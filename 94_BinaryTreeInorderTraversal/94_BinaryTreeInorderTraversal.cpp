/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        LDR(root, output);
        return output;

        
    }
    void LDR(TreeNode* root, vector<int>& output){ // output用ref 整隻程式都會改到該值 所以主程式最後return的output會是一直更新的output
        if(!root)return ; // root是null的話代表false 加個！變true才會進來
        LDR(root->left, output); 
        output.push_back(root->val);
        LDR(root->right, output);

    }
};
// 題意：中序LDR
// 遞迴 目標是檢查完最左邊到底 最左沒了就直接推值（代表中間）回去output
// 接下來再檢查右邊 有的話檢查他左邊
