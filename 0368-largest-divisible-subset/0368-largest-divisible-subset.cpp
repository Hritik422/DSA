class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=1,n=nums.size(),super=1;
        if(n==1)return {nums[0]};
        vector<int>v(n,-1);
        v[n-1]=n-1;
        map<int,int>mp;
        mp[nums[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            int base=nums[i],ans=1,index=i,maxi=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]%base==0 && mp[nums[j]]>maxi){
                    maxi=mp[nums[j]];
                    index=j;
                }
            }
            mp[base]=1+maxi;
            v[i]=index;
            super=max(super,1+maxi);
        }
        int base;
        vector<int>res;
        if(super==1)return {nums[0]};
        for(auto it:mp){
            if(it.second==super){
                base=it.first;
                break;
            }
        }
        int i;
        for(i=0;i<n;i++){
            if(nums[i]==base){
                res.push_back(nums[i]);
                break;
            }
        }
        int cur=v[i];
        while(1){
            res.push_back(nums[cur]);
            cur=v[cur];
            if(cur==v[cur]){
                res.push_back(nums[cur]);
                break;
            }   
        }
        i=res.size();
        if(i>1 && res[i-1]==res[i-2]){
            res.pop_back();
        }
        return res;
    }
};