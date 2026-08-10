
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.5023452, 0.02494203, 0.003147722, 0.00118288, 0.0005870448, 0.0003470419, 0.0002119984, 0.0001536955],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.0004708219, 0.0001049944, 3.72746e-05, 2.288319e-05, 1.619522e-05, 1.24206e-05, 9.695386e-06, 8.312154e-06],
        [0.0004708219, 0.0001049944, 3.72746e-05, 2.288319e-05, 1.619522e-05, 1.24206e-05, 9.695386e-06, 8.312154e-06],
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
        [0.0009372477332320483, 0.0042095370745685095, 0.011841770016538944, 0.019345318206411468, 0.027587707105147682, 0.03578991470482382, 0.04573329798715462, 0.05408196076007431],
        [0.0009372477332320483, 0.0042095370745685095, 0.011841770016538944, 0.019345318206411468, 0.027587707105147682, 0.03578991470482382, 0.04573329798715462, 0.05408196076007431],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}