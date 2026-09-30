// Created by oportunitas at 2026/09/30 08:40
// leetgo: 1.4.18
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 13.8MB/40th%)
        we can find the max value for each column and row. for each tile,
        whichever is the least of the 2 maxes (column vs row) shall be its new
        height.

        the grid size is small (at most 50 x 50), so lets try to not use 
        dynamic programming for a moment
    */
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> col_max (grid.size(), 0);
        vector<int> row_max (grid.size(), 0);

        for (int i {0}; i < grid.size(); ++i) {
            for (int j {0}; j < grid.size(); ++j) {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }

        int result {0};
        for (int i {0}; i < grid.size(); ++i) {
            for (int j {0}; j < grid.size(); ++j) {
                result += abs(min(row_max[i], col_max[j]) - grid[i][j]);
            }
        }

        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> grid = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.maxIncreaseKeepingSkyline(grid);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
