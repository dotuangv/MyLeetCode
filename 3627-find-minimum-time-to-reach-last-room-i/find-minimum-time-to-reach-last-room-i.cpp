class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startX = 0, startY = 0;
         // Khởi tạo ma trận khoảng cách với giá trị vô cùng
    vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
    dist[startX][startY] = 0;

    // Hàng đợi ưu tiên để lưu các ô (khoảng cách, tọa độ x, tọa độ y)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, startX, startY);

    // Các hướng di chuyển: lên, xuống, trái, phải
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!pq.empty()) {
        auto [currentDist, x, y] = pq.top();
        pq.pop();

        // Nếu đã đến đích
        if (x == m - 1 && y == n - 1) {
            return currentDist;
        }

        // Bỏ qua nếu tìm thấy đường tốt hơn trước đó
        if (currentDist > dist[x][y]) {
            continue;
        }

        // Duyệt các ô kề
        for (const auto& [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {  // Kiểm tra giới hạn của ma trận
                int newDist = max(currentDist, grid[nx][ny]) + 1;
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    pq.emplace(newDist, nx, ny);
                }
            }
        }
    }
    return dist[m - 1][n - 1];
    }
};