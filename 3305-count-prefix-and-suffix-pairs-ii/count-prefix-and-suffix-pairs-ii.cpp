class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children; 
        int cnt = 0;
    };

    TrieNode* root;

    Solution() {
        root = new TrieNode();
    }

    int Insert(string& s) {
        TrieNode* node = root;
        int res = 0, i = 0, j = s.size() - 1;

        while (i < s.size()) {
            string key = "";
            key.push_back(s[i]);
            key.push_back(s[j]);
            if (node->children.find(key) == node->children.end()) {
                node->children[key] = new TrieNode();
            }
            node = node->children[key];
            res += node->cnt;
            i++;
            j--;
        }
        node->cnt++;
        return res;
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        for (auto& word : words) {
            ans += Insert(word);
        }
        return ans;
    }
};
