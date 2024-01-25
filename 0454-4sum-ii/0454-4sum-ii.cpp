class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int i,j,ans=0,n=nums1.size(),n1=nums2.size();
        unordered_map<long long int,int>mp;
        for(auto it:nums4){
            for(auto it1:nums3){
                mp[it+it1]++;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n1;j++){
                    long long int y=nums1[i];
                    y+=nums2[j];
                    long long int remain=-1*y;
                    ans+=mp[remain];
            }
        }
        return ans;
        
    }
};