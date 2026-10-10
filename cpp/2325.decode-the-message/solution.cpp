// Created by oportunitas at 2026/10/10 06:56
// leetgo: 1.4.18
// https://leetcode.com/problems/decode-the-message/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 9.4MB/96th%)
        we'll create a map
    */
    string decodeMessage(string key, string message) {
        array<int, 26> map; ranges::fill(map, -1);
        for (int counter {0}; const auto& c: key) {
            if (c != ' ' && map[c - 'a'] == -1) map[c - 'a'] = counter++;
            if (counter >= 26) break;
        } for (auto& c: message) {
            if (c != ' ') c = map[c - 'a'] + 'a';
        } return message;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string key = LeetCodeIO::deserialize<string>(cin);
		string message = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.decodeMessage(key, message);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
