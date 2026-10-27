// Created by oportunitas at 2026/10/27 07:04
// leetgo: 1.4.18
// https://leetcode.com/problems/create-grid-with-exactly-one-path/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 10.9MB/99th%)
        the solution for this problem should be trivial
    */
    vector<string> createGrid(int m, int n) {
        vector<string> grid (m, string(n, '#'));
        for (size_t col {0}; col < n; ++col) {
            grid[0][col] = '.';
        } for (size_t row {1}; row < m; ++row) {
            grid[row][n-1] = '.';
        } return grid;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int m = LeetCodeIO::deserialize<int>(cin);
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.createGrid(m, n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
