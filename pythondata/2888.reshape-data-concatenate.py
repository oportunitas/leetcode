# Created by oportunitas at 2026/09/19 06:37
# leetgo: 1.4.18
# https://leetcode.com/problems/reshape-data-concatenate/

# @lc code=begin

import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2])

# @lc code=end
