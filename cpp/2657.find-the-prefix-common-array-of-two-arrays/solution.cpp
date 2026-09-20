// Created by oportunitas at 2026/09/20 13:14
// leetgo: 1.4.18
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 85.54MB/96.65th%)
		1, 3, 2, 4
		3, 1, 2, 4
		0, 2, 3, 4

		we create maps for each A and B unique numbers, and then a sum that we add
		along the way based on the number of common numbers we've found 
	*/
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
		bitset<51> in_a {0};
		bitset<51> in_b {0};
		auto result {[&A] () { vector<int> _; _.reserve(A.size() + 1); return _; } ()};
		int count = 0;

		for (int i = 0; i < A.size(); ++i) {
			// we use A as anchor
			if (!in_a[A[i]]) {
				// add the number into the A list first
				in_a[A[i]] = 1;
				if (in_b[A[i]]) {
					count += 1;
				}
			} 
			// then we use B as anchor
			if (!in_b[B[i]]) {
				// add the number to B list
				in_b[B[i]] = 1;
				if (in_a[B[i]]) {
					count += 1;
				}
			}
			result.push_back(count);
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> A = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> B = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.findThePrefixCommonArray(A, B);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
