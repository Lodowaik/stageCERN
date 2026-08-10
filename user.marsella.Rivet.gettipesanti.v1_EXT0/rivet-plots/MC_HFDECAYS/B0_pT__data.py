
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.01194691, 0.004928651, 0.00141613, 0.0004045332, 0.0001333041, 4.984256e-05, 2.096556e-05, 8.809695e-06, 4.561089e-06, 1.703029e-06],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [2.071019e-05, 1.331302e-05, 7.148304e-06, 3.834511e-06, 2.217609e-06, 1.352705e-06, 8.740354e-07, 5.741499e-07, 4.161459e-07, 2.559365e-07],
        [2.071019e-05, 1.331302e-05, 7.148304e-06, 3.834511e-06, 2.217609e-06, 1.352705e-06, 8.740354e-07, 5.741499e-07, 4.161459e-07, 2.559365e-07],
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
        [0.0017335185416145263, 0.002701148853915605, 0.005047773862569114, 0.009478853651566794, 0.016635714880487547, 0.02713955703719873, 0.041689103463012675, 0.06517250597211369, 0.09123827664840567, 0.1502831132059407],
        [0.0017335185416145263, 0.002701148853915605, 0.005047773862569114, 0.009478853651566794, 0.016635714880487547, 0.02713955703719873, 0.041689103463012675, 0.06517250597211369, 0.09123827664840567, 0.1502831132059407],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}