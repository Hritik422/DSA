class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt=0,cnt1=0,n=s.size();
        vector<char>v={'A','E','I','O','U','a','e','i','o','u'};
        for(int i=0;i<n/2;i++){
            if(binary_search(v.begin(),v.end(),s[i]))cnt++;
            if(binary_search(v.begin(),v.end(),s[n-i-1]))cnt1++;
        }
        return cnt==cnt1;
    }
};