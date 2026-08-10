
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.003876502, 0.0007764423, 0.0001537761, 5.362698e-05, 1.532057e-05, 7.659469e-06, 4.373696e-06, 1.09511e-06, 5.493415e-07, 5.452923e-07],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [4.637544e-05, 2.08007e-05, 9.233112e-06, 5.471794e-06, 2.89533e-06, 2.047087e-06, 1.546354e-06, 7.74365e-07, 5.493415e-07, 5.452923e-07],
        [4.637544e-05, 2.08007e-05, 9.233112e-06, 5.471794e-06, 2.89533e-06, 2.047087e-06, 1.546354e-06, 7.74365e-07, 5.493415e-07, 5.452923e-07],
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
        [0.011963218386060423, 0.02678975630256105, 0.06004256838351343, 0.1020343491279949, 0.18898317751885207, 0.2672622606084051, 0.3535577232619734, 0.707111614358375, 1.0, 1.0],
        [0.011963218386060423, 0.02678975630256105, 0.06004256838351343, 0.1020343491279949, 0.18898317751885207, 0.2672622606084051, 0.3535577232619734, 0.707111614358375, 1.0, 1.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}