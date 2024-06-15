
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital){
        ios_base::sync_with_stdio(false);
        int ans = w;
        priority_queue<int> maxheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        for(int i = 0; i < profits.size(); i++){
            if(capital[i] <= w) maxheap.push(profits[i]);
            else minheap.push({capital[i], profits[i]});
        }
        while(k-- && (!maxheap.empty() || !minheap.empty())) {
            while (!minheap.empty() && minheap.top().first <= ans){
                maxheap.push(minheap.top().second);
                minheap.pop();
            }
            if (!maxheap.empty()){
                ans += maxheap.top();
                maxheap.pop();
            }
        }
        return ans;
    }
};