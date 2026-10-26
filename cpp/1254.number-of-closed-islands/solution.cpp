// Created by oportunitas at 2026/10/25 14:03
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-closed-islands/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #0 (0ms/100th% | 12.9MB/95th%)
    we do dfs and return true if its an enclosed island
*/
class Solution {
private:
    int _fill(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        } if (grid[i][j] == 1) {
            return true;
        } grid[i][j] = 1;

        return (bool)(
            _fill(grid,i+1,j) & _fill(grid,i-1,j) & _fill(grid,i,j+1) & _fill(grid,i,j-1)
        );
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int result {0};
        for (int i {0}; i < grid.size(); ++i) {
            for (int j {0}; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0 && _fill(grid,i,j)) {
                    result += 1;
                }
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
		auto res = obj.closedIsland(grid);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
