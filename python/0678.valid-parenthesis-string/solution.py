# Created by oportunitas at 2026/10/04 08:43
# leetgo: 1.4.18
# https://leetcode.com/problems/valid-parenthesis-string/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.2MB/90th%)
        we listify/serialize the cpp implementation
    '''
    def checkValidString(self, s: str) -> bool:
        l = r = 0
        return all((r := r + (1 if c in '(*' else -1)) >= 0 and
                   (l := max(0, (l + (1 if c in '(' else -1)))) >= 0
                   for c in s) and l == 0
    
        # for c in s:
        #     if c == '(':
        #         l += 1
        #         r += 1
        #     elif c == ')':
        #         l -= 1
        #         r -= 1
        #     else:
        #         l -= 1
        #         r += 1

        #     if r < 0:
        #         return False
        #     l = max(0, l)
        # return l == 0
            

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().checkValidString(s)
    print("\noutput:", serialize(ans, "boolean"))
