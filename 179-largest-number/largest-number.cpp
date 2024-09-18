class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> array;
        for (int num : nums) {
            array.push_back(to_string(num));
        }

        // Custom comparator for sorting
        sort(array.begin(), array.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        for(int i = 0; i< array.size() ; i++)cout<<array[i]<<" "; 

        // Handle the case where the largest number is "0"
        if (array[0] == "0") {
            return "0";
        }

        // Build the largest number from the sorted array
        string largest;
        for (const string &num : array) {
            largest += num;
        }

        return largest;
    }
};