class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int pop=0,stream=1,dif,d,n1=target.size(),i;
        vector<string>ans;
        for(i=0;i<n1;i++){
            dif=target[i]-stream;
            d = dif;
            while(dif){
                ans.push_back("Push");
                dif--;
            }
            while(d){
                ans.push_back("Pop");
                d--;
            }
            ans.push_back("Push");
            stream=target[i]+1;
        }
        return ans;
    }
};