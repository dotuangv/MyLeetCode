class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        while(1){
            while(i < start.size() && start[i] == '_') i++;
            while(j < target.size() && target[j] == '_') j++;
            if(i == start.size()){
                if(j != target.size()) return false;
                else return true;
            }else
            {
                if(j == target.size()) return false;
                else if(start[i] == target[j]){
                    if(start[i] == 'L' && i < j) return false;
                    else if(start[i] == 'R' && i > j) return false;
                    i++;
                    j++;
                }else return false;
            }
        }
        return true;
    }
};