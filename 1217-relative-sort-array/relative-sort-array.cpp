class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> vt(1001);
        for(auto x: arr1) vt[x]++;
        vector<int> ans;
        for(auto x: arr2)
        {
            while(vt[x])
            {
                ans.push_back(x);
                vt[x]--;
            }
        }
        for(int i = 0; i <= 1000; i++)
        {
            while(vt[i])
            {
                ans.push_back(i);
                vt[i]--;
            }
        }
        return ans;
    }
};