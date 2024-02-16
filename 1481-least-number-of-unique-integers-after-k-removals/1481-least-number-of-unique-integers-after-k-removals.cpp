class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int ans=mp.size();
        vector<int>v;
        for(auto it:mp){
           v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            k-=v[i];
            if(k<0) return ans;
            ans--;
        }
        return 0;
    }
};