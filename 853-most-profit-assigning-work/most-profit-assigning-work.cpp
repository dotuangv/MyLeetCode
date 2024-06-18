class Solution {
public:
Solution(){
ios::sync_with_stdio(0);
cout.tie(0);
cin.tie(0);
}
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        /*
        int diffmax = INT_MIN,workermax = INT_MIN;
        for(int i : difficulty)
        if(i> diffmax)
        diffmax = i;
        for(int i: worker)
        if(i>workermax)
        workermax = i;

       int countMax = diffmax > workermax? diffmax:workermax;
       vector<int>  countArr(countMax+1); 
       for(int i = 0; i < difficulty.size(); ++i)
       {
        if(profit[i] > countArr[difficulty[i]])
       countArr[difficulty[i]] = profit[i]; 
       }
       for(int i =0;i<countArr.size()-1;++i)
       {
        if(countArr[i+1]==0)
       countArr[i+1] = countArr[i]; 
       else if(countArr[i+1]<countArr[i])
       countArr[i+1] = countArr[i];
       }
       int sum = 0;
       for(int i = 0; i<worker.size();++i)
       {
        sum += countArr[worker[i]] ;
       }
return sum;
*/
struct{
bool operator() (const pair<int,int> first, const pair<int,int> second)  const
{
   return first.first < second.first; 
}
}cmp;
vector <pair<int,int>> jobs;
for(int i = 0; i<difficulty.size();++i)
jobs.push_back({difficulty[i],profit[i]});;
ranges::sort(jobs,cmp);
ranges::sort(worker);
int best = 0;
int sum = 0;
int i = 0;
for(int w: worker)
{
    while(i < jobs.size() && jobs[i].first <= w)
    best = max(best,jobs[i++].second);
    sum += best;

}
return sum;
    }
};