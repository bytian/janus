#pragma once

#include "../frame.h"
#include "../constants.h"
#include "commo.h"

namespace janus {

class FrameRococo : public Frame {
 public:
  FrameRococo() : Frame(MODE_RCC) {}
  Executor *CreateExecutor(cmdid_t, Scheduler *sched) override;
  Coordinator *CreateCoordinator(cooid_t coo_id,
                                 Config *config,
                                 int benchmark,
                                 ClientControlServiceImpl *ccsi,
                                 uint32_t id,
                                 TxnRegistry *txn_reg) override;
  Scheduler *CreateScheduler() override;
  vector<rrr::Service *> CreateRpcServices(uint32_t site_id,
                                           Scheduler *dtxn_sched,
                                           rrr::PollMgr *poll_mgr,
                                           ServerControlServiceImpl *scsi)
  override;
  mdb::Row *CreateRow(const mdb::Schema *schema,
                      vector<Value> &row_data) override;

  shared_ptr<Tx> CreateTx(epoch_t epoch, txnid_t tid,
                          bool ro, Scheduler *mgr) override;

  Communicator *CreateCommo(PollMgr *poll = nullptr) override;

};
} // namespace janus