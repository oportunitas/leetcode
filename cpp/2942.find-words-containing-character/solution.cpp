// Created by oportunitas at 2026/09/02 08:59
// leetgo: 1.4.18
// https://leetcode.com/problems/find-words-containing-character/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (Runtime: 0ms/100th% | Memory: 33.2MB/26th%)
		we're using cpp23, so lets utilize the modern language to initialize and loop
	*/
    vector<int> findWordsContaining(vector<string>& words, char x) {
		auto result {[&words] () {vector<int> _; _.reserve(words.size()); return _;} ()};
		for (auto [i, word] : words | views::enumerate) {
			if (word.contains(x)) result.push_back(i);
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> words = LeetCodeIO::deserialize<vector<string>>(cin);
		char x = LeetCodeIO::deserialize<char>(cin);

		Solution obj;
		auto res = obj.findWordsContaining(words, x);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
