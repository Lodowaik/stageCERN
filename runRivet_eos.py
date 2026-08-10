from AthenaCommon.AlgSequence import AlgSequence
from AthenaCommon.AppMgr import ServiceMgr

theApp.EvtMax = -1

import AthenaPoolCnvSvc.ReadAthenaPool

ServiceMgr.EventSelector.InputCollections = [
 "/eos/user/m/marsella/EVNT.38750384._005106.pool.root.1",
 "/eos/user/m/marsella/EVNT.48024315._005001.pool.root.1"
]

from Rivet_i.Rivet_iConf import Rivet_i

job = AlgSequence()

rivet = Rivet_i()

rivet.Analyses += ["MC_HFJETS"]

rivet.AnalysisPath = "."
rivet.HistoFile = "hfjets_rtb_run3_singlelep.yoda.gz"

job += rivet
