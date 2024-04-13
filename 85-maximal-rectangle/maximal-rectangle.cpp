// class Solution {
// public:
//     // int largestRectangleArea(vector<int>& heights) {
//     //     int n = heights.size();
//     //   stack < int > st;
//     //   int leftsmall[n], rightsmall[n];
//     //   for (int i = 0; i < n; i++) {
//     //     while (!st.empty() && heights[st.top()] >= heights[i]) {
//     //       st.pop();
//     //     }
//     //     if (st.empty())
//     //       leftsmall[i] = 0;
//     //     else
//     //       leftsmall[i] = st.top() + 1;
//     //     st.push(i);
//     //   }
//     //   // clear the stack to be re-used
//     //   while (!st.empty())
//     //     st.pop();

//     //   for (int i = n - 1; i >= 0; i--) {
//     //     while (!st.empty() && heights[st.top()] >= heights[i])
//     //       st.pop();

//     //     if (st.empty())
//     //       rightsmall[i] = n - 1;
//     //     else
//     //       rightsmall[i] = st.top() - 1;

//     //     st.push(i);
//     //   }
//     //   int maxA = 0;
//     //   for (int i = 0; i < n; i++) {
//     //     maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
//     //   }
//     //   return maxA;
//     // }





// int largestRectangleArea(vector < int > & histo) {
// 	stack < int > st;
// 	int maxA = 0;
// 	int n = histo.size();
// 	for (int i = 0; i <= n; i++) {
// 		while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
// 			int height = histo[st.top()];
// 			st.pop();
// 			int width;
// 			if (st.empty())
// 				width = i;
// 			else
// 				width = i - st.top() - 1;
// 			maxA = max(maxA, width * height);
// 		}
// 		st.push(i);
// 	}
// 	return maxA;
// }


//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int n= matrix.size();
//         int m=matrix[0].size();
//            vector<int>height(m,0);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]=='1') height[j]++;
//                 else height[j]=0;
//             }
//         }

//         int maxArea=largestRectangleArea(height);

//         int ans=0;

//         ans= max(ans,maxArea);

//         return ans;

//     }
// };



class Solution {
public:

int largestRectangleArea(vector < int > & histo) {
	stack < int > st;
	int maxA = 0;
	int n = histo.size();
	for (int i = 0; i <= n; i++) {
		while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
			int height = histo[st.top()];
			st.pop();
			int width;
			if (st.empty())
				width = i;
			else
				width = i - st.top() - 1;
			maxA = max(maxA, width * height);
		}
		st.push(i);
	}
	return maxA;
}

int solve(vector<vector<char>>&mat, int n, int m) {
	int maxArea = 0;
	vector<int> height(m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '1') height[j]++;
			else height[j] = 0;
		}
		int area = largestRectangleArea(height);
		maxArea = max(area, maxArea);
	}

	return maxArea;
}


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        return solve(matrix, n, m);
    }
};