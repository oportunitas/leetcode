// Created by oportunitas at 2026/10/15 09:51
// leetgo: 1.4.18
// https://leetcode.com/problems/shuffle-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 18.8MB/48th%)
        we can do this verbatim
    */
    string restoreString(string s, vector<int>& indices) {
        string result(s.size(), 'x');
        for (const auto& [i, idx] : indices | views::enumerate) {
            result[idx] = s[i];
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		vector<int> indices = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.restoreString(s, indices);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
