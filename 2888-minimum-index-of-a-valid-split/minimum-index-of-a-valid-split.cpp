class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i < n; i++){
            mp1[nums[i]]++;
        }
        int x = nums[0];
        for(int i = 0; i < n - 1; i++){
            mp2[nums[i]]++;
            if(mp2[nums[i]] > mp2[x]) x = nums[i];
            else if(mp2[nums[i]] == mp2[x]){
                if(mp1[nums[i]] > mp1[x]) x = nums[i];
            }
            if(mp2[x] > (i + 1)/2 && (mp1[x] - mp2[x]) > (n - i - 1)/2) return i;
        }
        return -1;
    }
};