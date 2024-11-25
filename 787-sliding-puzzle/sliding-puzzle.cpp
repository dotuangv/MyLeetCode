class Solution {
public:
    // Convert vector<vector<int>> to string
    string toString(const vector<vector<int>>& board) {
        string res;
        for (const auto& row : board) {
            for (int val : row) {
                res += (val + '0'); // Convert integer to character
            }
        }
        return res;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        // Target state
        string goal = "123450";
        // Initial state
        string start = toString(board);
        // Moves corresponding to the position of the zero
        vector<vector<int>> moves = {
            {1, 3},          // 0 at position 0
            {0, 2, 4},       // 0 at position 1
            {1, 5},          // 0 at position 2
            {0, 4},          // 0 at position 3
            {1, 3, 5},       // 0 at position 4
            {2, 4}           // 0 at position 5
        };

        unordered_set<string> visited; // To check if a state has been processed
        queue<pair<string, int>> q;    // BFS: {current state, number of steps}
        
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            // Check if the target state is reached
            if (current == goal) return steps;

            // Find the position of zero
            int zeroPos = current.find('0');

            // Iterate through possible moves
            for (int move : moves[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[move]); // Move the zero

                // If the new state has not been processed
                if (!visited.count(next)) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }

        return -1; // No solution found
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();