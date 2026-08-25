// Created by oportunitas at 2026/08/25 12:15
// leetgo: 1.4.18
// https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	int fib(int n) {
		constexpr int tc_size = 31;

		static constexpr auto lookup = [] {
			array<int, tc_size> arr { };
			for (auto [i, num] : arr | views::enumerate) {
				if (i < 2) { num = i; } else { num = arr[i - 1] + arr[i - 2]; }
			} return arr;
		} (); // () because IIFE;

		return lookup[n];
	}
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.fib(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
