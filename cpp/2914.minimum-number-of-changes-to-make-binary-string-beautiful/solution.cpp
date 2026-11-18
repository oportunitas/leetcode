// Created by oportunitas at 2026/11/18 09:21
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 13.6MB/75th%)
        we can simply find the positions where
        the index is odd and it flips bits. we only
        need to correct these bits, as such we just count
        the occurence count
    */
    int minChanges(string s) {
        int result {0};
        for (int i = 1; i < ssize(s); i += 2) {
            if (s[i] != s[i-1]) result += 1;
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minChanges(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
