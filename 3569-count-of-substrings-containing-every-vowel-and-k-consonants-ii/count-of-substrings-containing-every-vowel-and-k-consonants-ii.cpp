static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int l = 0, r = 0;
        long long ans = 0;
        queue<int> f_cons;
        vector<int> mp(26);
        while(r < word.size()){
            char c = word[r];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                mp[c - 'a'] = r + 1;
            }else f_cons.push(r + 1);
            while(f_cons.size() > k){
                char c = word[l];
                if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
                    f_cons.pop();
                }
                l++;
            }
            if(f_cons.size() == k && mp['a' - 'a'] > l && mp['e' - 'a'] > l && mp['i' - 'a'] > l && mp['o' - 'a'] > l && mp['u' - 'a'] > l){
                if(k){
                    int x = min({f_cons.front(), mp['a' - 'a'], mp['e' - 'a'], mp['i' - 'a'], mp['o' - 'a'], mp['u' - 'a']});
                    ans += x - l;
                }else{
                    int x = min({mp['a' - 'a'], mp['e' - 'a'], mp['i' - 'a'], mp['o' - 'a'], mp['u' - 'a']});
                    ans += x - l;
                }
            }
            r++;
        }
        return ans;
    }
};