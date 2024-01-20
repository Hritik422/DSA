class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),x,i,ans=0,temp=0,mod=1e9+7;
        x=n-1;
        vector<int>v(n);
        v[0]=arr[0];
        temp+=v[0];
        ans+=arr[0];
        for(i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                int j=i-1,m=arr[i];
                while(j>=0 && arr[j]>m){
                    temp-=v[j];
                    temp+=m;
                    temp%=mod;
                    v[j]=m;
                    j--;
                }
                v[i]=arr[i];
                temp+=v[i];
                temp%=mod;
                ans+=temp;
                ans%=mod;
            }
            else{
                v[i]=arr[i];
                temp+=v[i];
                temp%=mod;
                ans+=temp;
                ans%=mod;
            }
        }
        return ans;
    }
};
   
