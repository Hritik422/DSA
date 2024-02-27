class Solution {
public:
    int threeSumClosest(vector<int>& A, int X) {
        sort(A.begin(),A.end());
        int N = A.size();
        int min = INT_MAX , diff = INT_MAX;
        for(int i = 0 ; i < N-2 ; i++){
            int low = i+1 , high = N-1 ;
          
            while(low < high){
                int temp = X-(A[i]+A[low]+A[high]);
                if(diff > abs(temp)){
                    diff = abs(temp);
                    min = A[i]+A[low]+A[high];
                } 
              
                if((A[i]+A[low]+A[high]) == X)
                    return min;
                if((A[i]+A[low]+A[high]) > X)
                    high--;
                else if((A[i]+A[low]+A[high]) < X)
                    low++;
           }
        }
        
        return min;
    }
};