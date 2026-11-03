// Created by oportunitas at 2026/11/03 15:46
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-time-visiting-all-points/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 13.7MB/81th%)
        we can directly compare each pair of coordinates
    */
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans {0};
        for (const auto [prev, curr] : points | views::pairwise) {
            int dx = abs(curr[0] - prev[0]);
            int dy = abs(curr[1] - prev[1]);
            ans += min(dx, dy) + abs(dx - dy);
        } return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> points = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.minTimeToVisitAllPoints(points);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
