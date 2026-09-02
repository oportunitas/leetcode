// Created by oportunitas at 2026/09/02 08:54
// leetgo: 1.4.18
// https://leetcode.com/problems/convert-the-temperature/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (Runtime; 0ms/100th% | Memory: 8.3MB/76th%)
		this should be a trivial question, lets just do it 'verbatim'
	*/
    vector<double> convertTemperature(double celsius) {
        return {(celsius + 273.15), (celsius * 1.80 + 32.00)};
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		double celsius = LeetCodeIO::deserialize<double>(cin);

		Solution obj;
		auto res = obj.convertTemperature(celsius);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
