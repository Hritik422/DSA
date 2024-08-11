class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int pos=0;
        for(auto it:commands){
            if(it[0]=='D')pos+=n;
            else if(it[0]=='U')pos-=n;
            else if(it[0]=='R')pos++;
            else pos--;
        }
        return pos;
    }
};