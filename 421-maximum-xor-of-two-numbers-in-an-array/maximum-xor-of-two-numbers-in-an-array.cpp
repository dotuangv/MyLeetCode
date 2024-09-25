
struct TrieNode{
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution {
public:
    TrieNode *root;
    Solution()
    {
        root = new TrieNode();
    }

    void insert(int x)
    {
        bitset<32> a(x);
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){
            if(!node->child[a[i]]){
                node->child[a[i]] = new TrieNode();
            }
            node = node->child[a[i]];
        }
    }

    int search(int x)
    {
        bitset<32> a(x);
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){
            int k = (a[i] + 1) % 2;
            if(node->child[k])
            {
                a[i] = 1;
                node = node->child[k];
            }else
            {
                a[i] = 0;
                node = node->child[(k + 1) % 2];
            }
        }
        int ans = 0;
        long long j = 1;
        for(int i = 0; i < 32; i++)
        {
            ans += a[i] * j;
            j *= 2;
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        insert(nums[0]);
        int ans = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            ans = max(ans, search(nums[i]));
            insert(nums[i]);
        }
        return ans;
    }
};