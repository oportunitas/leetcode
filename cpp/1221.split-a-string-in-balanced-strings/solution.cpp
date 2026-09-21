// Created by oportunitas at 2026/09/21 11:00
// leetgo: 1.4.18
// https://leetcode.com/problems/split-a-string-in-balanced-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 8.4MB/58th%)
		we can increment a counter by 1 whenever we find the r and l count to be the same.
	*/
    int balancedStringSplit(string s) {
        int result {0};
		int r_count {0};
		int l_count {0};

		for (auto&& c : s) {
			if (c == 'R') {
				r_count += 1;
			} else {
				l_count += 1;
			}

			if (r_count > 0 && (r_count == l_count)) {
				result += 1;
				r_count = 0;
				l_count = 0;
			}
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.balancedStringSplit(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
