
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.3457678, 0.07616408, 0.03163517, 0.019932, 0.01280209, 0.00837894, 0.007615652, 0.005185722],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.00476435, 0.002233661, 0.001451803, 0.001141098, 0.0009230799, 0.0007376218, 0.0007039531, 0.0005903142],
        [0.00476435, 0.002233661, 0.001451803, 0.001141098, 0.0009230799, 0.0007376218, 0.0007039531, 0.0005903142],
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
        [0.013779044780919448, 0.029326960950621345, 0.04589205621464971, 0.05724954846478025, 0.07210384398172485, 0.08803282992836803, 0.09243504036161317, 0.1138345248742605],
        [0.013779044780919448, 0.029326960950621345, 0.04589205621464971, 0.05724954846478025, 0.07210384398172485, 0.08803282992836803, 0.09243504036161317, 0.1138345248742605],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}