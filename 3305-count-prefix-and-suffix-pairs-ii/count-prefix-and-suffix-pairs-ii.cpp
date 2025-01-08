class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ (hash2 << 1); 
        }
    };
    struct TrieNode {
        unordered_map<pair<char, char>, TrieNode*, pair_hash> children; 
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
            pair<char, char> key = {s[i], s[j]};
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
