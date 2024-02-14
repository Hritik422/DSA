class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        int i,j=0,n=nums.size();
        for(auto it:nums){
            if(it<0)neg.push_back(it);
            else {pos.push_back(it);pos.push_back(0);}
        }
        for(i=1;i<n;i+=2){
            pos[i]=neg[j];
            j++;
        }
        return pos;
        
    }
};