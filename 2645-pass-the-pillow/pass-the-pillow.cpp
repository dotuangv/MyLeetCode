class Solution {
public:
    int passThePillow(int n, int time) {
        if(time % (n - 1) == 0) return (n - 1)*(time/(n - 1) % 2) + 1;
        else
        {
            if(time/(n - 1) % 2) return n - time % (n - 1);
            else return time % (n - 1) + 1;
        }
    }
};