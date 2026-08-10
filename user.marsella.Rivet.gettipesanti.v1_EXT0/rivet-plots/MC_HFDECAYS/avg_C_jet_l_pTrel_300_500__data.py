
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.5849761, 0.0907058, 0.03831266, 0.02573299, 0.013465, 0.01580373, 0.009953229, 0.008194176],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.01858025, 0.007378329, 0.004760374, 0.003965962, 0.002926075, 0.003041453, 0.002414039, 0.002190004],
        [0.01858025, 0.007378329, 0.004760374, 0.003965962, 0.002926075, 0.003041453, 0.002414039, 0.002190004],
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
        [0.03176240875481921, 0.08134351937803316, 0.12425067849635082, 0.15411975056143884, 0.21730969179353882, 0.1924515921241378, 0.24253827576960205, 0.2672634807941641],
        [0.03176240875481921, 0.08134351937803316, 0.12425067849635082, 0.15411975056143884, 0.21730969179353882, 0.1924515921241378, 0.24253827576960205, 0.2672634807941641],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}