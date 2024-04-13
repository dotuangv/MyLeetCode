// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.
// Array
// Dynamic Programming
// Matrix

#include <vector>
#include <iostream>

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution
{
public:
    /**
     * @brief Calculates the area of the largest square of '1's in the given matrix.
     * 
     * @details 
     * This function uses dynamic programming to solve the problem. It iterates over the matrix and for each cell that contains '1', 
     * it finds the size of the square that can be made using this cell as the bottom right corner by checking its adjacent cells. 
     * It keeps track of the maximum size of the square found so far.
     * 
     * Time complexity: O(m*n) where m is the number of rows and n is the number of columns in the matrix.
     * Space complexity: O(m*n) as a 2D vector of size m*n is used for dynamic programming.
     * 
     * @param matrix The input matrix of '0's and '1's.
     * @return The area of the largest square of '1's in the matrix.
     */
    int maximalSquare(std::vector<std::vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSideLength = 0;  // This holds the side length of the maximum square found so far. There is no need to do the multiplication to find area until it is time to return the result.
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int row = 1; row <= m; row++)
        {
            for (int col = 1; col <= n; col++)
            {
                if (matrix[row - 1][col - 1] == '1')
                {
                    dp[row][col] = std::min({dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]}) + 1;
                    maxSideLength = std::max(maxSideLength, dp[row][col]);
                }
            }
        }

        return maxSideLength * maxSideLength;
    }
};