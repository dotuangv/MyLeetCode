class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7, ans = 0, odd = 0, even = 0, teven, todd;
        for(int i = 1; i <= arr.size(); i++){
            if(arr[i - 1]%2){
                teven = odd;
                todd = even + 1;
            }else{
                teven = even + 1;
                todd = odd;
            }
            odd = todd;
            even = teven;
            ans = (ans + odd)%mod;
        }
        return ans;
    }
};