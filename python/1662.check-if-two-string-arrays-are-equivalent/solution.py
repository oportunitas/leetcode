# Created by oportunitas at 2026/10/03 12:31
# leetgo: 1.4.18
# https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.2MB/89th%)
        we can use .join() method to combine elements of the array to a single string
    '''
    def arrayStringsAreEqual(self, word1: list[str], word2: list[str]) -> bool:
        return "".join(word1) == "".join(word2)
        

# @lc code=end

if __name__ == "__main__":
    word1: List[str] = deserialize("List[str]", read_line())
    word2: List[str] = deserialize("List[str]", read_line())
    ans = Solution().arrayStringsAreEqual(word1, word2)
    print("\noutput:", serialize(ans, "boolean"))
