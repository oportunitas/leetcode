// Created by oportunitas at 2026/10/03 07:04
// leetgo: 1.4.18
// https://leetcode.com/problems/longest-valid-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 12.2MB/10th%)
        lets now lean down idea #0, given we aready get the general idea of what the solution 
        should be.

        one thing i noticed is that not every variable in the 'lr' variables are needed, just last l
        instead of storing the exact left and right values in a stack, we can trace back as such
        instead:
            - the stack opn now stores the index of every pushed open bracket
            - whenever we get a close bracket, we pop from the stack, and we know also which
            index is the popped open bracket by calling it before pop.

        one thing that flew above my head is that whenever we are popping from the array, if we
        know the index of the opening bracket, we know for "that" specific popping instance, what
        the length of that subsequence is (because we know the current close bracket value, which
        is just i, and also the opening bracket value, which is the value of opn.back()).

        this means, we dont need all the redundant calculations in idea #0, keeping track of
        the current and or last subsequences is unnecessary, since whenever we "can" pop from
        the opn stack, it's always a valid subsequence, and therefore we only need to check
        whether that specific subsequence's length is bigger and or smaller than the max so far.

        also, the "current subsequence is immediately after last subsequence" case only might
        happen whenever the current stack is just emptied. 

        mb vro i was overthinking 🥀.
    */
    int longestValidParentheses(string s) {
        auto opn {[&s] () {vector<int64_t> _; _.reserve(s.size()); return _;} ()};
        int64_t last_l {-1};
        int64_t max_len {0};
        for (const auto& [i, c] : s | views::enumerate) {
            // println("c: {}", c);
            if (c == '(') {
                opn.push_back(i);
            } else {
                if (opn.empty()) /*extra close bracket case, last MUST move*/ {
                    last_l = i;
                } else if (opn.size() == 1) /*just enough open bracket case, encapsulate case*/ {
                    opn.pop_back();

                    // no need for - 1 since last_l is already offset by -1
                    max_len = max(max_len, i - last_l);
                } else /*extra open bracket case, append case*/ {
                    opn.pop_back();
                    max_len = max(max_len, i - opn.back());
                }
            }
        } return max_len;
    }

    // /* idea #0 (0ms/100th% | 12.7MB/8th%)
    //     wow this is surely hard, the main high level idea is this:
    //         find all subsequences that are valid, and then, evaluate whether each new subsequence
    //         via a stack. depending on the current subsequence's behavior: 
    //             - encapsulates the previous subsequence
    //                 - in this case we reassume the last subsequence as this subsequence instead
    //             - is immediately after the previous subsequence
    //                 - in this case we reassume the last subsequence as this + last
    //             - is disconnected from the the previous subsequence
    //                 - in this case we add this new subsequence to the stack we keep track of
    //         in any case, we keep track of the biggest subsequence by length so far.

    //         the exact way to find whether a subsequence is valid is abstracted in the explanation
    //         above, but its generally similar to the "finding valid subsequence" problem, the 
    //         difference is now we keep track of the indexes of the beginning and the end of the
    //         valid subsequence for asking the question/s in the above paragraph.
    // */
    // int longestValidParentheses(string s) {
    //     auto opn {[&s] () {vector<int64_t> _; _.reserve(s.size()); return _;} ()};
    //     // auto cls {[&s] () {string _; _.reserve(s.size()); return _;} ()};
    //     typedef struct {int64_t l; int64_t r;} lr;
    //     vector<lr> valids;
    //     // lr last = {INT_MIN, INT_MIN};
    //     lr curr = {0, 0};
    //     int64_t max_len {0};

    //     // println("---");
    //     for (int i {0}; i < s.size();) {
    //         // append all opening brackets here
    //         while ((s[i] == '(') && (i < s.size())) {
    //             opn.push_back(i);
    //             curr = {i, i};
    //             i += 1;
    //         }

    //         // the next encounter here should be a ')', pop all thats possible from the stack
    //         curr.l += 1;
    //         while ((s[i] == ')') && (i < s.size())) {
    //             if (!opn.empty()) {
    //                 curr.r = i;
    //                 curr.l = opn.back();
    //                 opn.pop_back();
    //             } i += 1;
    //         }

    //         // println("curr: {}->{}", curr.l, curr.r);
    //         // if current sequence is immediately after last sequence, last sequence is
    //         // now <last_sequence>-><cur_sequence>
    //         while (true) {
    //             if (!valids.empty()) {
    //                 lr& last = valids.back();
    //                 // println("_last: {}->{}", last.l, last.r);
    //                 if (last.r + 1 == curr.l) /* if current is immediately after last, break case*/ {
    //                     last.r = curr.r;
    //                     break;
    //                 } else if (curr.l <= last.l && curr.r >= last.r) 
    //                 /* else if current encapsulates last, pop and test again with 2nd last*/ {
    //                     valids.pop_back();
    //                 } else /* else if current and last are disconnected, push curr to valids*/ {
    //                     valids.push_back(curr);
    //                     break;
    //                 }
    //             } else /* else if no valids, push*/ {
    //                 valids.push_back(curr);
    //                 break;
    //             }
    //         }

    //         lr& last = valids.back();
    //         // println("last: {}->{}", last.l, last.r);
    //         max_len = max(max_len, (last.r - (last.l - 1)));
    //         // println("max_len: {}", max_len);
    //         // println("---");
    //     }

    //     return max_len;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.longestValidParentheses(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
