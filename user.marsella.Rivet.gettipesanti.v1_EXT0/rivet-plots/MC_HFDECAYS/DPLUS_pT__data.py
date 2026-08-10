
import numpy as np
from numpy import nan

add_legend_handle = [
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'
]

xpoints = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [45.0, 85.0, 125.0, 165.0, 205.0, 245.0, 285.0, 325.0, 365.0, 405.0],
}
xedges = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [25.0, 65.0, 105.0, 145.0, 185.0, 225.0, 265.0, 305.0, 345.0, 385.0, 425.0],
}
ref_xerrs = [
  [abs(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]   - xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))],
  [abs(xedges['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i+1] - xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz'][i]) for i in range(len(xpoints['user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz']))]
]

yvals = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.003727564, 0.0006539907, 0.0001387179, 3.915602e-05, 1.280202e-05, 4.774333e-06, 1.777111e-06, 9.229593e-07, 6.38987e-07, 3.557176e-07],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [1.63697e-05, 6.87402e-06, 3.169613e-06, 1.693929e-06, 9.595674e-07, 5.835337e-07, 3.554254e-07, 2.559851e-07, 2.129961e-07, 1.59082e-07],
        [1.63697e-05, 6.87402e-06, 3.169613e-06, 1.693929e-06, 9.595674e-07, 5.835337e-07, 3.554254e-07, 2.559851e-07, 2.129961e-07, 1.59082e-07],
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
        [0.004391527549895857, 0.010510883411644844, 0.02284934388424277, 0.04326101069516258, 0.07495437438779193, 0.12222308330818148, 0.2000018006753658, 0.2773525333132241, 0.3333340114900616, 0.4472143070795485],
        [0.004391527549895857, 0.010510883411644844, 0.02284934388424277, 0.04326101069516258, 0.07495437438779193, 0.12222308330818148, 0.2000018006753658, 0.2773525333132241, 0.3333340114900616, 0.4472143070795485],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}