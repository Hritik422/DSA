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
    long int cur=-1e18,ans=1;
    void is(TreeNode* root) {
        if(root==NULL)
            return;
       is(root->left);
       if(root->val<=cur)ans=0;
        else cur=root->val;
        is(root->right);
    }
        bool isValidBST(TreeNode* root) {
            is(root);
            return ans;
        }
};