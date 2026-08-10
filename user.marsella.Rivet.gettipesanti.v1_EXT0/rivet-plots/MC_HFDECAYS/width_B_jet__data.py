
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.06186357, 0.3697542, 0.3315072, 0.1702006, 0.0584204, 0.0080897, 0.0001643633],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.02142857, 0.021428575000000005, 0.021428555000000002, 0.021428599999999992, 0.02142855000000002, 0.02142860000000002, 0.02142854999999999],
        [0.02142857, 0.02142857499999999, 0.021428555000000002, 0.021428599999999992, 0.02142854999999999, 0.021428599999999992, 0.02142854999999999],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.000226439, 0.0005515092, 0.0005218233, 0.0003738767, 0.0002189975, 8.151156e-05, 1.156536e-05],
        [0.000226439, 0.0005515092, 0.0005218233, 0.0003738767, 0.0002189975, 8.151156e-05, 1.156536e-05],
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
        [0.0036602963585838965, 0.0014915562825249856, 0.001574093413355728, 0.0021966826203902922, 0.0037486477326413377, 0.010075968206484789, 0.0703646130249271],
        [0.0036602963585838965, 0.0014915562825249856, 0.001574093413355728, 0.0021966826203902922, 0.0037486477326413377, 0.010075968206484789, 0.0703646130249271],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}