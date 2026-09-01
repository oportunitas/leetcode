// Created by oportunitas at 2026/09/01 09:01
// leetgo: 1.4.18
// https://leetcode.com/problems/score-of-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0
		just do it as is.
	*/
    int scoreOfString(string s) {
		int result = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
			result += abs(s[i] - s[i + 1]);
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.scoreOfString(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
