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
    int ans=0;
    void find(TreeNode* root,int val){
        if(root==NULL){
            return;
        }
        val=val*10+root->val;
        if(!root->left && !root->right){
            ans+=val;
            return;
        }
        find(root->left,val);
        find(root->right,val);
        
        
    }
    int sumNumbers(TreeNode* root) {
        find(root,0);
        return ans;
    }
};