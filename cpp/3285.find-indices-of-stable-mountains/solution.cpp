// Created by oportunitas at 2026/09/27 14:17
// leetgo: 1.4.18
// https://leetcode.com/problems/find-indices-of-stable-mountains/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 28.8MB/0th%)
        we can just count
    */
    vector<int> stableMountains(vector<int>& height, int threshold) {
        auto result {[] () { vector<int> _; _.reserve(1 << 7); return _; } ()};
        for (auto i {1}; i < height.size(); ++i) {
            if (height[i - 1] > threshold) result.push_back(i);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> height = LeetCodeIO::deserialize<vector<int>>(cin);
		int threshold = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.stableMountains(height, threshold);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
