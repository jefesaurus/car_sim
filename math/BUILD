package(default_visibility = ["//visibility:public"])

cc_library(
    name = "eigen_types",
    hdrs = ["eigen_types.h"],
    copts = ["-DEIGEN_ENABLE_AVX512", "-mavx512f"],
    deps = ["@com_eigenteam_eigen_git_mirror//:eigen3"],
)

cc_binary(
    name = "eigen_test",
    srcs = ["eigen_test.cc"],
    deps = [
        ":eigen_types",
        "//base:init",
        "//base:logging",
    ],
)

cc_binary(
    name = "sdl_test",
    srcs = ["sdl_test.cc"],
    linkopts = [
        "-lSDL2",
        "-lGL",
    ],
    deps = [],
)

cc_library(
    name = "sdl_container",
    hdrs = ["sdl_container.h"],
    linkopts = [
        "-lSDL2",
        "-lGL",
    ],
    deps = [
        ":controller_input",
        ":eigen_types",
        ":pixel_buffer",
    ],
)
