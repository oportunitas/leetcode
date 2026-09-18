# Created by oportunitas at 2026/09/19 05:57
# leetgo: 1.4.18
# https://leetcode.com/problems/display-the-first-three-rows/

# @lc code=begin

import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)

# @lc code=end
