class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            int num = i, len = 0, lsum = 0, rsum = 0;
            int digits[10]; 
            
            while (num > 0) {
                digits[len++] = num % 10;
                num /= 10;
            }
            
            if (len % 2 == 0) {
                int half = len / 2;
                for (int j = 0; j < half; j++) {
                    lsum += digits[len - 1 - j];
                    rsum += digits[half - 1 - j];
                }
                if (lsum == rsum)
                    ++count;
            }
        }
        return count;
    }
};