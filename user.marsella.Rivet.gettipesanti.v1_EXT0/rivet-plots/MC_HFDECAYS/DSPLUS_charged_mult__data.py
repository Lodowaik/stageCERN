
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.4140952, 0.0, 0.467883, 0.0, 0.113564, 0.0, 0.004422469, 0.0, 3.528919e-05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
        [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.001922634, 0.0, 0.002041751, 0.0, 0.001005983, 0.0, 0.0002012891, 0.0, 1.764471e-05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
        [0.001922634, 0.0, 0.002041751, 0.0, 0.001005983, 0.0, 0.0002012891, 0.0, 1.764471e-05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
}
ratio0_yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.004642975818121051, 1.0, 0.004363806763656726, 1.0, 0.008858291359938009, 1.0, 0.04551509575307368, 1.0, 0.5000032587883145, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        [0.004642975818121051, 1.0, 0.004363806763656726, 1.0, 0.008858291359938009, 1.0, 0.04551509575307368, 1.0, 0.5000032587883145, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}