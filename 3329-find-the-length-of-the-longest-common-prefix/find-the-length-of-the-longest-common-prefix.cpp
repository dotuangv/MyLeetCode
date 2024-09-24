class TrieNode {
public:
    TrieNode* children[10];
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode();
    }

    void insert(vector<int> &number) {
        TrieNode* node = root;
        for (int i = number.size() - 1; i >= 0; i--) {
            int k = number[i];
            if (!node->children[k]) {
                node->children[k] = new TrieNode();
            }
            node = node->children[k];
        }
    }

    int search(vector<int> &number) {
        TrieNode* node = root;
        for (int i = number.size() - 1; i >= 0; i--) {
            int k = number[i];
            if (!node->children[k]) {
                return number.size() - i - 1;
            }
            node = node->children[k];
        }
        return number.size();
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        // Insert arr1 into the trie
        for (int i = 0; i < arr1.size(); i++) {
            vector<int> number;
            while (arr1[i]) {
                number.push_back(arr1[i] % 10);
                arr1[i] /= 10;
            }
            insert(number);
        }

        // Search arr2 and find the longest common prefix
        int ans = 0;
        for (int i = 0; i < arr2.size(); i++) {
            vector<int> number;
            while (arr2[i]) {
                number.push_back(arr2[i] % 10);
                arr2[i] /= 10;
            }
            ans = max(ans, search(number));
        }
        return ans;
    }
};
