class Solution {
public:
    
    vector<int>v;
    Solution(vector<int>& w) {
       int n1=0;
        for(auto it:w){
            n1+=it;
            v.push_back(n1);
        }
    }
    
    int pickIndex() {
        int u= rand()%v.back();
        return upper_bound(v.begin(),v.end(),u)-v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */