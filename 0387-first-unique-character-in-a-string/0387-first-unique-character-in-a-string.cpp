class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>arr;
        for(auto it:s)arr[it]++;
        for(int i=0;i<s.size();i++){
            if(arr[s[i]]==1)return i;
        }
        return -1;
    }
};