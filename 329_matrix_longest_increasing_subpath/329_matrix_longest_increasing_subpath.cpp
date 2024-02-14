// 329_matrix_longest_increasing_subpath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };   // all the moves available to us - top, down, left, right
//int longestIncreasingPath(vector<vector<int>>& matrix) {
//	int maxPath = 1; // atleast one cell can always be selected in the path
//	// explore each cell of matrix to find longest path achievable from that cell and finally return the maximum
//	for (int i = 0; i < size(matrix); i++)
//	{
//		for (int j = 0; j < size(matrix[0]); j++)
//		{
//			maxPath = max(maxPath, solve(matrix, i, j));
//		}
//	}
//	return maxPath;
//}
//// recursive solver for each cell 
//int solve(vector<vector<int>>& mat, int i, int j) {
//	int MAX = 1;  // max length of path starting from cell i,j of matrix
//	// choosing all the 4 moves available for current cell
//	for (int k = 0; k < 4; k++) 
//	{
//		int new_i = i + moves[k][0];
//		int new_j = j + moves[k][1];
//		// bound checking as well as move to next cell only when it is greater in value
//		if (new_i < 0 || new_j < 0 || new_i >= size(mat) || new_j >= size(mat[0]) || mat[new_i][new_j] <= mat[i][j]) 
//			continue;
//		// MAX will be updated each time to store maximum of path length from each move
//		MAX = max(MAX, 1 + solve(mat, new_i, new_j));
//	}
//	return MAX;
//}

int dp[200][200]{}; // constraints are small enough that we can just set them to MAX
int maxPath, n, m;
int solve(vector<vector<int>>& mat, int i, int j, int prev) {
	if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
	if (dp[i][j]) return dp[i][j];
	/*return dp[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j]),
								solve(mat, i - 1, j, mat[i][j]),
								solve(mat, i, j + 1, mat[i][j]),
								solve(mat, i, j - 1, mat[i][j]) });*/
	int down = solve(mat, i + 1, j, mat[i][j]);
	int up = solve(mat, i - 1, j, mat[i][j]);
	int right = solve(mat, i, j + 1, mat[i][j]);
	int left = solve(mat, i, j - 1, mat[i][j]);
	return dp[i][j] = 1 + max(up, max(down, max(left, right )));
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
	int maxPath = 0, n = size(matrix), m = size(matrix[0]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			maxPath = max(maxPath, solve(matrix, i, j, -1));
			int x = 0;
		}
	}
	return maxPath;
}

int main()
{
    std::cout << "Hello World!\n";
	vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int ans = longestIncreasingPath(matrix);
	cout << ans;
	cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
