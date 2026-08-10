
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.4903204, 0.03431918, 0.005467973, 0.001942799, 0.0008730721, 0.0003149254, 8.393947e-05, 1.107535e-05],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
        [0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375, 0.9375],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.001047873, 0.0002771386, 0.0001103334, 6.589113e-05, 4.426338e-05, 2.662303e-05, 1.361685e-05, 4.953065e-06],
        [0.001047873, 0.0002771386, 0.0001103334, 6.589113e-05, 4.426338e-05, 2.662303e-05, 1.361685e-05, 4.953065e-06],
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
        [0.0021371189124499, 0.008075326974595547, 0.02017811719260501, 0.03391556717910602, 0.05069842456310309, 0.08453757620058593, 0.16222225372640547, 0.44721521216033805],
        [0.0021371189124499, 0.008075326974595547, 0.02017811719260501, 0.03391556717910602, 0.05069842456310309, 0.08453757620058593, 0.16222225372640547, 0.44721521216033805],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}