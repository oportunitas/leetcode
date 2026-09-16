// Created by oportunitas at 2026/09/16 12:13
// leetgo: 1.4.18
// https://leetcode.com/problems/smallest-even-multiple/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 7.8MB/64th%)
		this should be trivial: if even return n, else return 2*n
	*/
    int smallestEvenMultiple(int n) {
		return (n % 2) ? 2 * n : n;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.smallestEvenMultiple(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
