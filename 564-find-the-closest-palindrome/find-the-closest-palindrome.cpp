class Solution {
public:
    string nearestPalindromic(string n) {
        // if(n.size() == 1)
        // {
        //     n[0]--;
        //     return n;
        // }
        // if(n[0] == '1')
        // {
        //     bool ok = true;
        //     for(int i = 1; i < n.size(); i++) if(n[i] != '0') ok = false;
        //     if(ok)
        //     {
        //         string ans = "";
        //         for(int i = 0; i < n.size() - 1; i++) ans.push_back('9');
        //         return ans;
        //     }
        // }
        // int j = 0;
        // vector<int> pre(n.size());
        // pre[0] = -1;
        // for(int i = 1; i < pre.size(); i++)
        // {
        //     pre[i] = j;
        //     if(n[i] != '0') j = i;
        // }
        // bool ok = false;
        // int l = 0, r = n.size() - 1;
        // while(l <= r)
        // {
        //     if(n[l] != n[r])
        //     {
        //         ok = true;
        //         if(n[l] < n[r]) n[r] = n[l];
        //         else
        //         {
        //             n[pre[r]]--;
        //             n[r] = n[l];
        //             for(int i = pre[r] + 1; i < r; i++) n[i] = '9'; 
        //         }
        //     }
        //     l++;
        //     r--;
        // }
        // if(ok) return n;
        // else
        // {
        //     l = (n.size() - 1)/2, r = n.size()/2;
        //     while(l >= 0 && r < n.size())
        //     {
        //         if(n[l] != '0')
        //         {
        //             n[l]--;
        //             if(l != r) n[r]--;
        //             if(n[0] != '0') return n;
        //             else break;
        //         }else
        //         {
        //             l--;
        //             r++;
        //         }
        //     }
        //     string ans = "";
        //     for(int i = 0; i < n.size() - 1; i++) ans.push_back('9');
        //     return ans;
        // }
        if(n.length()==1)
            return to_string(stoi(n)-1);
        
        int d = n.length();
        vector<long> candidates;
        candidates.push_back(pow(10,d-1)-1);
        candidates.push_back(pow(10,d)+1);

        int mid = (d+1)/2;
        long prefix = stol(n.substr(0,mid));
        vector<long> v = {prefix,prefix+1, prefix-1};
        for(long i : v)
        {
            string postfix = to_string(i);
            if(d%2!=0)
                postfix.pop_back();
            reverse(postfix.begin(), postfix.end());
            string c = to_string(i)+postfix;
            candidates.push_back(stol(c));
        }
        long mindiff = LONG_MAX;
        long result;
        long num = stol(n);
        for(int i=0;i<5;i++)
        {
            if(candidates[i]!=num && abs(candidates[i]-num)<mindiff)
            {
                mindiff = abs(candidates[i]-num);
                result = candidates[i];
            }
            else if(abs(candidates[i]-num)==mindiff)
                result = min(result, candidates[i]);
        }
        return to_string(result);
    }
};