// Created by oportunitas at 2026/11/19 15:48
// leetgo: 1.4.18
// https://leetcode.com/problems/matrix-diagonal-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 14.7MB/98th%)
        we can just implement it verbatim. and to slightly optimize,
        do it directly per row (i and opposite - i in column per row)
    */
    int diagonalSum(vector<vector<int>>& mat) {
        int opp = ssize(mat) - 1; //square matrix, so no need for row/col wise
        int result {0};
        for (int i = 0; i < mat.size(); ++i) {
            result += mat[i][i];
            if (opp - i != i) {
                result += mat[i][opp-i];
            }
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> mat = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.diagonalSum(mat);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
