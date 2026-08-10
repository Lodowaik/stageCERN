
import numpy as np
from numpy import nan

add_legend_handle = [
    'recoil_t',
    'recoil_b'
]

xpoints = {
    'recoil_t' : [0.75, 2.25],
    'recoil_b' : [0.75, 2.25],
}
xedges = {
    'recoil_t' : [0.0, 1.5, 3.0],
    'recoil_b' : [0.0, 1.5, 3.0],
}
ref_xerrs = [
  [abs(xpoints['recoil_t'][i]   - xedges['recoil_t'][i]) for i in range(len(xpoints['recoil_t']))],
  [abs(xedges['recoil_t'][i+1] - xpoints['recoil_t'][i]) for i in range(len(xpoints['recoil_t']))]
]

yvals = {
    'recoil_t' : [0.6634612, 0.003205519],
    'recoil_b' : [0.6666667, 0.0],
}
xerrs = {
    'recoil_t' : [
        [0.75, 0.75],
        [0.75, 0.75],
    ],
    'recoil_b' : [
        [0.75, 0.75],
        [0.75, 0.75],
    ],
}
yerrs = {
    'recoil_t' : [
        [0.04611374, 0.003205519],
        [0.04611374, 0.003205519],
    ],
    'recoil_b' : [
        [0.05735401, 0.0],
        [0.05735401, 0.0],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'recoil_t' : [1.0, 1.0],
    'recoil_b' : [1.004831480725625, 0.0],
}
ratio0_yerrs = {
    'recoil_t' : [
        [0.06950480299375457, 1.0],
        [0.06950480299375457, 1.0],
    ],
    'recoil_b' : [
        [0.08644666786844506, 0.0],
        [0.08644666786844506, 0.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}