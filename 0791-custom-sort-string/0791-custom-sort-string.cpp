class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        string ans;
        for(auto it:s)mp[it]++;
        for(auto it:order){
            int y=mp[it];
            for(int i=0;i<y;i++)ans+=it;
            mp[it]=0;
        }
        for(auto it:mp){
            int y=it.second;
            for(int i=0;i<y;i++)ans+=it.first;
        }
        return ans;
    }
};