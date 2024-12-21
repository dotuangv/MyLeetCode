class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> path(n);
        for (int i = 0; i < edges.size(); i++) {
            path[edges[i][0]].push_back(edges[i][1]);
            path[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        stack<pair<int, long long>> stk; // Pair chứa node và tổng giá trị tính tới node đó
        vector<long long> subtreeSum(n, 0); // Để lưu giá trị tổng của từng cây con
        stk.push({0, 0}); // Bắt đầu DFS từ node 0
        visited[0] = true;

        int ans = 0;

        while (!stk.empty()) {
            int node = stk.top().first;
            long long sum = stk.top().second;
            bool allVisited = true; // Kiểm tra xem tất cả con của node đã được duyệt chưa

            for (int neighbor : path[node]) {
                if (!visited[neighbor]) {
                    stk.push({neighbor, 0}); // Đưa con của node vào stack
                    visited[neighbor] = true;
                    allVisited = false;
                }
            }

            if (allVisited) { // Nếu tất cả con của node đã duyệt
                stk.pop(); // Lấy node ra khỏi stack
                long long currentSum = values[node]; // Bắt đầu với giá trị của node
                for (int neighbor : path[node]) {
                    if (subtreeSum[neighbor] > 0) { // Thêm tổng của các cây con
                        currentSum += subtreeSum[neighbor];
                    }
                }

                if (currentSum % k == 0) { // Nếu tổng chia hết cho k
                    ans++;
                    subtreeSum[node] = 0; // Đặt lại cây con thành 0
                } else {
                    subtreeSum[node] = currentSum; // Lưu lại tổng giá trị của cây con
                }
            }
        }

        return ans;
    }
};
