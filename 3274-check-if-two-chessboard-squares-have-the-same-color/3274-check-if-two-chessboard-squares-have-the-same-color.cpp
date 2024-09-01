class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        vector<vector<int>>v(8, vector<int>(8,0));
        int i,j;
        for(i=0;i<8;i+=2){
            for(j=0;j<8;j+=2){
             v[i][j]=1;       
            }
        }
        for(i=1;i<8;i+=2){
            for(j=1;j<8;j+=2){
             v[i][j]=1;       
            }
        }
        return v[coordinate1[0]-'a'][int(coordinate1[1]-'0')-1] == v[coordinate2[0]-'a'][int(coordinate2[1]-'0')-1];
    }
};