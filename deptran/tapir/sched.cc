#include "../__dep__.h"
#include "../command.h"
#include "sched.h"
#include "exec.h"

namespace rococo {

int TapirSched::OnHandoutRequest(const SimpleCommand &cmd,
                                 int *res,
                                 map<int32_t, Value> *output,
                                 const function<void()> &callback) {
//  auto exec = (TapirExecutor*) GetOrCreateExecutor(cmd.root_id_);
  auto exec = GetOrCreateExecutor(cmd.root_id_);
//  verify(0);
  exec->mdb_txn();
  exec->Execute(cmd, res, *output);
  callback();
  return 0;

}

int TapirSched::OnFastAccept(cmdid_t cmd_id,
                             int* res,
                             const function<void()>& callback) {
  auto exec = (TapirExecutor*) GetOrCreateExecutor(cmd_id);
  exec->FastAccept(res);
  callback();
  return 0;
}

} // namespace rococo