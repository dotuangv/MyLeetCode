class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<int, int>> pq;
        string ans = "";
        vector<int> vt(26), cnt(26);
        for(auto &x: s){
            vt[x - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            pq.push({vt[i], i});
        }
        while(1){
            bool ok = false;
            for(int i = 25; i >= 0; i--){
                if(vt[i] == 0) continue;
                if(ans.empty()){
                    ok = true;
                    for(int j = 0; j < min(repeatLimit, vt[i]); j++){
                        ans.push_back(i + 'a');
                    }
                    vt[i] = max(0, vt[i] - repeatLimit);
                    cnt[i] = repeatLimit;
                    break;
                }else{
                    if(i == ans.back() - 'a'){
                        if(cnt[i] < repeatLimit){
                            ans.push_back(i + 'a');
                            vt[i]--;
                            cnt[i]++;
                            ok = true;
                            break;
                        }
                        continue;
                    }
                    cnt[ans.back() - 'a'] = 0;
                    ok = true;
                    ans.push_back(i + 'a'); 
                    cnt[i]++;
                    vt[i]--;
                    break;
                }
            }
            if(!ok) break;
        }
        return ans;
    }
};
