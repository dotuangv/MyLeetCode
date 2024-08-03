// Start Of Anuj Bhati aka Edwards310's Template...
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define FOR(a, b, c) for (int a = b; a < c; a++)
#define FOR1(a, b, c) for (int a = b; a <= c; ++a)
#define Rep(i, n) FOR(i, 0, n)
#define Rep1(i, n) FOR1(i, 1, n)
#define fi first

// end of Anuj Bhati's aka Edwards310's Template
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vi help(1001, 0);
        Rep(i, target.size())
            help[target[i]]++;
        
        Rep(i, arr.size())
            help[arr[i]]--;
        
        Rep(i, 1001)
            if(help[i])
                return false;
        return true;
    }
};