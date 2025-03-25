class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x, y;
        for(int i = 0; i < rectangles.size(); i++){
            x.push_back({rectangles[i][0], rectangles[i][2]});
            y.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        stack<pair<int, int>> X, Y;
        for(int i = 0; i < x.size(); i++){
            if(X.empty()) X.push(x[i]);
            else{
                auto [a, b] = X.top();
                X.pop();
                if(x[i].first < b){
                    X.push({a, max(b, x[i].second)});
                }else{
                    X.push({a, b});
                    X.push(x[i]);
                }
            }
            if(Y.empty()) Y.push(y[i]);
            else{
                auto [a, b] = Y.top();
                Y.pop();
                if(y[i].first < b){
                    Y.push({a, max(b, y[i].second)});
                }else{
                    Y.push({a, b});
                    Y.push(y[i]);
                }
            }
        }
        return X.size() >= 3 || Y.size() >= 3;
    }
};