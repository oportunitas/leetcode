# Created by oportunitas at 2026/10/06 09:09
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0
        we golf, using the same idea as the cpp logic
    '''
    def minAddToMakeValid(self, s: str) -> int:
        extras = [1 if (c == ')' and n < 0 and [(n := n + 1)]) else 0 
                  for i, c in enumerate(s)
                  if [n := (n if i else 0) + (-1 if c in ')' else 1), 1]] + [n]
        return sum(extras)

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().minAddToMakeValid(s)
    print("\noutput:", serialize(ans, "integer"))
