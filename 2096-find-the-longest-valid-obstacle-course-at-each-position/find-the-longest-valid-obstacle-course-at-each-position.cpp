class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        const int size{static_cast<int>(obstacles.size())};
        vector<int> ans(size,1);
        array<int,100001> arr{};
        arr[0] = obstacles[0];
        int largest{arr[0]};
        int smallest{arr[0]};
        int length{1};
        for (int i{1}; i<size; ++i) {
            if (obstacles[i] >= largest) {
                largest = obstacles[i];
                arr[length] = largest;
                ans[i] = length + 1;
                ++length;
            }
            else if (obstacles[i] < smallest) {
                smallest = obstacles[i];
                arr[0] = smallest;
                if (length == 1) {
                    largest = smallest;
                }
            }
            else {
                int left{0};
                int right{length};
                while (true) {
                    int ind{(left+right)/2};
                    if (obstacles[i] < arr[ind]) {
                        right = ind;
                    }
                    else if (obstacles[i] >= arr[ind+1]) {
                        left = ind + 1;
                    }
                    else {
                        arr[ind+1] = obstacles[i];
                        if (ind+1 == length-1) {
                            largest = obstacles[i];
                        }
                        ans[i] = ind + 2;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};