// Created by oportunitas at 2026/09/02 08:05
// leetgo: 1.4.18
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0
		this sounds the most obvious (and might be already fast enough if compilation 
		auto-vectorizes the loop):
			we just loop over each element of the array, increasing and decreasing based
			on the middle character of the string (this will always either be + or -)
	*/
    int finalValueAfterOperations(vector<string>& operations) {
		int result = 0;
		for (auto operation : operations) {
			switch (operation[1]) {
				case '-':
					result -= 1;
					break;
				case '+':
					result += 1;
					break;
				default:
					// just to check in case this case ever gets entered, 
					// intuitively it should have never enter this case
					return INT_MIN;
			}
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> operations = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.finalValueAfterOperations(operations);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
