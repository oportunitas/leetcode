# Created by oportunitas at 2026/09/22 10:40
# leetgo: 1.4.18
# https://leetcode.com/problems/change-data-type/

# @lc code=begin

import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students["grade"] = students["grade"].astype(int)
    return students

# @lc code=end
