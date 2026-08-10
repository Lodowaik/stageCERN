
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [45.0, 85.0, 125.0, 165.0, 205.0, 245.0, 285.0, 325.0, 365.0, 405.0],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [25.0, 65.0, 105.0, 145.0, 185.0, 225.0, 265.0, 305.0, 345.0, 385.0, 425.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.003793221, 0.0007072871, 0.0001527871, 4.488236e-05, 1.297919e-05, 3.886215e-06, 1.757298e-06, 4.413239e-07, 6.582328e-07, 0.0],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [2.90774e-05, 1.259273e-05, 5.871039e-06, 3.157772e-06, 1.68976e-06, 1.049446e-06, 6.213023e-07, 3.120632e-07, 3.800338e-07, 0.0],
        [2.90774e-05, 1.259273e-05, 5.871039e-06, 3.157772e-06, 1.68976e-06, 1.049446e-06, 6.213023e-07, 3.120632e-07, 3.800338e-07, 0.0],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
}
ratio0_yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.00766562243539198, 0.01780426929884625, 0.03842627420770471, 0.07035663900026648, 0.13018994251567317, 0.27004321685753363, 0.3535554584367591, 0.7071069570444747, 0.5773546988238812, 1.0],
        [0.00766562243539198, 0.01780426929884625, 0.03842627420770471, 0.07035663900026648, 0.13018994251567317, 0.27004321685753363, 0.3535554584367591, 0.7071069570444747, 0.5773546988238812, 1.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}