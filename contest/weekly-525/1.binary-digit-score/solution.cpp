// Created by oportunitas at 2026/10/25 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/binary-digit-score/
// https://leetcode.com/contest/weekly-contest-525/problems/binary-digit-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 {popcount((uint)a)}; int s2 {popcount((uint)b)};
        return (s1 >= s2) ? s1 * s2 : s2 / s1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int a = LeetCodeIO::deserialize<int>(cin);
		int b = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.calculateScore(a, b);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
