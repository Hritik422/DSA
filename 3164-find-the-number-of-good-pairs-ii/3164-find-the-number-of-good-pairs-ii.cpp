class Solution {
public:
int printDivisors(long long n,map<long long,int>&mp) 
{ 
    int ans=0;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        {  
            if (n/i == i) {
                ans+=mp[i];
            }
            else{
                ans+=mp[i];
                ans+=mp[n/i];
            } 
        } 
    } 
    return ans;
} 
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<long long int,int>mp;
        long long int i,sum=0;
        for(auto it:nums2)mp[it]++;
        for(i=0;i<nums1.size();i++){
            if(nums1[i]%k!=0)continue;
            nums1[i]/=k;
            sum+=printDivisors(nums1[i],mp);
        }
        return sum;
    }
};