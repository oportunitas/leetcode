// Created by oportunitas at 2026/09/20 13:51
// leetgo: 1.4.18
// https://leetcode.com/problems/add-two-integers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 8MB/69th%)
		this is trivial, just add the number
	*/
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int num1 = LeetCodeIO::deserialize<int>(cin);
		int num2 = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.sum(num1, num2);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
