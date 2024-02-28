class Solution {
public:
    bool isPalindrome(string s){
        int n = s.length();
        for(int i=0;i<n/2;++i){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    } 

    vector<vector<int>> palindromePairs(vector<string>& a) {
        int n = a.size();
        unordered_map<string,int> present;
        for(int i=0;i<n;++i){
            present[a[i]] = i;
        }
        set<pair<int,int>> validPair;
        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            if(present.find("")!=present.end()&&i!=present[""]&&isPalindrome(a[i])){
                validPair.insert({i, present[""]});
                validPair.insert({present[""],i});
            }
            string prefix = "";
            string suffix = a[i];
            int m = a[i].length();
            for(int j=0;j<m;++j){
                prefix.insert(prefix.begin(),a[i][j]);
                suffix.erase(suffix.begin());
                if(present.find(prefix)!=present.end()&&i!=present[prefix]&&isPalindrome(suffix)){
                    validPair.insert({i, present[prefix]});
                }
            }
            suffix = "";
            prefix = a[i];
            for(int j=m-1;j>=0;--j){
                suffix+=a[i][j];
                prefix.pop_back();
                if(present.find(suffix)!=present.end()&&i!=present[suffix]&&isPalindrome(prefix)){
                    validPair.insert({present[suffix],i});
                }
            }
        }
        for(pair<int,int> p: validPair){
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};