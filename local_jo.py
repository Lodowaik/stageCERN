#import glo
#import sys
#include("GeneratorUtils/StdAnalysisSetup.py")
from AthenaCommon.AppMgr import theApp
from AthenaCommon.AppMgr import ServiceMgr as svcMgr
from AthenaCommon.Constants import WARNING
#raise RuntimeError("STO LEGGENDO QUESTO LOCAL_JO")
print("========== LOCAL_JO LOADED ==========") #per verificare che lo stia aprendo correttamente
theApp.EvtMax = -1
svcMgr.MessageSvc.OutputLevel = WARNING

import AthenaPoolCnvSvc.ReadAthenaPool
svcMgr.EventSelector.InputCollections = ['/eos/user/m/marsella/EVNT.33856989._004982.pool.root.1' ]
print("INPUT =", svcMgr.EventSelector.InputCollections)
svcMgr.EventSelector.OutputLevel = DEBUG

from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from xAODEventInfoCnv.xAODEventInfoCnvConf import xAODMaker__EventInfoCnvAlg
job += xAODMaker__EventInfoCnvAlg()

from Rivet_i.Rivet_iConf import Rivet_i
rivet = Rivet_i()
import os
rivet.AnalysisPath = os.environ['PWD']

rivet.Analyses += [ 'MC_HFDECAYS' ]
rivet.RunName = ''
#rivet.HistoFile = 'MyZmumu_PowhegPy8.yoda.gz'
rivet.HistoFile = 'mod1_hfdecays_dilep_rtt_evnt.338.yoda.gz'
rivet.CrossSection = 1.0
rivet.IgnoreBeamCheck = True
#rivet.SkipWeights=True
job += rivet
print(svcMgr.EventSelector.InputCollections)
