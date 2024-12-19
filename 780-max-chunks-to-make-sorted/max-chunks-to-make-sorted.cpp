class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int j = 0;
        int Min = arr[0], Max = arr[0];
        for(int i = 0; i < arr.size(); i++){
            Min = min(arr[i], Min);
            Max = max(arr[i], Max);
            if(Min == j && Max == i){
                ans++;
                j = i + 1;
                Min = 1e9;
                Max = -1;
            }
        }
        return ans;
    }
};