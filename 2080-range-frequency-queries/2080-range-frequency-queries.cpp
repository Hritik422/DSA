class RangeFreqQuery {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    vector<int>temp;
    map<pair<pair<int,int>,int>,int>mp1;
    pair<int,int> binary(vector<pair<int,int>>v,int target,int low,int high){
         pair<int,int> ans={-1,-1};
        //if(v[high].first<target)return ans;
         while(low<=high){
             int mid=(low+high)/2;
             if(v[mid].first>=target){
                 ans={v[mid].first,v[mid].second};
                 high=mid-1;
             }
             else{
                 low=mid+1;
             }
         }
        return ans;
    }
    pair<int,int> binary_(vector<pair<int,int>>v,int target,int low,int high){
         pair<int,int> ans={-1,-1};
         //if(v[high].first<left)return ans;
         while(low<=high){
             int mid=(low+high)/2;
             if(v[mid].first<=target){
                 ans={v[mid].first,v[mid].second};
                 low=mid+1;
             }
             else{
                 high=mid-1;
             }
         }
        return ans;
    }
    RangeFreqQuery(vector<int>& arr) {
        int i,n=arr.size();
        temp=arr;
        for(i=0;i<n;i++){
            int y=mp[arr[i]].size();
            mp[arr[i]].push_back({i,y+1});
        }
    }
    
    int query(int left, int right, int value) {
        if(mp1[{{left,right},value}])return mp1[{{left,right},value}];
        int res=0,n=mp[value].size();
        --n;
        if((n>=0 && mp[value][n].first<left) || n<0)return 0;
       // cout<<v[0].first;
        pair<int,int> x=binary(mp[value],left,0,n);
        pair<int,int> y=binary_(mp[value],right,0,n);
        if(x.first==-1 || y.first==-1)return 0;
        if(temp[x.first]==value)res++;
        if(y.first<left)return 0;
        
        return mp1[{{left,right},value}]=y.second-x.second+res;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */