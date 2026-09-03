// Created by oportunitas at 2026/09/03 13:39
// leetgo: 1.4.18
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (0ms/100th% | 9.1MB/90th%)
		lets find patterns here, since i am suspicious that the answer is O(n) time:
			[5, 1, 6]:
				5 -> 5
				1 -> 1
				6 -> 6
			total: 12

				5, 1 -> 4
				5, 6 -> 3
				1, 6 -> 7
			total = 14

			    5, 1, 6 -> 2
			total = 2

			lets explore binary representations
			[101, 001, 110]:
				101 -> 101
				001 -> 001
				110 -> 110
			total =   1100

				101, 001 -> 100
				101, 110 -> 011
				001, 110 -> 111
			total =        1110

			    101, 001, 110 -> 010
						    010
						   1110
						   1100
			grand total = 11100
			
		hmm, there seems to be no indication of O(n) solutions here (yet?),
		we can approach this problem with graph optimizations, but hmm, is it too far for
		an easy problem?

			lets tackle this with statistics/probabilities:
				a similar problem is finding the sum of subset sums.
				this problem has the O(n) solution of :
					<sum of array> * 2^(array size - 1)
				we know this, because if we were using statistics, each index appears
				exactly 2^(array size - 1) times:
				5   1   6    12
			    5   1         6
				5       6    11
				    1   6     7
				5             5
				    1         1
				        6     6

			    20  4   24   48
				in the case of [5, 1, 6], there is (2^3 - 1) possible subsets, and each number
				will only appear (2^2) times to "give space" for subsets without it.

			lets use binary to find out if this property kind of exists for xor
			    101    001    110      0010
				101    001             0100
				101           110      0011
				       001    110      0111
				101                    0101
				       001             0001
					          110      0110
									  11100

			  10100  00100  11000     01000

			    001    011       010   sum = 100
				001              001
				       011       011
								 110

				010    000       010

			an interesting pattern emerges: the number of 1s in indexes where numbers have 1s
			repeats n - 1 times down! if we were to do or over every array element, and then
			shift them by the amount n - 1, we might arrive at a possible solution!
					5, 1, 6 case: (5 or 1 or 6) << 2
					1, 3 case	: (1 or 3) << 1
			lets test this with a possible breaking case:
					1, 6 ()
				001   110      111
				001            001
				      110      110
					          1110
			huh, this still follows the rule! lets try to submit with this rule in mind
	*/ 
    int subsetXORSum(vector<int>& nums) {
		// println("---");
		// println("sum: {:07b}", reduce(nums.begin(), nums.end(), 0, plus<>()));
		// println("xor: {:07b}", reduce(nums.begin(), nums.end(), 0, bit_xor<>()));

        return (reduce(nums.begin(), nums.end(), 0, bit_or<>())) << (nums.size() - 1);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.subsetXORSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
