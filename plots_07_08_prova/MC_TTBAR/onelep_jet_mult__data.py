
import numpy as np
from numpy import nan

add_legend_handle = [
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz'
]

xpoints = {
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz' : [0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0],
}
xedges = {
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz' : [-0.5, 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5],
}
ref_xerrs = [
  [abs(xpoints['mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz'][i]   - xedges['mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz'][i]) for i in range(len(xpoints['mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz']))],
  [abs(xedges['mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz'][i+1] - xpoints['mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz'][i]) for i in range(len(xpoints['mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz']))]
]

yvals = {
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz' : [0.0, 0.0, 0.0, 0.0, 0.1109876, 0.05786649, 0.02757055, 0.008382331, 0.002120912, 0.0004039873, 0.0003029834],
}
xerrs = {
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz' : [
        [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
        [0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
    ],
}
yerrs = {
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz' : [
        [0.0, 0.0, 0.0, 0.0, 0.003357049, 0.002434222, 0.001674745, 0.0009311023, 0.0004843623, 0.0002019937, 0.0001749275],
        [0.0, 0.0, 0.0, 0.0, 0.003357049, 0.002434222, 0.001674745, 0.0009311023, 0.0004843623, 0.0002019937, 0.0001749275],
    ],
}
variation_yvals = {
}


# lists for ratio plot
ratio0_yvals = {
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz' : [1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
}
ratio0_yerrs = {
    'mod1_ttbar_nonallhad_rtb_evnt.124.yoda.gz' : [
        [1.0, 1.0, 1.0, 1.0, 0.030247063635937706, 0.042066176814940744, 0.06074398225642942, 0.11107916163177045, 0.2283745388776149, 0.5000001237662669, 0.577350112250374],
        [1.0, 1.0, 1.0, 1.0, 0.030247063635937706, 0.042066176814940744, 0.06074398225642942, 0.11107916163177045, 0.2283745388776149, 0.5000001237662669, 0.577350112250374],
    ],
}
ratio0_variation_vals = {
}
ratio_band_edges = {
}