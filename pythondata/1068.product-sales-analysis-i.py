# Created by oportunitas at 2026/10/02 06:04
# leetgo: 1.4.18
# https://leetcode.com/problems/product-sales-analysis-i/

# @lc code=begin

import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    return sales.merge(product, on='product_id', how='left')[['product_name', 'year', 'price']]
    

# @lc code=end
