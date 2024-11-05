class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty array case

        int k = 1; // Start with the first unique element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Check for unique element
                nums[k] = nums[i]; // Place unique element at the k-th position
                k++; // Move to the next position
            }
        }

        return k; // Return the count of unique elements
    }
};