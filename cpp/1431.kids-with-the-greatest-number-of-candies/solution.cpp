// Created by oportunitas at 2026/09/20 13:53
// leetgo: 1.4.18
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 12.6MB/26th%)
		we find the maximum value in the array first, then we set the vector
		according to whether each index after extraCandies is bigger and or equal to max.
	*/
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max {ranges::max(candies)};
		auto result {[&candies] () { vector<bool> _; _.reserve(candies.size()); return _; } ()};

		ranges::for_each(candies, [&result, &max, &extraCandies] (auto&& candy) {
			result.push_back((candy + extraCandies) >= max);
		});

		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> candies = LeetCodeIO::deserialize<vector<int>>(cin);
		int extraCandies = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.kidsWithCandies(candies, extraCandies);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
