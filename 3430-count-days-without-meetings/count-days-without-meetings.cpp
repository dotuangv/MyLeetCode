class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = meetings[0][0] - 1, end = meetings[0][1];
        for(int i = 1; i < meetings.size(); i++){
            if(meetings[i][0] > end + 1){
                ans += meetings[i][0] - end - 1;
                end = meetings[i][1];
            }else{
                end = max(end, meetings[i][1]);
            }
        }
        return ans + days - end;
    }
};