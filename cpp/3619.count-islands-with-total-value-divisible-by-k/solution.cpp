// Created by oportunitas at 2026/10/26 09:12
// leetgo: 1.4.18
// https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #0 (23ms/88th% | 78.6MB/90th%)
    we can do bfs on each island and count
*/
class Solution {
private:
    int64_t _dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0z;
        } else {
            int64_t result {grid[i][j]}; grid[i][j] = 0;
            result += (
                _dfs(grid, i-1,j) + _dfs(grid, i+1,j) + _dfs(grid, i,j-1) + _dfs(grid, i,j+1)
            );
            return result;
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int64_t count {0};
        for (int64_t i {0}; i < grid.size(); ++i) {
            for (int64_t j {0}; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0 && _dfs(grid,i,j) % k == 0) count++;
            }
        } return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> grid = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.countIslands(grid, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
