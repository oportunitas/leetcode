// Created by oportunitas at 2026/09/26 19:35
// leetgo: 1.4.18
// https://leetcode.com/problems/find-center-of-star-graph/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 99.1MB/87th%)
        the center of the star graph is the only number that appears more than once.
        we can just check the first 2 edges and find a common node
    */
    int findCenter(vector<vector<int>>& edges) {
        int from_0 {edges[0][0]};
        int to_0 {edges[0][1]};
        int from_1 {edges[1][0]};
        int to_1 {edges[1][1]};

        if (from_0 == to_1 || from_0 == from_1) return from_0;
        else return to_0;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> edges = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.findCenter(edges);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
