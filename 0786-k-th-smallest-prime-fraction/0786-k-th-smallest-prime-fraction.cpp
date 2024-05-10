class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        priority_queue<pair<double,pair<int,int>>>q;
        int i,j,n=a.size(),cnt=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                double ans=double(a[i])/double(a[j]);
                q.push({ans,{a[i],a[j]}});
                cnt++;
            }
        }
        k=cnt-k;
        while(k>0){
            q.pop();
            k--;
        }
        int am=q.top().second.first;
        int b=q.top().second.second;
        return {am,b};
    }
};