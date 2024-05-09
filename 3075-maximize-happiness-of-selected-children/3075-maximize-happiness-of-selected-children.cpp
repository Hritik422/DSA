class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        partial_sort(happiness.begin(), happiness.begin()+k, happiness.end(), greater<int>());
        long long prev=0,ans=0;
        for(int i=0;i<k;i++){
            happiness[i]-=prev;
            ans+=max(happiness[i],0);
            prev++;
        }
        return ans;
    }
};