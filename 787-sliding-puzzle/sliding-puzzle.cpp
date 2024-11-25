#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Chuyển vector<vector<int>> sang string
    string toString(const vector<vector<int>>& board) {
        string res;
        for (const auto& row : board) {
            for (int val : row) {
                res += (val + '0'); // Chuyển số sang ký tự
            }
        }
        return res;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        // Trạng thái đích
        string goal = "123450";
        // Trạng thái ban đầu
        string start = toString(board);
        // Các bước di chuyển (tương ứng vị trí của số 0)
        vector<vector<int>> moves = {
            {1, 3},          // 0 tại vị trí 0
            {0, 2, 4},       // 0 tại vị trí 1
            {1, 5},          // 0 tại vị trí 2
            {0, 4},          // 0 tại vị trí 3
            {1, 3, 5},       // 0 tại vị trí 4
            {2, 4}           // 0 tại vị trí 5
        };

        unordered_set<string> visited; // Để kiểm tra trạng thái đã xử lý
        queue<pair<string, int>> q;    // BFS: {trạng thái hiện tại, số bước}
        
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            // Kiểm tra trạng thái hoàn thành
            if (current == goal) return steps;

            // Tìm vị trí số 0
            int zeroPos = current.find('0');

            // Duyệt qua các bước di chuyển có thể
            for (int move : moves[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[move]); // Di chuyển số 0

                // Nếu trạng thái mới chưa được xử lý
                if (!visited.count(next)) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }

        return -1; // Không tìm thấy đường đi
    }
};
