package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "init_example",
    srcs = ["init_example.cc"],
    deps = [":init"],
)

cc_library(
    name = "init",
    hdrs = ["init.h"],
    deps = [":logging"],
)

cc_library(
    name = "logging",
    hdrs = ["logging.h"],
    deps = [
        "@com_google_glog//:glog",
    ]
)

cc_library(
    name = "time",
    srcs = ["time.cc"],
    hdrs = ["time.h"],
    deps = [":logging"],
)

cc_library(
    name = "wall_timer",
    hdrs = ["wall_timer.h"],
    deps = [
        ":logging",
        ":time",
    ],
)

cc_library(
    name = "file",
    srcs = ["file.cc"],
    hdrs = ["file.h"],
    deps = [
        ":logging",
    ],
)

cc_library(
    name = "googletest",
    hdrs = ["googletest.h"],
    deps = [
        ":logging",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "logging_test",
    srcs = ["logging_test.cc"],
    deps = [
        ":googletest",
    ],
)

cc_test(
    name = "optional_test",
    srcs = ["optional_test.cc"],
    deps = [
        ":googletest",
    ],
)
