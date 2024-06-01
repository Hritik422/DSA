class Solution {
public:
    int scoreOfString(string s) {
        int i,n=s.size()-1,ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(s[i]-s[i+1]);
        }
        return ans;
    }
};