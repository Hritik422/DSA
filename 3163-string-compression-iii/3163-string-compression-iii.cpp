class Solution {
public:
    string compressedString(string word) {
        string ans;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            int temp=0;
            while(i<word.size() && word[i]==c){
                temp++;
                if(temp==9){
                    i++;
                    break;
                }
                i++;
            }
            --i;
            ans+=to_string(temp);
            ans+=c;
        }
        return ans;
    }
};