
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.6, 1.7999999999999998, 3.0, 4.2, 5.4],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.0, 1.2, 2.4, 3.6, 4.8, 6.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.8148692, 0.01642672, 0.001751908, 0.0002855261, 0.0],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.6, 0.6000000000000001, 0.6000000000000001, 0.5999999999999996, 0.5999999999999996],
        [0.6, 0.5999999999999999, 0.6000000000000001, 0.6000000000000001, 0.6000000000000005],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.003963927, 0.0005613846, 0.0001846062, 7.372273e-05, 0.0],
        [0.003963927, 0.0005613846, 0.0001846062, 7.372273e-05, 0.0],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 1.0, 1.0, 1.0, 1.0],
}
ratio0_yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.0048644948170823, 0.03417508790555875, 0.10537436897371323, 0.2581996181785132, 1.0],
        [0.0048644948170823, 0.03417508790555875, 0.10537436897371323, 0.2581996181785132, 1.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}