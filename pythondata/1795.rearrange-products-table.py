# Created by oportunitas at 2026/10/14 11:34
# leetgo: 1.4.18
# https://leetcode.com/problems/rearrange-products-table/

# @lc code=begin

import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    return pd.melt(products, id_vars=['product_id']).dropna().rename(columns={'variable': 'store', 'value': 'price'})

# @lc code=end
