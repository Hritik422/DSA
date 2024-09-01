class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k=original.size();
        if(m*n != k)return {};
        int i,j;
        vector<vector<int>>ans;
        for(i=0;i<m*n;i+=n){
            vector<int>temp;
            for(j=i;j<n+i;j++){
                temp.push_back(original[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};