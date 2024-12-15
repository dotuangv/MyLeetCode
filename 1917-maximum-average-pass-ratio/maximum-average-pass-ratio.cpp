class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for(int i = 0; i < classes.size(); i++){
            pq.push({(classes[i][0] + 1)*1.0 /(classes[i][1] + 1) - classes[i][0]*1.0/classes[i][1], {classes[i][0], classes[i][1]}});
        }
        while(extraStudents--){
            auto [a, b] = pq.top().second;
            pq.pop();
            pq.push({(a + 2)*1.0/(b + 2) - (a + 1)*1.0/(b + 1), {a + 1, b + 1}});
        }
        double ans = 0;
        while(!pq.empty()){
            auto [a, b] = pq.top().second;
            ans += a * 1.0 / b;
            pq.pop();
        }
        return ans/classes.size();
    }
};