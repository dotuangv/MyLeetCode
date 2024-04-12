static auto speedup = []() { std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr); std::cin.tie(nullptr); return NULL; }();
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        for(int i = 0; i < n; i++)
        {
            long long x1i, x2i, y1i, y2i;
            x1i = bottomLeft[i][0];
            y1i = bottomLeft[i][1];;
            x2i = topRight[i][0];
            y2i = topRight[i][1];
            for(int j = i + 1; j < n; j++)
            {
                long long x1j, x2j, y1j, y2j;
                x1j = bottomLeft[j][0];
                y1j = bottomLeft[j][1];;
                x2j = topRight[j][0];
                y2j = topRight[j][1];
                long long t1 = 0, t2 = 0;
                if(x1i >= x1j && x2i <= x2j) t1 = x2i - x1i;
                else if(x1i <= x1j && x2i >= x2j) t1 = x2j - x1j;
                else if (x1i >= x2j || x2i <= x1j) t1 = 0;
                else
                {
                    t1 = min(abs(x1i - x2j), abs(x1j - x2i));
                }
                
                if(y1i >= y1j && y2i <= y2j) t2 = y2i - y1i;
                else if(y1i <= y1j && y2i >= y2j) t2 = y2j - y1j;
                else if (y1i >= y2j || y2i <= y1j) t2 = 0;
                else
                {
                    t2 = min(abs(y1i - y2j),abs(y1j - y2i));
                }
                // cout << t1 << " " << t2 << endl;
                ans = max(ans, min(t1, t2)*min(t1, t2));
            }
        }
        return ans;
    }
};