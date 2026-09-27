// Created by oportunitas at 2026/09/26 19:41
// leetgo: 1.4.18
// https://leetcode.com/problems/count-of-matches-in-tournament/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 7.9MB/66th%)
            post-submission note: the analysis below is wayy too overblown. overthinking
            is dangerous sometimes. the number of matches is always n - 1.

            i've been reading cs:app intensely, and perhaps ive been too comfortable
            with finding out binary manipulation solutions, where the solution is just
            plain logic.

            the reason turns out to be way more intuitive:
                there should only be 1 champion and n - 1 losers.
                notice what this means, that in the entire tournament,
                there's n - 1 lose events, and only one champion event.

                that means, the number of matches is just n - 1

        if the team count is a power of 2, the number of matches is simply
        n - 1:
            2 teams: 1 match (2 - 1)
            4 teams: 3 match (4 - 1)
            8 teams: 7 match (8 - 1)
        if we were to represent the number of teams in binary, the sequence of
        the number of matches in each round is always a binary number with only one
        1:
            100->010->001
            4  ->2  ->1
        
        an odd number of teams in binary means the last digit is 1. in this case,
        at that instance, the number of matches increases by 1.
            in this representation, we can count how many times we'll encounter
            the odd number case by counting the number of 1 digits, since
            at some point every 1 digit will be at the leftmost position
            because we're right shifting along the way

        notice that we can go back to the definition of the number of matches 
        in the power of 2 case by utilizing this criteria:
            number_of_matches = team_number - number_of_binary_1s
            number_of_binary_1s is always 1

        lets assume that every match always have a power of 2 number of teams.
        we fill the remaining slots that's not filled with "ghost teams".

        the number of ghost teams is the difference between the current
        team count and the next nearest power of 2.


        0111
        1000 -> 7 matches here
        0001 -> minus 1, 6

        01110
        10000 -> 15 matches here
        00010 -> minus 2, 13

        10110 (22 teams)
         1011, 11 matches here
        01011 (11 teams remaining)
          101, 5 matches here, + 1
        00110 (6 teams remaining)
           11, 3 matches here
        00011 (3 teams remaining)
            1, 1 match here, + 1
        00010 (2 teams remaining)
            1, 1 match here
              (1 team remaining)
        11 + 5 + 3 + 1 + 1 = 21

        010110
        100000 -> 31 matches here
        001010 -> minus 10, 21

        a = (b - 1) - (b - n)
        a = b - 1 + b + n
        a = n - 1
    */
    int numberOfMatches(int n) {
        return n - 1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.numberOfMatches(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
