class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> relation(n+1);
        map<int,int>mp;
        bool check=false;
        int i,ans=0,fin;
        for(i=0;i<trust.size();i++){
            relation[trust[i][0]]=1;
            mp[trust[i][1]]++;
        }
        for(i=1;i<n+1;i++){
       if(relation[i]==0){
           ans++;
           fin=i;
        }
        }
        if(ans==1 && mp[fin]==n-1)
        return fin;
        else
        return -1;
    }
};