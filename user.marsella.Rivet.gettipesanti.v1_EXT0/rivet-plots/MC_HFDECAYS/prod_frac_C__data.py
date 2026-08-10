
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.2931119, 0.5639501, 0.09463041, 0.03803846, 0.004999329, 0.005131455, 0.0001382905],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
        [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.0004972, 0.0006897231, 0.0002825966, 0.0001791416, 6.48788e-05, 6.601035e-05, 1.080399e-05],
        [0.0004972, 0.0006897231, 0.0002825966, 0.0001791416, 6.48788e-05, 6.601035e-05, 1.080399e-05],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
}
ratio0_yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.001696280499017611, 0.0012230215049168357, 0.002986319091294226, 0.00470948613587406, 0.01297750158071213, 0.012863866096458022, 0.07812532314222598],
        [0.001696280499017611, 0.0012230215049168357, 0.002986319091294226, 0.00470948613587406, 0.01297750158071213, 0.012863866096458022, 0.07812532314222598],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}