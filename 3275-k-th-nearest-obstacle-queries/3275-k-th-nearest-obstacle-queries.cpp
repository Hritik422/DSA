class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        multiset<int>s;
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int sum=abs(queries[i][0]) + abs(queries[i][1]);
            if(i<k-1){
                ans.push_back(-1);
                 s.insert(sum);
            }
            else if(s.size()==k-1){
                s.insert(sum);
                ans.push_back(*s.rbegin());
            }
            else{
                if(sum<*s.rbegin()){
                    s.erase(prev(s.end()));
                    s.insert(sum);
                }
                ans.push_back(*s.rbegin());
            }
        }
        return ans;
    }
};