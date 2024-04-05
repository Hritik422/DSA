class Solution {
public:
    string makeGood(string s) {
        stack<char>p;
        string q;
        for(int i=0;i<s.size();i++){
            if(p.empty())
                p.push(s[i]);
            else if(int(p.top())==int(s[i])+32 || int(p.top())==int(s[i])-32){
                p.pop();
            }
            else
                p.push(s[i]);
        }
        while(!p.empty()){
            q+=p.top();
            p.pop();
        }
        reverse(q.begin(),q.end());
        return q;
    }
};