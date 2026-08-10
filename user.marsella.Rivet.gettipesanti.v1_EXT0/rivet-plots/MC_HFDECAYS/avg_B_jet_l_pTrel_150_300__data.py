
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.4592035, 0.04723088, 0.01226867, 0.005370283, 0.002996777, 0.00228242, 0.001438528, 0.001116655],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.001527449, 0.0004899469, 0.0002490203, 0.0001648218, 0.0001234897, 0.0001071905, 8.549525e-05, 7.528216e-05],
        [0.001527449, 0.0004899469, 0.0002490203, 0.0001648218, 0.0001234897, 0.0001071905, 8.549525e-05, 7.528216e-05],
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
        [0.0033263008666092483, 0.010373444238176379, 0.020297253084482672, 0.03069145518029497, 0.04120750392838707, 0.04696352993752246, 0.05943245456466611, 0.06741756406410215],
        [0.0033263008666092483, 0.010373444238176379, 0.020297253084482672, 0.03069145518029497, 0.04120750392838707, 0.04696352993752246, 0.05943245456466611, 0.06741756406410215],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}