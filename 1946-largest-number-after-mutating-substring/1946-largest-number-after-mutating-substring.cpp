class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        map<char,char>mp;
        int j=0,n=num.size();
        for(char i='0';i<='9';i++){
            mp[i]= char(change[j]+'0');
            j++;
        }
        int i;
        for(i=0;i<num.size();i++){
            if(mp[num[i]]>num[i]){
                while(i<n && mp[num[i]]>=num[i]){
                    num[i]=mp[num[i]];
                    i++;
                }
                break;
            }
        }
        return num;
    }
};