class Solution {
public:
    bool pal(string s){
        int i,n=s.size();
        for(i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
            return 0;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        ios_base::sync_with_stdio(0);
        for(auto it:words){
            if(pal(it))
            return it;
        }
        return "";
    }
};