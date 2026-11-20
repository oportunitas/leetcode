// Created by oportunitas at 2026/11/20 13:51
// leetgo: 1.4.18
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (6ms/100th% | 104.7MB/100th%)
        we can first precompute the values per row and column,
        then we repurpose grid for the return value. we return with
        move(grid) to avoid array copy. 
    */
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = ssize(grid); int m = ssize(grid[0]);
        
        vector<int> rowcount (n, 0);
        vector<int> colcount (m, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int diff = (grid[i][j] == 1) ? 1 : -1;
                rowcount[i] += diff;
                colcount[j] += diff;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = rowcount[i] + colcount[j];
            }
        } return move(grid);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> grid = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.onesMinusZeros(grid);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
