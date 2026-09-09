// Created by oportunitas at 2026/09/09 09:08
// leetgo: 1.4.18
// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 9.2MB/87th%)
		we iterate over the string characters and then keep tabs of the maximum
		frequency of both consonants and vowels along the way. then after we're 
		done we add them.
	*/
    int maxFreqSum(string s) {
		vector<int> count (26, 0);
		pair<int, int> result {0, 0};
		string vowels = "aiueo";
		for (auto c : s) {
			count[c - 'a'] += 1;
			if (vowels.contains(c)) {
				result.first = max(result.first, count[c - 'a']);
			} else {
				result.second = max(result.second, count[c - 'a']);
			}
		} return result.first + result.second;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.maxFreqSum(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
