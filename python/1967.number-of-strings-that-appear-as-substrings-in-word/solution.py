# Created by oportunitas at 2026/10/03 13:00
# leetgo: 1.4.18
# https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.4MB/22nd%)
        we use sum() here
    '''
    def numOfStrings(self, patterns: list[str], word: str) -> int:
        return sum(pattern in word for pattern in patterns)

# @lc code=end

if __name__ == "__main__":
    patterns: List[str] = deserialize("List[str]", read_line())
    word: str = deserialize("str", read_line())
    ans = Solution().numOfStrings(patterns, word)
    print("\noutput:", serialize(ans, "integer"))
