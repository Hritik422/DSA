class NumArray {
public:
long long int segment[100000];
long long int arr[100000];
int n;
void build(int ind,int low,int high){
     if(low==high){
        segment[ind]=arr[low];
        return;
     }
     int mid=(low+high)/2;
     build(2*ind+1,low,mid);
     build(2*ind+2,mid+1,high);
     segment[ind]=segment[2*ind+1]+segment[2*ind+2];
}
long long int query(int ind,int low,int high,int l,int r){
       if(low>=l && high<=r)
       return segment[ind];
       if(high<l || low>r) return 0;
       long long int mid=(low+high)/2;
       long long int left=query(2*ind+1,low,mid,l,r);
       long long int right=query(2*ind+2,mid+1,high,l,r);
       long long int res=left+right;
       return res;
}
    void update(int node, int start, int end, int index, int val) {
        if (start == end) {
            segment[node] = val;
            return;
        }
        int mid = (start+end)/2;
        if (index<=mid) update(2*node+1, start, mid, index, val);
        else update(2*node+2, mid+1, end, index, val);
        segment[node] = segment[2*node+1]+segment[2*node+2];
    }

    NumArray(vector<int>& nums) {
         n=nums.size();
         for(int i=0;i<n;i++)arr[i]=nums[i];
         build(0,0,n-1);
    }
    
    void update(int index, int val) {
        update(0,0,n-1,index,val);
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */