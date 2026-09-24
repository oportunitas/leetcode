// Created by oportunitas at 2026/09/24 18:41
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 13MB/80th%)
        perhaps we only need to justadd the number of spaces? (+1)? the words are only 
        separated by a single space though
    */
    int mostWordsFound(vector<string>& sentences) {
        int result {0};
        for (const auto& sentence : sentences) {
            int nof_words {1};
            for (const auto& c : sentence) {
                if (c == ' ') nof_words += 1;
            } result = max(result, nof_words);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> sentences = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.mostWordsFound(sentences);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
