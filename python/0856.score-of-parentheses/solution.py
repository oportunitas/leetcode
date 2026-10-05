# Created by oportunitas at 2026/10/05 09:53
# leetgo: 1.4.18
# https://leetcode.com/problems/score-of-parentheses/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.2MB/56th%)
        we go golfing, this is the same logic as the cpp solution but "golfed"
    '''
    def scoreOfParentheses(self, s: str) -> int:
        return sum(
            (1 << d) if s[i-1:i+1] == "()" else 0 
            for i, c in enumerate(s)
            if (d := 1 if not i else d + (1 if c == '(' else -1)) or True
        )

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().scoreOfParentheses(s)
    print("\noutput:", serialize(ans, "integer"))
