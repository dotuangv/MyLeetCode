class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k-- == 1 || weights.size() == 2) return 0;
        vector<long long> Pair;
        for(int i = 0; i < weights.size() - 1; i++){
            Pair.push_back(weights[i] + weights[i + 1]);
        }
        sort(Pair.begin(), Pair.end());
        long long sum1 = 0, sum2 = 0;
        int i = 0, j = Pair.size() - 1;
        while(k--){
            sum1 += Pair[i++];
            sum2 += Pair[j--];
        }
        return sum2 - sum1;
    }
};