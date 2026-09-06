// Created by oportunitas at 2026/09/06 18:22
// leetgo: 1.4.18
// https://leetcode.com/problems/transform-array-by-parity/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 28.3MB/26th%)
		we can just simply count and append.
	*/
    vector<int> transformArray(vector<int>& nums) {
        auto result {[&nums] () {vector<int> _; _.reserve(nums.size()); return _;} ()};
		int odd_count {0};
		ranges::for_each(nums, [&odd_count] (int num) {
			if (num % 2) odd_count += 1;
		});

		result.insert(result.end(), nums.size() - odd_count, 0);
		result.insert(result.end(), odd_count, 1);
		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.transformArray(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
