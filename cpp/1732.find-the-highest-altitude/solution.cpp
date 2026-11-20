// Created by oportunitas at 2026/11/20 14:15
// leetgo: 1.4.18
// https://leetcode.com/problems/find-the-highest-altitude/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 10.6MB/98th%)
        we can just add along the way and keep track of the max
    */
    int largestAltitude(vector<int>& gain) {
        int curh {0}; int maxh {0};
        for (const auto& diff : gain) {
            curh += diff;
            maxh = max(maxh, curh);
        } return maxh;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> gain = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.largestAltitude(gain);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
