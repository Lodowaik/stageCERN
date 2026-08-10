
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [5.0, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0, 75.0, 85.0, 95.0],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.06481857, 0.02046826, 0.007802392, 0.003401983, 0.001614953, 0.0008263229, 0.0004372507, 0.0002387224, 0.0001396513, 8.228156e-05],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0],
        [5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [7.32154e-05, 4.115714e-05, 2.542598e-05, 1.67974e-05, 1.158519e-05, 8.282493e-06, 6.034203e-06, 4.455236e-06, 3.419222e-06, 2.612159e-06],
        [7.32154e-05, 4.115714e-05, 2.542598e-05, 1.67974e-05, 1.158519e-05, 8.282493e-06, 6.034203e-06, 4.455236e-06, 3.419222e-06, 2.612159e-06],
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
        [0.0011295435860433204, 0.002010778639708505, 0.0032587416781930463, 0.004937532021764953, 0.007173701030308622, 0.010023312920409201, 0.013800327821087536, 0.018662831807991206, 0.024483996926630832, 0.03174659060912311],
        [0.0011295435860433204, 0.002010778639708505, 0.0032587416781930463, 0.004937532021764953, 0.007173701030308622, 0.010023312920409201, 0.013800327821087536, 0.018662831807991206, 0.024483996926630832, 0.03174659060912311],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}