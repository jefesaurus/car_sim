#pragma once
#include "base/logging.h"

void Init(int* argc, char*** argv) {
  CHECK_NOTNULL(argc);
  CHECK_NOTNULL(argv);
  FLAGS_alsologtostderr = true;
  google::InitGoogleLogging(*argv[0]);
  google::ParseCommandLineFlags(argc, argv, false);
  google::InstallFailureSignalHandler();
}
