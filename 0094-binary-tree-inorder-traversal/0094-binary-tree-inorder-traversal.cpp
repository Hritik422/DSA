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
    vector<int> inorderTraversal(TreeNode* head) {
        if(head==NULL){
        return {};
    }
        stack<pair<TreeNode*,bool>>st;
        vector<int>ans;
    st.push({head,false});
    while(!st.empty()){
        auto root=st.top().first;
        bool flag=st.top().second;
        st.pop();
        if(flag){
            ans.push_back(root->val);
            continue;
        }
        if(root->right)
        st.push({root->right,false});
        st.push({root,true});
        if(root->left)
        st.push({root->left,false});
    }
        return ans;
    }
};