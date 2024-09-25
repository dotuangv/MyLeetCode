class TrieNode {
public:
    TrieNode* children[26];  // con trỏ tới các nút con (26 ký tự tiếng Anh)
    int ok;  // số lượng từ đi qua node này

    TrieNode() {
        // Khởi tạo tất cả các con trỏ là nullptr và ok là 0
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        ok = 0;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode();
    }

    // Hàm thêm một từ vào trie
    void insert(string &s) {
        TrieNode* node = root;
        for (char c : s) {
            int k = c - 'a';
            if (!node->children[k]) {
                node->children[k] = new TrieNode();
            }
            node = node->children[k];
            node->ok++;
        }
    }

    // Hàm tìm kiếm số điểm prefix của một từ
    int search(string &s) {
        TrieNode* node = root;
        int ans = 0;
        for (char c : s) {
            int k = c - 'a';
            if (!node->children[k]) return ans;  // nếu không tìm thấy prefix thì dừng
            node = node->children[k];
            ans += node->ok;
        }
        return ans;
    }

    // Hàm chính trả về điểm prefix cho mỗi từ trong danh sách
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        for (string &word : words) {
            insert(word);
        }
        for (string &word : words) {
            ans.push_back(search(word));
        }
        return ans;
    }
};
