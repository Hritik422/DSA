class Solution {
public:

string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
        int i,j;
        for(i=0;i<s.size();i++)
        mp[s[i]]++;
        vector<pair<int,char>>v;
        for(auto it:mp){
            pair<int,char>p;
            p.first=it.second;
            p.second=it.first;
            v.push_back(p);
        }
        sort(v.begin(), v.end(), greater<pair<int,char>>());
        for(i=0;i<v.size();i++){
            for(j=0;j<v[i].first;j++)
                ans+=v[i].second;
        }
        return ans;
    }
};