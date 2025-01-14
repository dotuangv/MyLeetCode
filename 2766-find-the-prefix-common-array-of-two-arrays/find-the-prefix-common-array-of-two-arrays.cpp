class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size()), mp(A.size() + 1);
        for(int i = 0; i < A.size(); i++){
            mp[B[i]]++;
            for(int j = i; j >= 0; j--) ans[i] += mp[A[j]];
        }
        return ans;
    }
};