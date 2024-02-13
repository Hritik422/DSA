class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int>mp;
        vector<string>ans;
        int n=list1.size(),m=list2.size(),i,mini=n+m+2;
        for(int i=0;i<n;i++)mp[list1[i]]=i+1;
        for(i=0;i<m;i++){
            int k=mp[list2[i]];
            if(k){
                mini=min(mini,i+k);
            }
        }
        for(i=0;i<m;i++){
            int k=mp[list2[i]];
            if(k && i+k==mini){
                ans.push_back(list2[i]);
            }
        }
        return ans;
        
        
    }
};