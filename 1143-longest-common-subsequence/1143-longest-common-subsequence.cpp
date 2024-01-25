class Solution {
public:
int dp[1001][1001];
int res(string &s,string &s1,int i,int j){
    if(i<0 || j<0)return 0;
    if(dp[i][j]>=0)return dp[i][j];
    if(s[i]==s1[j]){return dp[i][j]=1+res(s,s1,i-1,j-1);}
    return dp[i][j]=max(res(s,s1,i-1,j) , res(s,s1,i,j-1));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size(),i,j;
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++)dp[i][j]=-1;
        }
        return res(text1,text2,n-1,m-1);
    }
};