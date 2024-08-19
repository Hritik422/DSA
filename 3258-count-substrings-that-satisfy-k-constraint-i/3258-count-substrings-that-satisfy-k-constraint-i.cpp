class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int one=0, zero=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='0')zero++;
                else one++;
                if(zero<=k || one<=k)ans++;
                else break;
            }
        }
        return ans;
    }
};