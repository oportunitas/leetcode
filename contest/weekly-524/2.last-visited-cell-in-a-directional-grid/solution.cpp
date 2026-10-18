// Created by oportunitas at 2026/10/18 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/last-visited-cell-in-a-directional-grid/
// https://leetcode.com/contest/weekly-contest-524/problems/last-visited-cell-in-a-directional-grid/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        // println("grid: \n {}", grid);
        int height {(int)grid.size()}; int width {(int)grid[0].size()};

        int i {0}; int j {0};
        while (true) {
            // println("at {}, {}", i, j);
            int next_i {i}; int next_j {j};
            if (grid[i][j] == 'L') {
                next_j -= 1;
            } else if (grid[i][j] == 'R') {
                next_j += 1;
            } else if (grid[i][j] == 'U') {
                next_i -= 1;
            } else if (grid[i][j] == 'D') {
                next_i += 1;
            }

            // println("trying to go to {}, {}", next_i, next_j);
            if (
                next_i >= 0 && next_i < height && next_j >= 0 && next_j < width && 
                grid[next_i][next_j] != 'X'
            ) {
                grid[i][j] = 'X';
                i = next_i;
                j = next_j;
            } else {
                break;
            }
        }

        // println("final: {}, {}", i, j);
        return {i, j};
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<char>> grid = LeetCodeIO::deserialize<vector<vector<char>>>(cin);

		Solution obj;
		auto res = obj.lastVisitedCell(grid);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
