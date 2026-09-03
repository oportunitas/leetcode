// Created by oportunitas at 2026/09/03 12:47
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #1 (0ms/100th% | 12.2MB/53th%)
		idea #0 wasn't very time-efficient.

		lets introduce some efficiencies:
			- first, we notice that if we've calculated case i - j, we no longer need to do
			j - i (if the indeces of the string and result is swapped). but we do it nonetheless
			in idea #0.

			- to remove this redundancy, instead of looping over the result vector in every
			index of boxes. we can just do them twice overall. the following is the logic:
				lets assume we only are able to move the balls to the left, and only care about balls to the right (assume all balls to the left of ith box is 0/ignore them):
					input: " 1  1  0"
					output: [1, 0, 0]
				
					input: " 0   0  1  0  1  1"
					output: [11, 8, 5, 3, 1, 0]
				if we read from right to left, notice the amount in an index is equal to the amount in its previous index, plus the amount of balls we've seen so far. using this, we discover a shorthand technique to calculating the number of movements to the left!

				we can do the same with movements to the right only, now we only care about balls
				to the left.
					input: " 1  1  0"
					output: [0, 1, 3]

					input: " 0  0  1  0  1  1"
					output: [0, 0, 0, 1, 2, 4]
				
				notice that when we add the ith index of the outputs from the right-moves and 
				left-moves result, we end up with the true output!

			the above method made the calculation way simpler! we reduced the amount of calculations
			from (boxes.size() ^ 2) to (2 * boxes.size())! (O(n^2) to O(n))


	*/
	vector<int> minOperations(string boxes) {
        vector<int> result ((int)boxes.size(), 0);

		// first we add the left-movements by reading from right to left
		for (int i {(int)boxes.size() - 1}, ball_count {0}, last_val {0}; i >= 0; --i) {
			if (i < boxes.size() - 1) {
				last_val = last_val + ball_count;
				result[i] += last_val;
			}
			if (boxes[i] == '1') ball_count += 1;
		}

		// then we add the right-movements by reading from left to right
		for (int i {0}, ball_count {0}, last_val {0}; i < boxes.size(); ++i) {
			if (i > 0) {
				last_val = last_val + ball_count;
				result[i] += last_val;
			}
			if (boxes[i] == '1') ball_count += 1;
		}

		return result;
    }

	// /*idea #0 (Runtime: 52ms/57th% | Memory: 12.2/67th)
	// 	lets do the most straightforward (imo) approach first:
	// 		- we create the vector of all 0s to work on the answer vector
	// 		- loop over "boxes":
	// 			- whenever we encounter a '1' in ith index, loop over the result vector:
	// 				- add result[j] with the difference of i
			
	// 		this nested loop may look time-consuming, however, we are using O2 compilation
	// 		optimization, which, ((as far as i know)), has a very high chance of auto-vectorization (fingers crossed), which means at least the very inner loop over the result vector can be auto-vectorized, thus reduced from O(n) to best case O(1) worst case O(n/c).
	// */
    // vector<int> minOperations(string boxes) {
    //     vector<int> result ((int)boxes.size(), 0);
	// 	// println("initialized result: {}", result);
	// 	for (auto [i, c] : boxes | views::enumerate) {
	// 		if (c == '1') {
	// 			for (auto [j, num] : result | views::enumerate) {
	// 				num += abs(i - j);
	// 			}
	// 		}
	// 	} return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string boxes = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minOperations(boxes);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
