class Solution {
public:
    void dfs(int i, vector<vector<int>> &rooms, vector<bool> &visited)
    {
        visited[i] = true;
        for(auto &x: rooms[i])
        {
            if(!visited[x]) dfs(x, rooms, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        dfs(0, rooms, visited);
        for(auto x: visited)
            if(!x) return false;
        return true;
    }
};