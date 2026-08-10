
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.00370241, 0.0006542548, 0.000137168, 3.537505e-05, 1.095046e-05, 4.653003e-06, 1.771684e-06, 7.748622e-07, 5.164413e-07, 2.216566e-07],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [1.177212e-05, 4.95289e-06, 2.279771e-06, 1.168044e-06, 6.496846e-07, 4.210279e-07, 2.557219e-07, 1.690906e-07, 1.380253e-07, 9.04911e-08],
        [1.177212e-05, 4.95289e-06, 2.279771e-06, 1.168044e-06, 6.496846e-07, 4.210279e-07, 2.557219e-07, 1.690906e-07, 1.380253e-07, 9.04911e-08],
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
        [0.0031795830283518033, 0.00757027690129289, 0.01662028315642132, 0.033018864991003545, 0.05932943456256633, 0.09048519848364595, 0.14433832444160472, 0.21822022031788363, 0.26726232003521017, 0.40824906634857705],
        [0.0031795830283518033, 0.00757027690129289, 0.01662028315642132, 0.033018864991003545, 0.05932943456256633, 0.09048519848364595, 0.14433832444160472, 0.21822022031788363, 0.26726232003521017, 0.40824906634857705],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}