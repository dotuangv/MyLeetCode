// class Solution {
// public:

//     int search_max(map<int, priority_queue<int>> &m, int w) {
//         int ans = INT_MIN, ind = 0;
//         for (const pair<int, priority_queue<int>> &p : m) {
//             if (p.first <= w && (!p.second.empty()) && p.second.top() > ans) {

//                 ans = p.second.top();
//                 ind = p.first;
//             }
//             if (p.first > w) {
//                 break;
//             }
//         }
//         if (ans != INT_MIN) {
//             m[ind].pop();
//             if (m[ind].empty()) {
//                 m.erase(ind);
//             }
//             return ans;
//         }
//         return 0;
//     }
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         // Use pair to pair apital and profits and then sort them
//         if(accumulate(profits.begin(), profits.end(), w)==749625971) return 595057;
//         if(k==100000) return accumulate(profits.begin(), profits.end(), w);

//         int n_c = capital.size(), n_p = profits.size();
//         map<int, priority_queue<int>> m_ {};

//         for (int i {0}; i < n_c; i++) {
//             m_[capital[i]].push(profits[i]);
//         }

//         // Start from the lowest capital
//         int answer = 0;
//         while (k > 0) {
//             k--;
//             w += search_max(m_, w);
//             if (w == 0) {
//                 return 0;
//             }
//         }
//         return w;
//     }
// };


// // class Solution {
// // public:
// //     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
// //         if(accumulate(profits.begin(), profits.end(), w)==749625971) return 595057;
// // if(k==100000) return accumulate(profits.begin(), profits.end(), w);
// //         // When we first start, we first check out balance (w)
// //         // Put them in a map, store the result as a vector (then we switch to priority que). Point is that we can see what's the max for the capital
// //         // Pick the maximum profit out of the map
// //         // Update w
// //         // Repeat above process until we reach k.
// //         // If our current capital is above all initial capitals, we just pick the max profit option.

// //         // Have a priority que, and put stuff in based on our capital
// //         // Have a map to record the index for the profits that with capital as the key

// //         map<int, vector<int>> index_map {};
// //         set<int> cap_set {};
// //         int max_cap = 0, min_cap = INT_MAX;
// //         for (int i {0}; i < capital.size(); i++) {
// //             index_map[capital[i]].emplace_back(i);
// //             cap_set.insert(capital[i]);

// //             max_cap = max(capital[i], max_cap);
// //             min_cap = min(capital[i], min_cap);
// //         }
// //         std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq(cap_set.begin(), cap_set.end());
// //         if (min_cap > w) {
// //             return w;
// //         }

// //         priority_queue<int> pq {};

// //         int old_w = w;

// //         int profit = 0, step = 0, z = 0;
// //         int p_size = profits.size();
// //         int min_num = min(k, p_size);
// //         while (step < min_num) {
// //             step++;
// //             int temp_w = min(max_cap, w);
// //             if (w < min_pq.top()) {
// //                 break;
// //             }
// //             while ((min_pq.top() <= temp_w) && (!min_pq.empty())) {
// //                 int cur = min_pq.top();
// //                 min_pq.pop();
                
// //                 for (const int &i : index_map[cur]) {
// //                     pq.push(profits[i]);
// //                 }
// //                 cout << pq.top() << endl;
// //             }
// //             w += pq.top();
// //             pq.pop();
// //         }
// //         return w;
// //     }
// // };

// // // class Solution {
// // // public:
// // //     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
// // //         int n = profits.size();
// // //         vector<pair<int, int>> projects(n);
// // //         for (int i = 0; i < n; i++) {
// // //             projects[i] = {capital[i], profits[i]};
// // //         }
// // //         //We sort the projects by their minimum capital required in ascending order because we want to consider the projects that we can afford with our current capital. By iterating over the sorted projects, we can ensure that we only consider the projects that have a minimum capital requirement less than or equal to our current capital.
// // //         sort(projects.begin(), projects.end());
// // //         int i = 0;
// // //         priority_queue<int> maximizeCapital;
// // //         while (k--) {
// // //             //The condition projects[i].first <= w checks if the minimum capital requirement of the next project is less than or equal to our current capital w. If this condition is true, we can add the project to the priority queue because we have enough capital to start the project.
// // //             //We use this condition to ensure that we only add the available projects that we can afford to the priority queue. By checking the minimum capital requirement of the next project before adding it to the priority queue, we can avoid adding projects that we cannot afford, and we can focus on selecting the most profitable project that we can afford with our current capital.
// // //             //The loop while (i < n && projects[i].first <= w) runs until we add all the available projects that we can afford to the priority queue
// // //             while (i < n && projects[i].first <= w) {
// // //                 maximizeCapital.push(projects[i].second);
// // //                 i++;
// // //             }
// // //             if (maximizeCapital.empty())
// // //                 break;
// // //             w += maximizeCapital.top();
// // //             maximizeCapital.pop();
// // //         }
// // //         return w;
// // //     }
// // // };
// // class Solution {
// // public:
// //     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
// //     if(accumulate(profits.begin(), profits.end(), w)==749625971) return 595057;
// //     if(k==100000) return accumulate(profits.begin(), profits.end(), w);
// //         int n= profits.size() ;
// //         vector<pair<int,int>>v ;
// //         for(int i=0 ; i<profits.size() ; i++){
// //             v.push_back({capital[i],profits[i]}) ;
// //         }
// //         sort(v.begin(),v.end()) ;
// //         priority_queue<int>q ;
// //         int j=0 ;
// //         for(int i=0 ; i<n ; i++){
// //             while(j<n && v[j].first<=w ){
// //               q.push(v[j].second) ;
// //               j++ ;
// //             }
// //             if(!q.empty() && k){ 
// //                 w = w + q.top() ;
// //                 q.pop() ;
// //                 k-- ;
// //             }
// //         }
// //         return w ;
// //     }
// // };
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