// Created by oportunitas at 2026/10/04 07:20
// leetgo: 1.4.18
// https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 8.1MB/75th%)
        idea #0 works! and honestly in a production environment i would prefer idea #0 over
        what i'm going to do here:

        instead of storing the individual indeces of the open brackets and stars in a stack
        and trying to pop both whenever the star is after the open bracket afterwards,
        we can "dp" our way through this by doing this along the way in the for loop.

        the way we do that is by encoding the amount of stars and also where the stars
        begin by using two pointers method.

        this is going to be a bit trippy to explain, but ill try:
            we define 2 variables, each corresponding to 'l' and 'r' (bear with me).
            we initially set the variables at -1. whenever we encounter an open bracket,
            we add both pointers by 1, whenever we encounter a close bracket, we reduce
            both by 1.

            if we're just finding out whether a string is valid or not, this 2 pointers
            approach will simply work by checking whether the 2 values are equal to 0 at the end
            (if more, extra open brackets, if less, extra close brackets). we dont even need 2
            pointers in this case, only 1.

            now, the reason we need 2 pointers is because the distance between r and l will "encode"
            the amount of stars present in the string.

            whenever we encounter a star, instead of increasing both l and r by 1, we decrease
            r by 1 and increase l by 1. this, in effect, encodes the information of:
                "whatever happens here, can either move the number up (open bracket) or the
                number down (close bracket), or not move at all (empty string)"
            the range between l and r encodes the possible "timelines" that can happen

            so, if we're being fancy (and this is dp-ish after all), r and l encodes the length
            pointer at 2 different edge "universes". r is in the "universe" where the star becomes
            an open bracket, and l is in the "universe" where the star becomes a close bracket.

            now, a question that might appear is "but if we encounter * again, wouldnt that mean
            that we need to split each case into 3 again, creating 9 separate scenarios"?
            the answer is in theory yes, but remember that each "universe" can only move the pointer either left 1 index or right 1 index. 
            
            so in effect, we have universes where what happens is the l is always pushed left
            each time, where r is always pushed right each time, and also everything in between.
            we only need to keep track of the 2 "edge" "universes", and everything that's inside
            the range of the 2 edge universes can be valid.

            lets explore an example:
                *
                    in this case, 3 possible combinations are '(', ')', and ''
    */
    bool checkValidString(string s) {
        int l {0}; int r {0};

        for (const auto& c : s) {
            if (c == '(') {
                l += 1; r += 1;
            } else if (c == ')') {
                l -= 1; r -= 1;
            } else {
                l -= 1; r += 1;
            }

            // we need to discard any timelines that gets below 0, since it no longer can be
            // saved. if all timelines gets below 0, then none can be saved, hence return false

            if (r < 0) return false; //all timelines are compromised, none can be saved
            l = max(l, 0); //discard timelines that gets below 0 
        } 

        return (l == 0); //find if there's a timeline that has 0 as final state
    }

    // /* idea #0 (0ms/100th% | 8.6MB/15th%)
    //     we can have 2 stacks, one for the open brackets,
    //     one for the star symbol, and pop the star symbol bracket
    //     whenever need them if no open brackets are left

    //     afterwards, if there's remaining stars and open brackets, wherever stars
    //     have positions after the open bracket, we assume that its a close bracket instead
    // */
    // bool checkValidString(string s) {
    //     auto opens {[&s] () {vector<int> _; _.reserve(s.size()); return _;} ()};
    //     auto stars {[&s] () {vector<int> _; _.reserve(s.size()); return _;} ()};

    //     for (const auto& [i, c] : s | views::enumerate) {
    //         if (c == '(') {
    //             opens.push_back(i);
    //         } else if (c == '*') {
    //             stars.push_back(i);
    //         } else {
    //             if (!opens.empty()) {
    //                 opens.pop_back();
    //             } else if (!stars.empty()) {
    //                 stars.pop_back();
    //             } else {
    //                 return false;
    //             }
    //         }
    //     } 
        
    //     while ((!stars.empty() && !opens.empty()) && (stars.back() > opens.back())) {
    //         stars.pop_back();
    //         opens.pop_back();
    //     }
        
    //     return opens.empty();
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.checkValidString(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
