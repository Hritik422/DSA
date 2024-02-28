class Solution {
public:
    bool isValid(string s) {
        if(s.size()%3!=0)return false;
        int k=s.size();
        for(int i=0;i<k-3;i++){
             if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
                 s.erase(i,3);
                 k-=3;
                 i=-1;
                 continue;
             }
        }
        return s=="abc";
    }
};