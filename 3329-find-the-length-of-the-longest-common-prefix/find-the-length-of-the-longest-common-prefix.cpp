class Solution {
public:
    int trie[60000][10];
    int cnt = 0;
    void insert(vector<int> &number) {
        int u = 0;
        for(int i = number.size() - 1; i >= 0; i--)
        {
            int k = number[i];
            if(!trie[u][k]) trie[u][k] = ++cnt;
            u = trie[u][k];
        }
    }

    int search(vector<int> &number) {
        int u = 0;
        for(int i = number.size() - 1; i >= 0; i--)
        {
            int k = number[i];
            if(!trie[u][k]) return number.size() - i - 1;
            u = trie[u][k];
        }
        return number.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(int i = 0; i < arr1.size(); i++)
        {
            vector<int> number;
            while(arr1[i])
            {
                number.push_back(arr1[i] % 10);
                arr1[i] /= 10;
            }
            insert(number);
        }
        int ans = 0;
        for(int i = 0; i < arr2.size(); i++)
        {
            vector<int> number;
            while(arr2[i])
            {
                number.push_back(arr2[i] % 10);
                arr2[i] /= 10;
            }
            ans = max(ans, search(number));
        }
        return ans;
    }
};