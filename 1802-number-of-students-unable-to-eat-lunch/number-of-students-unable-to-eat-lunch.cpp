class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int x: students) q.push(x);
        int i = 0, cnt = 0;
        bool ok = true;
        while(ok)
        {
            if(q.front() == sandwiches[i])
            {
                q.pop();
                i++;
                cnt = 0;
            }else
            {
                cnt++;
                q.push(q.front());
                q.pop();
            }
            if(cnt == q.size()) break;
        }
        return q.size();
    }
};