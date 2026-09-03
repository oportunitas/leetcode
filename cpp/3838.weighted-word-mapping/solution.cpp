// Created by oportunitas at 2026/09/02 12:31
// leetgo: 1.4.18
// https://leetcode.com/problems/weighted-word-mapping/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (Runtime: 0ms/100th% | Memory: 43.9MB/17th%)
		lets start with the most straightforward approach: do for loops
	*/
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
		string result (words.size(), ' ');
        for (auto [i, word] : words | views::enumerate) {
			int total = 0;
			for (auto [j, letter] : word | views::enumerate) {
				total += weights[letter - 'a'];
			}
			total = (26 - (total % 26));
			result[i] = total + 'a' - 1;
			// for (auto res : result) {
			// 	println("-: {}", res);
			// } println("---");
		} 
		// println("result: {}", result);

		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> words = LeetCodeIO::deserialize<vector<string>>(cin);
		vector<int> weights = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.mapWordWeights(words, weights);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
