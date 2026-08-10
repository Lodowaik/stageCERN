
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.625, 1.875, 3.125, 4.375, 5.625, 6.875, 8.125, 9.375],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.0, 1.25, 2.5, 3.75, 5.0, 6.25, 7.5, 8.75, 10.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.7356026, 0.0440146, 0.009677083, 0.005509259, 0.002865032, 0.00156739, 0.0006664796, 9.752536e-05],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.004265652, 0.001044323, 0.0004869236, 0.0003721444, 0.0002648739, 0.000195925, 0.0001283512, 4.876278e-05],
        [0.004265652, 0.001044323, 0.0004869236, 0.0003721444, 0.0002648739, 0.000195925, 0.0001283512, 4.876278e-05],
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
        [0.005798853892033552, 0.023726740672413243, 0.05031718752438106, 0.06754890267457021, 0.09245059042970549, 0.12500079750413107, 0.19258083818319421, 0.5000010253743231],
        [0.005798853892033552, 0.023726740672413243, 0.05031718752438106, 0.06754890267457021, 0.09245059042970549, 0.12500079750413107, 0.19258083818319421, 0.5000010253743231],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}