
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.01195596, 0.004916242, 0.001418916, 0.0004066409, 0.0001345095, 4.926439e-05, 2.175787e-05, 9.304676e-06, 3.467251e-06, 1.788811e-06],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [2.068842e-05, 1.327931e-05, 7.144786e-06, 3.838053e-06, 2.211479e-06, 1.329604e-06, 8.844491e-07, 5.845429e-07, 3.642394e-07, 2.644584e-07],
        [2.068842e-05, 1.327931e-05, 7.144786e-06, 3.838053e-06, 2.211479e-06, 1.329604e-06, 8.844491e-07, 5.845429e-07, 3.642394e-07, 2.644584e-07],
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
        [0.0017303855148394609, 0.0027011099128155204, 0.005035383348979079, 0.009438433271222842, 0.01644106178374018, 0.02698914976923494, 0.040649617816449865, 0.06282248839185803, 0.10505135047909712, 0.1478403252216137],
        [0.0017303855148394609, 0.0027011099128155204, 0.005035383348979079, 0.009438433271222842, 0.01644106178374018, 0.02698914976923494, 0.040649617816449865, 0.06282248839185803, 0.10505135047909712, 0.1478403252216137],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}