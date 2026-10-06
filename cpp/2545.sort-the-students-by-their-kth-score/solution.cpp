// Created by oportunitas at 2026/10/06 10:54
// leetgo: 1.4.18
// https://leetcode.com/problems/sort-the-students-by-their-kth-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 31.9MB/93th%)
        we can use std::ranges to expedite the whole process
    */
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        ranges::sort(score, ranges::greater(), [&k] (const auto& row) { return row[k]; });
        return score;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> score = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.sortTheStudents(score, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
