class Solution {
public:
    const int INF = numeric_limits<int>::max();
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    bool isValid(int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    int dijkstra2D(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> dest) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INF));
        dist[start.first][start.second] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currentCost, currentPos] = pq.top();
            pq.pop();

            int x = currentPos.first;
            int y = currentPos.second;

            if (currentPos == dest) {
                return currentCost;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny, rows, cols)) {
                    int newCost = currentCost + grid[nx][ny];
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        return dijkstra2D(grid, {0, 0}, {grid.size() - 1, grid[0].size() - 1});
    }
};