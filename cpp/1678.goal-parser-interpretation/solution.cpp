// Created by oportunitas at 2026/09/20 13:39
// leetgo: 1.4.18
// https://leetcode.com/problems/goal-parser-interpretation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 8.1MB/77th%)
		we can just check for specific characters and then append to a result string.
	*/
    string interpret(string command) {
        auto result {[&command] () { string _; _.reserve(command.size() + 1); return _;} ()};
		for (int i {0}; i < command.size(); ++i) {
			if (command[i] == 'G') {
				result.append("G");
			} else if (command[i] == '(') {
				continue;
			} else if (command[i] == 'a') {
				result.append("al");
				i += 2;
			} else if (command[i] == ')') {
				result.append("o");
			}
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string command = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.interpret(command);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
