class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, i = 0;
        for(int j = 1; j < values.size(); j++){
            ans = max(ans, values[i] + values[j] + i - j);
            if(values[j] + j >= values[i] + i) i = j;
        }
        return ans;
    }
};