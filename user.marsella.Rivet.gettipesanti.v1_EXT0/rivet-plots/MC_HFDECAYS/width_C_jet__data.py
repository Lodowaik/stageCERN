
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.02142857, 0.064285715, 0.107142845, 0.15, 0.19285714999999998, 0.2357143, 0.27857145],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.0, 0.04285714, 0.08571429, 0.1285714, 0.1714286, 0.2142857, 0.2571429, 0.3],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.1262147, 0.4262017, 0.2725036, 0.1199184, 0.0476915, 0.00731446, 0.0001556654],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.02142857, 0.021428575000000005, 0.021428555000000002, 0.021428599999999992, 0.02142855000000002, 0.02142860000000002, 0.02142854999999999],
        [0.02142857, 0.02142857499999999, 0.021428555000000002, 0.021428599999999992, 0.02142854999999999, 0.021428599999999992, 0.02142854999999999],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.0006317301, 0.001158817, 0.0009263352, 0.0006143277, 0.000387721, 0.0001515698, 2.201457e-05],
        [0.0006317301, 0.001158817, 0.0009263352, 0.0006143277, 0.000387721, 0.0001515698, 2.201457e-05],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
}
ratio0_yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.005005202246647973, 0.0027189403514814698, 0.003399350320509527, 0.005122881059120202, 0.008129771552582746, 0.020721939828777517, 0.14142237131694005],
        [0.005005202246647973, 0.0027189403514814698, 0.003399350320509527, 0.005122881059120202, 0.008129771552582746, 0.020721939828777517, 0.14142237131694005],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}