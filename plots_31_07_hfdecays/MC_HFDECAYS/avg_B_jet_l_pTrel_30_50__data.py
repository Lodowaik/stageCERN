
import numpy as np
from numpy import nan

add_legend_handle = [
    'recoil_t',
    'recoil_b'
]

xpoints = {
    'recoil_t' : [1.0, 3.0, 5.0, 7.0],
    'recoil_b' : [1.0, 3.0, 5.0, 7.0],
}
xedges = {
    'recoil_t' : [0.0, 2.0, 4.0, 6.0, 8.0],
    'recoil_b' : [0.0, 2.0, 4.0, 6.0, 8.0],
}
ref_xerrs = [
  [abs(xpoints['recoil_t'][i]   - xedges['recoil_t'][i]) for i in range(len(xpoints['recoil_t']))],
  [abs(xedges['recoil_t'][i+1] - xpoints['recoil_t'][i]) for i in range(len(xpoints['recoil_t']))]
]

yvals = {
    'recoil_t' : [0.4933674, 0.006632582, 0.0, 0.0],
    'recoil_b' : [0.4921971, 0.007802945, 0.0, 0.0],
}
xerrs = {
    'recoil_t' : [
        [1.0, 1.0, 1.0, 1.0],
        [1.0, 1.0, 1.0, 1.0],
    ],
    'recoil_b' : [
        [1.0, 1.0, 1.0, 1.0],
        [1.0, 1.0, 1.0, 1.0],
    ],
}
yerrs = {
    'recoil_t' : [
        [0.006015223, 0.0006952834, 0.0, 0.0],
        [0.006015223, 0.0006952834, 0.0, 0.0],
    ],
    'recoil_b' : [
        [0.00882228, 0.001103503, 0.0, 0.0],
        [0.00882228, 0.001103503, 0.0, 0.0],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'recoil_t' : [1.0, 1.0, 1.0, 1.0],
    'recoil_b' : [0.9976279340710391, 1.1764566197598463, 1.0, 1.0],
}
ratio0_yerrs = {
    'recoil_t' : [
        [0.012192177675298368, 0.10482846650067802, 1.0, 1.0],
        [0.012192177675298368, 0.10482846650067802, 1.0, 1.0],
    ],
    'recoil_b' : [
        [0.017881765191619877, 0.16637608098927387, 1.0, 1.0],
        [0.017881765191619877, 0.16637608098927387, 1.0, 1.0],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}