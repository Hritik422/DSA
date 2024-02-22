class Solution {
public:
    vector<vector<string>>ans;
    bool isValid(vector<string>v,int row,int col,int n){
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
    
   void solve (vector < string > &board, int n, int row)
   {
   if (row == n)
     {
      ans.push_back (board);
   return;
     }
   for (int col = 0; col < n; col++)
     {
      if (isValid (board, row, col,n))
     {
       board[row][col] = 'Q';
       solve (board, n,row+1);
       board[row][col] = '.';
     }
     }
 }
 vector < vector < string >> solveNQueens (int n)
 {
   vector < string > board (n, string (n, '.'));
   solve (board, n, 0);
     return ans;

 }

};