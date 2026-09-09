// Created by oportunitas at 2026/09/09 09:38
// leetgo: 1.4.18
// https://leetcode.com/problems/richest-customer-wealth/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #2 (0ms/100th% | 11.3MB/82th%)
        perhaps idea #0 is already near perfect, and we only need
        to make sure there's no reallocations?
    */
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        //change 'auto account' to 'auto& account' to prevent heap allocation
		ranges::for_each(accounts, [&result] (const auto& account) {
			result = max(
				result, 
				reduce(account.begin(), account.end(), 0, plus<int>())
			);
		}); return result;
    }

	// /* idea #1 (0ms/100th% | 11.1MB/98th%)
	// 	idea #0 is very good runtime-wise, but is very memory-
	// 	inneficient. lets do traditional loops and see if we can
	// 	reduce memory.
	// */
    // int maximumWealth(vector<vector<int>>& accounts) {
    //     int result = 0;
	// 	for (int i {0}; i < accounts.size(); ++i) {
	// 		int total_wealth = 0;
	// 		for (int j {0}; j < accounts[0].size(); ++j) {
	// 			total_wealth += accounts[i][j];
	// 		} result = max(total_wealth, result);
	// 	} return result;
    // }

	// /* idea #0 (0ms/100th% | 11.9MB/7th%)
	// 	lets try to do brute force iteration and see how
	// 	good the code is compared to other leetcode submissions.

	// 	lets hope that some part of this is auto-vectorized by
	// 	GCC14's -O2 compilation flag.
	// */
    // int maximumWealth(vector<vector<int>>& accounts) {
    //     int result = 0;
	// 	ranges::for_each(accounts, [&result] (auto account) {
	// 		result = max(
	// 			result, 
	// 			reduce(account.begin(), account.end(), 0, plus<int>())
	// 		);
	// 	}); return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> accounts = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.maximumWealth(accounts);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
