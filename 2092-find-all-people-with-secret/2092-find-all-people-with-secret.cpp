class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    ios_base::sync_with_stdio(0);
    unordered_map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> map; 
    vector<int>ans;
    for(int i=0;i<meetings.size();i++){
        map[meetings[i][0]].push({meetings[i][2],meetings[i][1]});
        map[meetings[i][1]].push({meetings[i][2],meetings[i][0]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,firstPerson});
    q.push({0,0}); 
    vector<pair<bool,int>>visited(n);
    for(int i=0;i<n;i++){
        visited[i]={0,1e9};
    }
    while(!q.empty()){
       int front=q.top().second;
       int tm=q.top().first;
       q.pop();
       if(visited[front].first)
       continue;
       visited[front]={1,tm};
       auto &x=map[front];
       while(!x.empty()){
           int time=x.top().first;
           int person=x.top().second;
           x.pop();
           if(visited[person].first==0){
               if(time>=tm){
               q.push({time,person});
               }
           }
       }
    }
    for(int i=0;i<n;i++){ 
        if(visited[i].first==1)
        ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    return ans;
    }

};