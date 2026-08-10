
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.66942, 0.08000487, 0.02392028, 0.0104294, 0.005788937, 0.002897369, 0.001963737, 0.001013195],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
        [0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625, 0.625],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [0.00703134, 0.002436753, 0.001326762, 0.0008691453, 0.0006632276, 0.0004581167, 0.000377964, 0.0002707893],
        [0.00703134, 0.002436753, 0.001326762, 0.0008691453, 0.0006632276, 0.0004581167, 0.000377964, 0.0002707893],
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
        [0.010503630008066684, 0.030457558396132633, 0.05546598952855067, 0.08333607877730262, 0.11456811500971595, 0.1581147240824348, 0.19247180248678922, 0.2672627677791541],
        [0.010503630008066684, 0.030457558396132633, 0.05546598952855067, 0.08333607877730262, 0.11456811500971595, 0.1581147240824348, 0.19247180248678922, 0.2672627677791541],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}