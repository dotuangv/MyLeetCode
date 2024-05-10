class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> pa;
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = i + 1; j < arr.size(); j++)
            {
                pa.push_back({arr[i]*1.0/arr[j], {arr[i], arr[j]}});
            }
        }
        sort(pa.begin(), pa.end());
        return {pa[k - 1].second.first, pa[k - 1].second.second};
    }
};