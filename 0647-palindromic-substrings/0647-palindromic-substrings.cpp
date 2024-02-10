class Solution {
public:
    bool pal(string s,int i,int j){
        if(j<i)return 0;
        while(j>i){
            if(s[j]!=s[i])return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        map<char,set<int>>mp;
        int i,n=s.size(),ans=0;
        for(i=0;i<n;i++)mp[s[i]].insert(i);
        for(auto it:mp){
            for(auto inx:it.second){
                auto inx2=inx;
                for(auto inx2:it.second){
                    if(pal(s,inx,inx2))ans++;
                }
            }
        }
        return ans;
        
    }
};