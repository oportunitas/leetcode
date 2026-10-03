# Created by oportunitas at 2026/10/03 11:07
# leetgo: 1.4.18
# https://leetcode.com/problems/longest-valid-parentheses/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (7ms/90th% | 20.3MB/78th%)
        this is a modification of the c++ version of the solution, where
        instead of defining 'last_l', we can assume that the array starts at -1
        index with '('

        the reasoning is, in the cpp version, we enter the "append" case where we're
        in the followign form:
            1       2
            ((..)(..)
        where section 1's index is opn.back(), and 2 is i

        notice that the opn.size() == 1 case is kind of similar, but
        we're compensating by setting a last_l variable to keep track of the last
        occurence of open bracket
            |last_l tries to remember this
            v 
            (..)(..)
        if we're to add just one more open bracket to the beginning of the sequence,
        we're back to the "append" case.

             |last_l tries to remember this
             v 
            ((..)(..)
            1
        this effectively means that we can just add an extra '(' at the array beginning
        to do the same process but with less conditions.
    '''
    def longestValidParentheses(self, s: str) -> int:
        opn, max_len = [-1], 0
        for i, c in enumerate(s):
            c == ')' and opn.pop()
            opn.append(i) if (c == '(' or not opn) else (max_len := max(max_len, i - opn[-1]))
        return max_len

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().longestValidParentheses(s)
    print("\noutput:", serialize(ans, "integer"))
