// Created by oportunitas at 2026/11/08 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/find-mismatched-segments-between-two-strings/
// https://leetcode.com/contest/weekly-contest-527/problems/find-mismatched-segments-between-two-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans; ans.push_back({"", ""});
        for (const auto& [c1, c2] : views::zip(s1, s2)) {
            if (c1 != c2) {
                ans.back()[0].push_back(c1);
                ans.back()[1].push_back(c2);
            } else {
                if (ans.back()[0].size() > 0) ans.push_back({"", ""});
            }
        }

        if (ans.back()[0].size() == 0) ans.pop_back();
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s1 = LeetCodeIO::deserialize<string>(cin);
		string s2 = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.findMismatchedSegments(s1, s2);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
