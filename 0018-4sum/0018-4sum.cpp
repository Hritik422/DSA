class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int i,j,k,l,n=nums.size(),m;
        m=n-1;
        sort(nums.begin(),nums.end());
        for(auto it:nums)cout<<it<<" ";
        for(i=0;i<n-3;i++){
            for(j=i+1;j<n-2;j++){
                k=j+1;
                m=n-1;
               while(k<m){
                   long long int y=nums[i];
                   y+=nums[j];
                   y+=nums[k];
                   y+=nums[m];
                   if(y==target)      
                   {res.push_back({nums[i],nums[j],nums[k],nums[m]});k++;m--;}
                        else if(y<target)k++;
                        else m--;
                    }
                }
            }
        set<vector<int>>s;
        for(auto it:res)s.insert(it);
        res.clear();
        for(auto it:s)res.push_back(it);
        return res;
    }
};