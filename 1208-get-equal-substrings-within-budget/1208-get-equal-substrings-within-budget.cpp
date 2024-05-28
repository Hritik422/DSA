class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,ans=0,temp=0,fin=0,j,n=s.size(),beg;
        j=n;
        for(i=0;i<n;i++){
            if(temp+abs(s[i]-t[i])<=maxCost){
                beg=i;
                while(i<n && temp+abs(s[i]-t[i])<=maxCost){
                    temp+=abs(s[i]-t[i]);
                    i++;
                    ans++;
                }
                j=i;break;
            }    
        }
        fin=ans;i=beg;
        //cout<<i<<" "<<j<<" "<<fin<<" "<<temp<<"  ";
        while(j<n){
            if(i>j){
                j=i;
                temp=0;
            }
            if(temp+abs(s[j]-t[j])>maxCost){
                temp-=abs(s[i]-t[i]);
                i++;
            }
            else{
                temp+=abs(s[j]-t[j]);
                fin=max(fin,j-i+1);
                j++;
            }
        }
        fin=max(fin,abs(j-i));
       
        return fin;
    }
};