// Created by oportunitas at 2026/10/18 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-interval-selection-to-cover-target-intervals/
// https://leetcode.com/contest/weekly-contest-524/problems/minimum-interval-selection-to-cover-target-intervals/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> availableIntervals = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		vector<vector<int>> targetIntervals = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.minSelection(availableIntervals, targetIntervals);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
