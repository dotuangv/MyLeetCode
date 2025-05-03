class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = -1;
        for(int i = 1; i <= 6; i++){
            int top = 0, bottom = 0;
            for(int j = 0; j < tops.size(); j++){
                if(tops[j] != i && top != -1){
                    if(bottoms[j] == i) top++;
                    else top = -1;
                }
                if(bottoms[j] != i && bottom != -1){
                    if(tops[j] == i) bottom++;
                    else bottom = -1;
                }
            }
            if(top != -1){
                if(ans == -1) ans = top;
                else ans = min(ans, top);
            }

            if(bottom != -1){
                if(ans == -1) ans = bottom;
                else ans = min(ans, bottom);
            }
        }
        return ans;
    }
};