// Created by oportunitas at 2026/09/21 09:39
// leetgo: 1.4.18
// https://leetcode.com/problems/largest-local-values-in-a-matrix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 15.6MB/82th%)
		idea #0 turns out to be slower than expected. this is most probably due to
		specific hardware/memory inefficiencies of using the approach. will investigate later.

		lets use the 3x3 sliding window and see if its more performant and or easier to 
		autovectorize by the compiler
	*/

	vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> result (n - 2, vector<int>(n - 2, 0));
		for (int i {1}; i < n - 1; ++i) {
			for (int j {1}; j < n - 1; ++j) {
				int window_max = 0;

				// 3x3 window
				for (int k {i - 1}; k <= i + 1; ++k) {
					for (int l {j - 1}; l <= j + 1; ++l) {
						window_max = max(window_max, grid[k][l]);
					}
				} result[i - 1][j - 1] = window_max;
			}
		} return result;
	}

	// /* idea #0 (2ms/42th% | 15.6MB/82th%)
	// 	we can consider 2 approaches:
	// 		1. 	calculate the max for each tile that would be in the final grid.
	// 			assuming no optimizations, we need to calculate 9 times to find the max
	// 			in a 3x3 grid. we do this (n - 2) * (n - 2) times. as such, the time is:
	// 				9 * ((n - 2) * (n - 2))
	// 		2.	traverse the array in 4 directions (up, down, left, right) and do:
	// 			if last num is bigger, change cur num to last num and last num to cur num,
	// 			if not, change last num to cur num anyway. the time is:
	// 				4 * n * n
	// 	lets compare:
	// 		9 * (n - 2) * (n - 2) = 9 * (n^2 - 4n + 4)
	// 							  = 9n^2 - 36n + 36
	// 		4 * n * n             = 4n^2

	// 	for big n, the 2nd approach is more time efficient since the n^2 part is smaller

	// 	now as for optimization, both cases should be auto-vectorized under -O2, so both
	// 	should have the same reduction in time, equivalent to dividing by some number x:
	// 		9n^2 - 36n + 36 --autovec-> (9n^2 - 36n + 36) / x
	// 		           4n^2 --autovec-> 4n^2 / x
	// 	the efficiency argument pertains in this case.

	// */
    // vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
	// 	int last {(int)(grid.size() - 1)};
	// 	int n = grid.size();
	// 	vector<vector<int>> result (n - 2, vector<int>(n - 2, 0));

	// 	for (int i {0}; i <= last; ++i) {
	// 		int cur_max = 0;
	// 		for (int j {0}; j <= last; ++j) {
	// 			// til: std::exchange(), which allows for postfix (i++-esque) assignment
	// 			cur_max = exchange(grid[i][j], max(cur_max, grid[i][j]));
	// 		}
	// 	} for (int j {0}; j <= last; ++j) {
	// 		int cur_max = 0;
	// 		for (int i {0}; i <= last; ++i) {
	// 			// til: std::exchange(), which allows for postfix (i++-esque) assignment
	// 			cur_max = exchange(grid[i][j], max(cur_max, grid[i][j]));
	// 		}
	// 	} for (int i {last}; i >= 0; --i) {
	// 		int cur_max = 0;
	// 		for (int j {last}; j >= 0; --j) {
	// 			// til: std::exchange(), which allows for postfix (i++-esque) assignment
	// 			cur_max = exchange(grid[i][j], max(cur_max, grid[i][j]));
	// 		}
	// 	} for (int j {last}; j >= 0; --j) {
	// 		int cur_max = 0;
	// 		for (int i {last}; i >= 0; --i) {
	// 			// til: std::exchange(), which allows for postfix (i++-esque) assignment
	// 			cur_max = exchange(grid[i][j], max(cur_max, grid[i][j]));
	// 		}
	// 	} 
		
	// 	for (int i {1}; i < last; ++i) {
	// 		for (int j {1}; j < last; ++j) {
	// 			result[i - 1][j - 1] = grid[i][j];
	// 		}
	// 	}

	// 	return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> grid = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.largestLocal(grid);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
