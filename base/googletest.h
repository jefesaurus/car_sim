#pragma once

#include "base/logging.h" 
#include <gtest/gtest.h>

// Define "main()" for a unit test using gtest.
#define GTEST_MAIN()                                    \
  int main(int argc, char** argv) {                     \
    FLAGS_logtostderr = true;                           \
    google::InitGoogleLogging(argv[0]);                 \
    google::InstallFailureSignalHandler();              \
    testing::InitGoogleTest(&argc, argv);               \
    google::ParseCommandLineFlags(&argc, &argv, false); \
    return RUN_ALL_TESTS();                             \
  }
