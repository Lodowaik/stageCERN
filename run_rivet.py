from AthenaConfiguration.AllConfigFlags import initConfigFlags
from AthenaConfiguration.MainServicesConfig import MainServicesCfg
from AthenaPoolCnvSvc.PoolReadConfig import PoolReadCfg

flags = initConfigFlags()

flags.Input.Files = [
    "EVNT.38750384._005106.pool.root.1"
]

flags.lock()

cfg = MainServicesCfg(flags)
cfg.merge(PoolReadCfg(flags))

from Rivet_i.Rivet_iConf import Rivet_i

rivet = Rivet_i()
rivet.Analyses = ["MC_TTBAR"]

cfg.addEventAlgo(rivet)

cfg.run()
