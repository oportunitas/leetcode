# Created by oportunitas at 2026/10/08 07:23
# leetgo: 1.4.18
# https://leetcode.com/problems/remove-invalid-parentheses/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (128ms/43th% | 19.8mb/49th%)
        we golf
    '''
    def removeInvalidParentheses(self, s: str) -> list[str]:
        css = {s} # we use set for auto deduplication (css: cur_strings)

        # we iterate down, from the biggest string lengths possible to the smallest
        while True:
            # the valid strings is those who has the same number of open brackets as they have
            # close brackets, and one that in every subsequence never has more close brackets
            # than open ones
            valids = [cs for cs in css 
                      if cs.count('(') == cs.count(')')
                      and all(cs[:i].count('(') >= cs[:i].count(')') 
                              for i in range(len(cs)))]

            # if valids have any element (truthy), we return it, no need to go down since
            # this would mean we're shortening the string further
            if valids:
                return valids

            # this would mean that we're also storing cases where we're left with even more extras
            # but this wouldnt matter since in the next iteration, setting valids would eliminate
            # them, and it would be too much of a hassle to try to remove them now (when in python,
            # zen. when in cpp, optimize)
            css = {cs[:i] + cs[(i + 1):] for cs in css for i in range(len(cs))}

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().removeInvalidParentheses(s)
    print("\noutput:", serialize(ans, "string[]"))
