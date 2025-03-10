class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int l = 0, r = 0;
        long long ans = 0;
        queue<int> f_cons;
        unordered_map<char, int> mp;
        while(r < word.size()){
            char c = word[r];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                mp[c] = r + 1;
            }else f_cons.push(r + 1);
            while(f_cons.size() > k){
                char c = word[l];
                if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
                    f_cons.pop();
                }
                l++;
            }
            if(f_cons.size() == k && mp['a'] > l && mp['e'] > l && mp['i'] > l && mp['o'] > l && mp['u'] > l){
                if(k){
                    int x = min({f_cons.front(), mp['a'], mp['e'], mp['i'], mp['o'], mp['u']});
                    ans += x - l;
                }else{
                    int x = min({mp['a'], mp['e'], mp['i'], mp['o'], mp['u']});
                    ans += x - l;
                }
            }
            r++;
        }
        return ans;
    }
};