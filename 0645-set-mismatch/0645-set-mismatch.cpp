class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto it:nums)mp[it]++;
        for(int i=1;i<=nums.size();i++){
            if(mp[i]==0)res.push_back(i);
            else if(mp[i]==2)res.push_back(i);
        }
        if(mp[res[0]]==0)swap(res[0],res[1]);
        return res;
    }
};