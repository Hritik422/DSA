class Solution {
public:
    int evalRPN(vector<string>& t) {
       stack<int>s;
        for(int i=0;i<t.size();i++){
            if(t[i]=="+" || t[i]=="*" || t[i]=="/" || t[i]=="-"){
              long long int first=s.top();
                s.pop();
              long long int second=s.top();
                s.pop();
                if(t[i]=="+")
                    first=first+second;
                else if(t[i]=="-")
                    first=second-first;
                else if(t[i]=="*")
                    first*=second;
                else
                    first=second/first;
                s.push(first);
            }
            else
                s.push(stoi(t[i]));
        }
        return s.top();
    }
};