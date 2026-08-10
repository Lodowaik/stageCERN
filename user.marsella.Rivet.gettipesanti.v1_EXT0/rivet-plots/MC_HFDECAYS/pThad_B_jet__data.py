
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.001081973, 0.01398674, 0.0143028, 0.009224218, 0.005197684, 0.002808496, 0.001487614, 0.0008029909, 0.0004410544, 0.0002532835],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
        [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [6.628096e-06, 2.383331e-05, 2.41078e-05, 1.936996e-05, 1.454924e-05, 1.070315e-05, 7.802603e-06, 5.740579e-06, 4.269863e-06, 3.235784e-06],
        [6.628096e-06, 2.383331e-05, 2.41078e-05, 1.936996e-05, 1.454924e-05, 1.070315e-05, 7.802603e-06, 5.740579e-06, 4.269863e-06, 3.235784e-06],
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
        [0.006125934750682319, 0.0017039932107124319, 0.0016855301059932322, 0.0020999026692560823, 0.00279917747981601, 0.003810989939099076, 0.005245045421729024, 0.00714899633358236, 0.00968103481112534, 0.012775344623712164],
        [0.006125934750682319, 0.0017039932107124319, 0.0016855301059932322, 0.0020999026692560823, 0.00279917747981601, 0.003810989939099076, 0.005245045421729024, 0.00714899633358236, 0.00968103481112534, 0.012775344623712164],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}