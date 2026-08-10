
import numpy as np
from numpy import nan

add_legend_handle = [
    'recoil_t',
    'recoil_b'
]

xpoints = {
    'recoil_t' : [1.0, 3.0],
    'recoil_b' : [1.0, 3.0],
}
xedges = {
    'recoil_t' : [0.0, 2.0, 4.0],
    'recoil_b' : [0.0, 2.0, 4.0],
}
ref_xerrs = [
  [abs(xpoints['recoil_t'][i]   - xedges['recoil_t'][i]) for i in range(len(xpoints['recoil_t']))],
  [abs(xedges['recoil_t'][i+1] - xpoints['recoil_t'][i]) for i in range(len(xpoints['recoil_t']))]
]

yvals = {
    'recoil_t' : [0.4954788, 0.004521225],
    'recoil_b' : [0.4972631, 0.002736856],
}
xerrs = {
    'recoil_t' : [
        [1.0, 1.0],
        [1.0, 1.0],
    ],
    'recoil_b' : [
        [1.0, 1.0],
        [1.0, 1.0],
    ],
}
yerrs = {
    'recoil_t' : [
        [0.01503465, 0.001429737],
        [0.01503465, 0.001429737],
    ],
    'recoil_b' : [
        [0.02137842, 0.001580125],
        [0.02137842, 0.001580125],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'recoil_t' : [1.0, 1.0],
    'recoil_b' : [1.0036011631577375, 0.6053350585294914],
}
ratio0_yerrs = {
    'recoil_t' : [
        [0.03034367968922182, 0.3162277922465703],
        [0.03034367968922182, 0.3162277922465703],
    ],
    'recoil_b' : [
        [0.04314699236374997, 0.34949045889111907],
        [0.04314699236374997, 0.34949045889111907],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}