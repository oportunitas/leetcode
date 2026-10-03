// Created by oportunitas at 2026/10/03 12:33
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 11.4MB/99th%)
        this is beautiful: using count_if
    */
    int numOfStrings(vector<string>& patterns, string word) {
        return ranges::count_if(patterns, [&word] (const auto& pattern) {
            return word.contains(pattern);
        });
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> patterns = LeetCodeIO::deserialize<vector<string>>(cin);
		string word = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.numOfStrings(patterns, word);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
