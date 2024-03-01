class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int on=0,z=0,i;
        string res;
        for(i=0;i<s.size();i++){
            if(s[i]=='0')z++;
            else on++;
        }
        while(on>1){
            res+='1';
            on--;
        }
        while(z>0){
            res+='0';
            z--;
        }
        res+='1';
        return res;
    }
};