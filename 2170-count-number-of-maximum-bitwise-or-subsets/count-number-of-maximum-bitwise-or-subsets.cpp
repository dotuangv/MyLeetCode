class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Tính giá trị OR lớn nhất từ tất cả các phần tử
        int Max = 0;
        for(auto x: nums) Max |= x;
        
        int ans = 0, n = nums.size();
        
        // Duyệt qua tất cả các tập con của nums
        for(int i = 0; i < (1 << n); i++) {
            int res = 0;
            for(int j = 0; j < n; j++) {
                // Kiểm tra xem bit thứ j có bật trong số i không
                if(i & (1 << j)) {
                    res |= nums[j];
                }
            }
            // Nếu giá trị OR của tập con bằng Max, tăng số lượng tập con hợp lệ
            if(res == Max) ans++;
        }
        
        return ans;
    }
};
