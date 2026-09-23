// Created by oportunitas at 2026/09/23 09:24
// leetgo: 1.4.18
// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (4ms/100th% | 20.4MB/43th%)
        lets do the most straightforward approach first. do a nested loop
    */
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        // println("---");
        vector<int> point_count (queries.size(), 0);
        for (const auto& [i, query] : queries | views::enumerate) {
            int x0 = query[0];
            int y0 = query[1];
            int r  = query[2];
            // println("{}", query);
            for (const auto& point : points) {
                int x1 = point[0];
                int y1 = point[1];

                // using dx/dy to denote difference might be blasphemous, but i cant exactly
                // use the delta symbol either, so this will do
                int dx = x1 - x0;
                int dy = y1 - y0;

                // println("   {}", point);
                point_count[i] += ((dx * dx) + (dy * dy) <= r * r);
            }
        }
        return point_count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> points = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		vector<vector<int>> queries = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.countPoints(points, queries);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
