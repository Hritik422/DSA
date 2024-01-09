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
    void trav(TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        if(!root->left && !root->right)v.push_back(root->val);
        trav(root->left,v);
        trav(root->right,v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v,v1;
        trav(root1,v);
        trav(root2,v1);
        return v==v1;
    }
};