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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<pair<TreeNode*,int>,int>>q;
        q.push({{root,0},0});
        map<int,vector<pair<int,int>>>mp;
        while(!q.empty()){
            auto root=q.front().first.first;
            int lvl=q.front().first.second;
            int h=q.front().second;
            mp[lvl].push_back({q.front().second,root->val});
            q.pop();
            if(root->left){
                q.push({{root->left,lvl-1},h+1});
            }
            if(root->right){
                q.push({{root->right,lvl+1},h+1});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>temp;
            sort(it.second.begin(),it.second.end());
            for(auto it1:it.second){
                temp.push_back(it1.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};