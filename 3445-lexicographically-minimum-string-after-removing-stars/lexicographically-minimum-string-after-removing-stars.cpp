class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*') pq.push({s[i], -i});
            else if(!pq.empty()) pq.pop();
        }

        vector<bool> mp(s.size());
        while(!pq.empty()){
            mp[-pq.top().second] = true;
            pq.pop();
        }

        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(mp[i]) ans += s[i];
        }
        return ans;
    }
};