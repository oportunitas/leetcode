// Created by oportunitas at 2026/11/15 19:26
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 112MB/74th%)
        instead of counting directly, we can create a prefix sum array first.
        an odd subarray means that it starts at an odd prefix sum and ends at an even prefix
        sum (or vice versa), so we can just count the odd prefix sum counts and even prefix
        sum counts, then multiply them
    */
    int numOfSubarrays(vector<int>& arr) {
        using i64 = std::int64_t;

        // directly find out count of odd prefix sums
        i64 odd_prefixes {0}; 
        i64 sum {0}; for (const auto& num : arr) {
            if ((sum += num) & 1) odd_prefixes += 1;
        } 
        
        // even prefix sums are the others
        i64 even_prefixes = ssize(arr) + 1 - odd_prefixes;

        // odd sums must mean it begins at even prefix sum and ends at odd prefix sums
        // (or vice versa)
        // so for each odd prefix sum it can choose between all the even prefix sums
        return (odd_prefixes * even_prefixes) % 1000000007;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> arr = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.numOfSubarrays(arr);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
