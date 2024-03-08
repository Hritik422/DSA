class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& arr, vector<vector<int>>& queries) {
        stack<pair<int,int>> s;
    s.push({arr[0],0});
        unordered_map<int,int>mp;
    for (int i = 1; i < arr.size(); i++) {
 
        if (s.empty()) {
            s.push({arr[i],i});
            continue;
        }
        while (s.empty() == false && s.top().first < arr[i]) {
            mp[s.top().second]=i;
            s.pop();
        }
        s.push({arr[i],i});
    }
    while(!s.empty()){
        mp[s.top().second]=-1;
        s.pop();
    }
        vector<int>ans;
        for(auto it:queries){
            int l=it[0],r=it[1];
            if(l>r)swap(l,r);
            if(l==r)ans.push_back(l);
            else if(mp[l]==-1)ans.push_back(-1);
            else if(arr[l]<arr[r]){
                ans.push_back(r);
            }
            else if(arr[l]==arr[r])ans.push_back(mp[r]);
            else{
                while(arr[r]<arr[l]){
                    r=mp[r];
                    if(r==-1)break;
                }
                ans.push_back(r);
            }
        }
        return ans;
    }
};