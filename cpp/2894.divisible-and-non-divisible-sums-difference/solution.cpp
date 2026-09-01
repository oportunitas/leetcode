// Created by oportunitas at 2026/09/01 16:38
// leetgo: 1.4.18
// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0
		num1 + num2 is always (n * (n + 1) / 2)

		we can just find num2, and then do (n * (n + 1) / 2) - (2 * num2)
	*/
    int differenceOfSums(int n, int m) {
		int sum {n * (n + 1) / 2};
		int num2 {0};
		for (int i = 1; i <= n; ++i) {
			if (i % m == 0) {num2 += i;}
		}

		return sum - (2 * num2);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		int m = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.differenceOfSums(n, m);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
