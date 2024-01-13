class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp,mp1;
        int remain=0,over=0;
        for(auto it:s)mp[it]++;
        for(auto it:t)mp1[it]++;
        for(auto it:mp1){
            int x=mp[it.first];
            if(x<it.second){
                remain+=it.second-x;
            }
        }
        return remain;
        
    }
};