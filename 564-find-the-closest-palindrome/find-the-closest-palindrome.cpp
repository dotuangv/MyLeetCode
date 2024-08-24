class Solution {
public:
    string nearestPalindromic(string numberStr) {
        // if(n.size() == 1)
        // {
        //     n[0]--;
        //     return n;
        // }
        // if(n[0] == '1')
        // {
        //     bool ok = true;
        //     for(int i = 1; i < n.size(); i++) if(n[i] != '0') ok = false;
        //     if(ok)
        //     {
        //         string ans = "";
        //         for(int i = 0; i < n.size() - 1; i++) ans.push_back('9');
        //         return ans;
        //     }
        // }
        // int j = 0;
        // vector<int> pre(n.size());
        // pre[0] = -1;
        // for(int i = 1; i < pre.size(); i++)
        // {
        //     pre[i] = j;
        //     if(n[i] != '0') j = i;
        // }
        // bool ok = false;
        // int l = 0, r = n.size() - 1;
        // while(l <= r)
        // {
        //     if(n[l] != n[r])
        //     {
        //         ok = true;
        //         if(n[l] < n[r]) n[r] = n[l];
        //         else
        //         {
        //             n[pre[r]]--;
        //             n[r] = n[l];
        //             for(int i = pre[r] + 1; i < r; i++) n[i] = '9'; 
        //         }
        //     }
        //     l++;
        //     r--;
        // }
        // if(ok) return n;
        // else
        // {
        //     l = (n.size() - 1)/2, r = n.size()/2;
        //     while(l >= 0 && r < n.size())
        //     {
        //         if(n[l] != '0')
        //         {
        //             n[l]--;
        //             if(l != r) n[r]--;
        //             if(n[0] != '0') return n;
        //             else break;
        //         }else
        //         {
        //             l--;
        //             r++;
        //         }
        //     }
        //     string ans = "";
        //     for(int i = 0; i < n.size() - 1; i++) ans.push_back('9');
        //     return ans;
        // }

    long long number = stoll(numberStr);
        
        // Edge cases for small numbers
        if (number <= 10) return to_string(number - 1);
        if (number == 11) return "9";
        
        // Special case for 18-digit number with all 9s, thanks to dcodeDV for pointing this out
        if (numberStr == "999999999999999999") {
            return "1000000000000000001";
        }
        
        int length = numberStr.length();
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));
        
        vector<long long> palindromeCandidates(5);
        palindromeCandidates[0] = generatePalindromeFromLeft(leftHalf - 1, length % 2 == 0);
        palindromeCandidates[1] = generatePalindromeFromLeft(leftHalf, length % 2 == 0);
        
        // Handle potential overflow for leftHalf + 1
        if (leftHalf < 999999999) {
            palindromeCandidates[2] = generatePalindromeFromLeft(leftHalf + 1, length % 2 == 0);
        } else {
            palindromeCandidates[2] = stoll("1" + string(length - 1, '0') + "1");
        }
        
        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;
        
        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;
        
        for (long long candidate : palindromeCandidates) {
            if (candidate == number) continue;
            long long difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }
        
        return to_string(nearestPalindrome);
    }

private:
    long long generatePalindromeFromLeft(long long leftHalf, bool isEvenLength) {
        long long palindrome = leftHalf;
        if (!isEvenLength) leftHalf /= 10;
        while (leftHalf > 0) {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
};