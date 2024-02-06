class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans(strs.size());
        unordered_map<string,int>mp;
        int cnt=1;
        for(auto it:strs){
            string y=it;
            sort(y.begin(),y.end());
            if(mp[y]){
                ans[mp[y]-1].push_back(it);
            }
            else{
                mp[y]=cnt;
                cnt++;
                ans[mp[y]-1].push_back(it);
            }
        }
        ans.resize(cnt-1);
        return ans;
    }
};