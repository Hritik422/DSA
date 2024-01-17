class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp,mp1;
        for(auto it:arr)mp[it]++;
        for(auto it:mp){
            if(!mp1[it.second])mp1[it.second]=1;
            else return false;
        }
        return true;
    }
};