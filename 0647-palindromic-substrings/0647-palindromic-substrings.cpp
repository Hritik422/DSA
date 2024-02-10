class Solution {
public:
    int pal(string s,int i,int j,int n){
        int ans=0;
        while(i>=0 && j<n){
            if(s[j]!=s[i])return ans;
            i--;
            j++;
            ans++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int i,n=s.size(),ans=0;
        for(i=0;i<n;i++){
            ans+=pal(s,i,i,n);
            ans+=pal(s,i,i+1,n);
        }
        return ans;
        
    }
};