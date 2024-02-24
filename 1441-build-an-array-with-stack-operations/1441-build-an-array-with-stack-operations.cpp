class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int pop=0,stream=1;;
        vector<string>ans;
        for(int i=0;i<target.size();i++){
            int push=0;
            while(stream!=target[i]){
                stream++;
                push++;
                ans.push_back("Push");
            }
            while(push!=0){
                ans.push_back("Pop");
                push--;
            }
            ans.push_back("Push");
            stream++;
        }
        return ans;
    }
};