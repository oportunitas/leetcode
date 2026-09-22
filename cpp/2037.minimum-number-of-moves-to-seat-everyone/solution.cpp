// Created by oportunitas at 2026/09/22 11:03
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 21.8MB/29th%)
		the most straightforward approach here is to sort both the seats and students array,
		and then calculate the sum of each index.
	*/
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		ranges::sort(seats); ranges::sort(students);
		// println(" - ");
		// println("{}", seats);
		// println("{}", students);

		int result {0};
		for (int i {0}; i < seats.size(); ++i) {
			result += abs(seats[i] - students[i]);
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> seats = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> students = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minMovesToSeat(seats, students);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
