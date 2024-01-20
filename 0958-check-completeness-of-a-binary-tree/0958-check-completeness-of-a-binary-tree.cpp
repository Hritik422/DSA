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
bool find(TreeNode* root){
    queue<pair<TreeNode*,int>>q;
    unordered_map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        TreeNode* cur=q.front().first;
        int lvl=q.front().second;
        q.pop();
        if(mp[lvl] && (cur->left || cur->right))return false;
        if(cur->right && !cur->left)return false;
        if(cur->left)q.push({cur->left,lvl+1});
        else {mp[lvl]=1;mp[lvl+1]=1;}
        if(cur->right)q.push({cur->right,lvl+1});
        else {mp[lvl]=1;mp[lvl+1]=1;}
    }
    return true;
}
    bool isCompleteTree(TreeNode* root) {
        return find(root);
    }
};