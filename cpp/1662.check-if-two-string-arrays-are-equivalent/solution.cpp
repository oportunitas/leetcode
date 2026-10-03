// Created by oportunitas at 2026/10/03 12:25
// leetgo: 1.4.18
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 15.3MB/14th%)
        we can use ranges::fold_left to fold each vectors to strings.
    */
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return (
            ranges::fold_left(word1, string{}, plus<>{}) == 
            ranges::fold_left(word2, string{}, plus<>{})
        );
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> word1 = LeetCodeIO::deserialize<vector<string>>(cin);
		vector<string> word2 = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.arrayStringsAreEqual(word1, word2);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
