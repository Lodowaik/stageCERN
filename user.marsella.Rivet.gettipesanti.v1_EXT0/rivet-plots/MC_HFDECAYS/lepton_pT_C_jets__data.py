
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.07245177, 0.01722254, 0.005643416, 0.002261727, 0.001070543, 0.0005552583, 0.0003232556, 0.0001781055, 9.561719e-05, 6.860986e-05],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0],
        [5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.0002148734, 0.0001047415, 5.999855e-05, 3.804823e-05, 2.613965e-05, 1.886406e-05, 1.438386e-05, 1.071503e-05, 7.856398e-06, 6.631192e-06],
        [0.0002148734, 0.0001047415, 5.999855e-05, 3.804823e-05, 2.613965e-05, 1.886406e-05, 1.438386e-05, 1.071503e-05, 7.856398e-06, 6.631192e-06],
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
        [0.002965743970092104, 0.006081652299834983, 0.010631601498099733, 0.01682264481964446, 0.024417188286691895, 0.03397348585334069, 0.044496862544686, 0.060161140447656025, 0.08216512114610353, 0.09665071463489358],
        [0.002965743970092104, 0.006081652299834983, 0.010631601498099733, 0.01682264481964446, 0.024417188286691895, 0.03397348585334069, 0.044496862544686, 0.060161140447656025, 0.08216512114610353, 0.09665071463489358],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}