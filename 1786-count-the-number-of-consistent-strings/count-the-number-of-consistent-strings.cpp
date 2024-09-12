class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> a(26);
        for(auto x: allowed) a[x - 'a'] = true;
        int ans = 0;
        for(auto x: words){
            bool ok = true;
            for(auto y: x) if(!a[y - 'a']) ok = false;
            if(ok) ans++;
        }
        return ans;
    }
};