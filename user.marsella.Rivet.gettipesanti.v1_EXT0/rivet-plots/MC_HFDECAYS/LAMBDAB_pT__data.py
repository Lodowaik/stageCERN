
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.01181906, 0.005020994, 0.001472846, 0.000449072, 0.0001378351, 4.997748e-05, 2.192705e-05, 1.080332e-05, 4.88982e-06, 3.229153e-06],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [6.965049e-05, 4.546831e-05, 2.474361e-05, 1.364419e-05, 7.650688e-06, 4.506343e-06, 3.039498e-06, 2.368694e-06, 1.522444e-06, 1.289103e-06],
        [6.965049e-05, 4.546831e-05, 2.474361e-05, 1.364419e-05, 7.650688e-06, 4.506343e-06, 3.039498e-06, 2.368694e-06, 1.522444e-06, 1.289103e-06],
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
        [0.005893065099931806, 0.009055639182201772, 0.016799862307396697, 0.030383078882673602, 0.05550609387594306, 0.09016747142913167, 0.1386186468311971, 0.21925611756386001, 0.3113497020340217, 0.3992077798729264],
        [0.005893065099931806, 0.009055639182201772, 0.016799862307396697, 0.030383078882673602, 0.05550609387594306, 0.09016747142913167, 0.1386186468311971, 0.21925611756386001, 0.3113497020340217, 0.3992077798729264],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}