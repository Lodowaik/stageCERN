
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [10.0, 30.0, 50.0, 70.0, 90.0, 110.0, 130.0, 150.0, 170.0, 190.0],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.0, 20.0, 40.0, 60.0, 80.0, 100.0, 120.0, 140.0, 160.0, 180.0, 200.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.01325778, 0.02042648, 0.009127218, 0.003882766, 0.001685431, 0.0007773985, 0.0003711343, 0.0002037463, 0.0001095255, 6.084233e-05],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
        [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [4.462261e-05, 5.542123e-05, 3.704578e-05, 2.418345e-05, 1.596931e-05, 1.086511e-05, 7.499728e-06, 5.611026e-06, 4.080938e-06, 3.04397e-06],
        [4.462261e-05, 5.542123e-05, 3.704578e-05, 2.418345e-05, 1.596931e-05, 1.086511e-05, 7.499728e-06, 5.611026e-06, 4.080938e-06, 3.04397e-06],
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
        [0.0033657678736560724, 0.0027132051141459516, 0.004058824934388552, 0.006228407789704555, 0.009474911758476022, 0.013976242557710107, 0.02020758523262334, 0.027539278013882947, 0.03726016315835125, 0.050030463987819004],
        [0.0033657678736560724, 0.0027132051141459516, 0.004058824934388552, 0.006228407789704555, 0.009474911758476022, 0.013976242557710107, 0.02020758523262334, 0.027539278013882947, 0.03726016315835125, 0.050030463987819004],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}