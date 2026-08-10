from AthenaCommon.AlgSequence import AlgSequence
from AthenaCommon.AppMgr import ServiceMgr

theApp.EvtMax = -1

import AthenaPoolCnvSvc.ReadAthenaPool

ServiceMgr.EventSelector.InputCollections = [
    "EVNT.38750384._005106.pool.root.1"
]

from Rivet_i.Rivet_iConf import Rivet_i

job = AlgSequence()

rivet = Rivet_i()

rivet.Analyses += ["MC_TTBAR"]

rivet.AnalysisPath = "."
rivet.HistoFile = "ttbar.yoda.gz"

job += rivet
