// Created by oportunitas at 2026/10/04 17:37
// leetgo: 1.4.18
// https://leetcode.com/problems/sum-multiples/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8.5MB/83th%)
        lets utilize modern functional cpp here
    */
    int sumOfMultiples(int n) {
        return ranges::fold_left(views::iota(0, n + 1) | views::filter([] (const int& i) {
            return (i % 3 == 0 || i % 5 == 0 || i % 7 == 0);
        }), 0, plus<>());
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.sumOfMultiples(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
