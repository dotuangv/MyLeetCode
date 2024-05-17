class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
        int ans = 0;
        int l = 0, r = people.size() - 1;
        sort(people.begin(), people.end());
        while(l <= r)
        {
            if(people[l] + people[r] <= limit)
            {
                l++;
            }
            ans++;
            r--;
        }
        return ans;
    }
};