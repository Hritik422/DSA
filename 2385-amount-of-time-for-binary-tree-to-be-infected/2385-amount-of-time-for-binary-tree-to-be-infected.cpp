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
    map<int,vector<int>>mp;
    void dfs(TreeNode* root){
        if(!root)return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        int ans=0;
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<bool>visited(100000);
        visited[start]=1;
        while(!q.empty()){
            int val=q.front().first;
            int cnt=q.front().second;
            ans=max(ans,cnt);
            q.pop();
            for(auto it:mp[val]){
                if(!visited[it]){q.push({it,cnt+1});visited[it]=1;}
            }
        }
        return ans;
    }
};