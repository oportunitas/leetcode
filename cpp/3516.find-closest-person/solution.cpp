// Created by oportunitas at 2026/09/09 12:18
// leetgo: 1.4.18
// https://leetcode.com/problems/find-closest-person/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 8.6MB/19th%)
		we just find whichever has the lowest absolute difference.
	*/
    int findClosest(int x, int y, int z) {
		int p1_dist {abs(x - z)};
		int p2_dist {abs(y - z)};
		if (p1_dist == p2_dist) return 0;
		if (p1_dist < p2_dist) return 1;
		return 2;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int x = LeetCodeIO::deserialize<int>(cin);
		int y = LeetCodeIO::deserialize<int>(cin);
		int z = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.findClosest(x, y, z);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
