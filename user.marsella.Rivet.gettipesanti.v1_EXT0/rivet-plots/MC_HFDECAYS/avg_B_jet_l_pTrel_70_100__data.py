
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.9375, 2.8125, 4.6875, 6.5625, 8.4375, 10.3125, 12.1875, 14.0625],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.0, 1.875, 3.75, 5.625, 7.5, 9.375, 11.25, 13.125, 15.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.5047358, 0.02563572, 0.002266927, 0.0005660779, 0.0001219672, 6.89219e-06, 0.0, 0.0],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.0009362572, 0.0002109741, 6.254626e-05, 3.121377e-05, 1.447493e-05, 3.44611e-06, 0.0, 0.0],
        [0.0009362572, 0.0002109741, 6.254626e-05, 3.121377e-05, 1.447493e-05, 3.44611e-06, 0.0, 0.0],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
}
ratio0_yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.0018549451019721605, 0.0082296927880317, 0.027590769354284454, 0.05514041441999414, 0.11867887432030907, 0.5000021763764493, 1.0, 1.0],
        [0.0018549451019721605, 0.0082296927880317, 0.027590769354284454, 0.05514041441999414, 0.11867887432030907, 0.5000021763764493, 1.0, 1.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}