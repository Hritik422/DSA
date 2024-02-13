class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       map<int,int>mp;
        vector<int>ans;
        int i,n=intervals.size();
       for(i=0;i<n;i++)mp[intervals[i][0]]=i;
       for(i=0;i<n;i++){
           if(intervals[i][0]==intervals[i][1])ans.push_back(i);
           else{
               auto it=mp.lower_bound(intervals[i][1]);
               if(it==mp.end())ans.push_back(-1);
               else ans.push_back((*it).second);
           }
       }
        return ans;
    }
};