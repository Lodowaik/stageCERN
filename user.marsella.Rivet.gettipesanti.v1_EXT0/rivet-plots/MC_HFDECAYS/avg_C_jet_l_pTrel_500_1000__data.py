
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.625, 1.875, 3.125, 4.375, 5.625, 6.875, 8.125, 9.375],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.0, 1.25, 2.5, 3.75, 5.0, 6.25, 7.5, 8.75, 10.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.4460549, 0.1007057, 0.07193359, 0.0460811, 0.04606359, 0.01723774, 0.01148726, 0.008650855],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.03582824, 0.01750029, 0.01494923, 0.01152036, 0.01151604, 0.008125185, 0.005743632, 0.004994602],
        [0.03582824, 0.01750029, 0.01494923, 0.01152036, 0.01151604, 0.008125185, 0.005743632, 0.004994602],
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
        [0.08032248945141057, 0.1737765588243764, 0.20781987941933663, 0.25000184457402275, 0.2500030935495909, 0.47136022471623307, 0.5000001741059226, 0.5773535679421282],
        [0.08032248945141057, 0.1737765588243764, 0.20781987941933663, 0.25000184457402275, 0.2500030935495909, 0.47136022471623307, 0.5000001741059226, 0.5773535679421282],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}