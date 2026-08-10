
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.7486432, 0.03469195, 0.008028118, 0.00372617, 0.002119207, 0.001113532, 0.0006761062, 0.0003624208],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.001953708, 0.0004210353, 0.0002022415, 0.0001377212, 0.0001042599, 7.560688e-05, 5.841673e-05, 4.271202e-05],
        [0.001953708, 0.0004210353, 0.0002022415, 0.0001377212, 0.0001042599, 7.560688e-05, 5.841673e-05, 4.271202e-05],
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
        [0.0026096650580677153, 0.012136397636915769, 0.025191645165155766, 0.03696052515048965, 0.04919760080067685, 0.0678982552813929, 0.08640170730574576, 0.11785201070137255],
        [0.0026096650580677153, 0.012136397636915769, 0.025191645165155766, 0.03696052515048965, 0.04919760080067685, 0.0678982552813929, 0.08640170730574576, 0.11785201070137255],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}