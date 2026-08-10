
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.7918479, 0.03205714, 0.005191859, 0.002720831, 0.001373483],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.6, 0.6000000000000001, 0.6000000000000001, 0.5999999999999996, 0.5999999999999996],
        [0.6, 0.5999999999999999, 0.6000000000000001, 0.6000000000000001, 0.6000000000000005],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.004354657, 0.0008777261, 0.0003524784, 0.0002537205, 0.0001803483],
        [0.004354657, 0.0008777261, 0.0003524784, 0.0002537205, 0.0001803483],
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
        [0.0054993604201008794, 0.027380050122999124, 0.06789059564213898, 0.09325110600401126, 0.13130726772737633],
        [0.0054993604201008794, 0.027380050122999124, 0.06789059564213898, 0.09325110600401126, 0.13130726772737633],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}