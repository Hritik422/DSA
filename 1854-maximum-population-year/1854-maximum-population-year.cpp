class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);
        for(auto& v : logs){
            ++diff[v[0] - 1950];
            --diff[v[1] - 1950];
        }
        for(int i = 1; i < 101; i++)
            diff[i] += diff[i - 1];
        return max_element(begin(diff), end(diff)) - begin(diff) + 1950;
    }
};