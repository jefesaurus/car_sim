#include "base/init.h"

DEFINE_string(suffix, "asdfo", "Suffix for string");

int main(int argc, char** argv) {
  Init(&argc, &argv);
  LOG(INFO) << "SUP, " << FLAGS_suffix;
  return 0;
}
