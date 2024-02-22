class Solution {
public:
    int ans=0;
    bool poss(vector<string>v,int row,int col,int n){
        for(int k=row-1;k>=0;k--){
            if(v[k][col]=='Q')return 0;
        }
        int l=col;
        for(int k=row;k>=0 && l>=0;k--,l--){
            if(v[k][l]=='Q')return 0;
        }
        l=col;
        for(int k=row;k>=0 && l<n;k--,l++){
            if(v[k][l]=='Q')return 0;
        }
        return 1;
        
    }
    void solve(vector<string>&v,int row,int n){
        if(row==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(poss(v,row,i,n)){
                v[row][i]='Q';
                solve(v,row+1,n);
                v[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>v(n, string (n, '.'));
        solve(v,0,n);
        return ans;
    }
};