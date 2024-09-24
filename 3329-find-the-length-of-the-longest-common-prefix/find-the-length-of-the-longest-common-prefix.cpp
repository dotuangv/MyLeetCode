class Solution {
public:
    int trie[60000][10];
    int cnt = 0;
    void insert(string number) {
        int u = 0;
        for(int i = 0; i < number.size(); i++)
        {
            int k = number[i] - '0';
            if(!trie[u][k]) trie[u][k] = ++cnt;
            u = trie[u][k];
        }
    }

    int search(string number) {
        int u = 0;
        for(int i = 0; i < number.size(); i++)
        {
            int k = number[i] - '0';
            if(!trie[u][k]) return i;
            u = trie[u][k];
        }
        return number.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(int i = 0; i < arr1.size(); i++)
        {
            insert(to_string(arr1[i]));
        }
        int ans = 0;
        for(int i = 0; i < arr2.size(); i++)
        {
            ans = max(ans, search(to_string(arr2[i])));
        }
        return ans;
    }
};