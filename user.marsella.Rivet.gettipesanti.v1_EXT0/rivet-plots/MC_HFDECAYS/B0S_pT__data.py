
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
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [0.01191924, 0.005000294, 0.001432373, 0.0004272865, 0.0001347944, 5.097385e-05, 2.392199e-05, 8.562383e-06, 3.066319e-06, 2.096595e-06],
}
xerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
        [20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0],
    ],
}
yerrs = {
    'user.marsella.51666151.EXT0._000002.gettipesanti.yoda.gz' : [
        [4.41235e-05, 2.859696e-05, 1.533733e-05, 8.410254e-06, 4.718469e-06, 2.936762e-06, 2.018882e-06, 1.219667e-06, 7.03468e-07, 5.814926e-07],
        [4.41235e-05, 2.859696e-05, 1.533733e-05, 8.410254e-06, 4.718469e-06, 2.936762e-06, 2.018882e-06, 1.219667e-06, 7.03468e-07, 5.814926e-07],
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
        [0.00370187193143187, 0.005719055719523692, 0.010707636907425648, 0.019682938730804744, 0.03500493343937137, 0.05761310946691294, 0.08439440029863736, 0.142444807712993, 0.22941774812079238, 0.2773509428382687],
        [0.00370187193143187, 0.005719055719523692, 0.010707636907425648, 0.019682938730804744, 0.03500493343937137, 0.05761310946691294, 0.08439440029863736, 0.142444807712993, 0.22941774812079238, 0.2773509428382687],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}