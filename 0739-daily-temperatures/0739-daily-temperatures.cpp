class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        int n=temp.size(),i,mini=temp[0];
        vector<int>ans(n,0);
        q.push({temp[0],0});
        for(i=1;i<n;i++){
            if(temp[i]<=mini){
                mini=temp[i];
                q.push({temp[i],i});
            }
            else{
                while(!q.empty()){
                    pair<int,int>p=q.top();
                    if(p.first<temp[i]){
                        ans[p.second]=i-p.second;
                        q.pop();
                    }
                    else{
                        break;
                    }
                }
                q.push({temp[i],i});
                mini=q.top().first;
            }
        }
        return ans;
    }
};