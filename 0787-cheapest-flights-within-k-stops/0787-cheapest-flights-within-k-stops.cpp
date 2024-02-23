class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans=INT_MAX;
        int i;
        vector<pair<int,int>>adj[n];
        for(i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<pair<int,int>,int>>q;
        q.push({{src,0},-1});
        vector<int>visited(n,1e9);
        visited[src]=0;
        while(!q.empty()){
            int curr=q.front().first.first;
            int dist=q.front().first.second;
            int cnt=q.front().second;
            q.pop();
            if(curr==dst && cnt<=k){
            ans=min(ans,dist);
            }
            for(auto it:adj[curr]){
                if(visited[it.first]>dist+it.second){
                q.push({{it.first,dist+it.second},cnt+1});
                visited[it.first]=dist+it.second;
               }
            }
        }
        if(ans!=INT_MAX)
        return ans;
        return -1;
    }
}; 