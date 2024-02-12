class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,int>>v;
        vector<vector<int>>ans;
        int i,n=people.size(),maxi=-1;
        for(i=0;i<n;i++){
            v.push_back({people[i][0],people[i][1]});
            maxi=max(maxi,people[i][0]);
        }
        sort(v.begin(),v.end(),[](pair<int,int> p1, pair<int,int> p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        for(i=0;i<n;i++){
            if(v[i].first==maxi){
                ans.push_back({v[i].first,v[i].second});
            }
            else{
                ans.insert(ans.begin()+v[i].second,{v[i].first,v[i].second});
            }
        }
        return ans;
    }
};
