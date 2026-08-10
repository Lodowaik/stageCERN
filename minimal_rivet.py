from AthenaCommon.AppMgr import ServiceMgr
from AthenaCommon.AppMgr import theApp
from AthenaCommon.Constants import INFO

theApp.EvtMax = 10

ServiceMgr.MessageSvc.OutputLevel = INFO

import AthenaPoolCnvSvc.ReadAthenaPool

ServiceMgr.EventSelector.InputCollections = [
    "/eos/user/m/marsella/EVNT.29331034._003002.pool.root.1"
]

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from xAODEventInfoCnv.xAODEventInfoCnvConf import xAODMaker__EventInfoCnvAlg
job += xAODMaker__EventInfoCnvAlg()

from Rivet_i.Rivet_iConf import Rivet_i

rivet = Rivet_i()

rivet.Analyses = ["MC_HFJETS"]

rivet.HistoFile = "test.yoda.gz"

job += rivet
