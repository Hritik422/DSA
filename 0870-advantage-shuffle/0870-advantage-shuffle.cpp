class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        int n=nums2.size(),j=0;
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int res=upper_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            if(res>=n){
                for(j=0;j<n;j++){
                    if(mp[j]==0){
                        ans.push_back(nums1[j]);
                        mp[j]=1;
                        break;
                    }
                }
            }
            else{
                int check=0;
            for(j=res;j<n;j++){
                if(mp[j]==0){
                        ans.push_back(nums1[j]);
                        mp[j]=1;
                        check=1;
                        break;
                    }
            }
            if(check==0){
                for(j=0;j<res;j++){
                    if(mp[j]==0){
                        ans.push_back(nums1[j]);
                        mp[j]=1;
                        break;
                    }
                }
            }
            }
        }
        return ans;
    }
};