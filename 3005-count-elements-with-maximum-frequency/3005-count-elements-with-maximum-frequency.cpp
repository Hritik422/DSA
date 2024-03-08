class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int cur=0,ans=0;
        for(auto it:nums)mp[it]++;
        for(auto it:mp){
            if(it.second>cur){
                cur=it.second;
                ans=cur;
            }
            else if(it.second==cur){
                ans+=cur;
            }
        }
        return ans;
    }
};