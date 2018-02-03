package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "hello_pangolin",
    srcs = ["hello_pangolin.cc"],
    deps = [
        "//base:init",
        "//base:logging",
        ":pangolin",
    ],
)

cc_library(
    name = "pangolin",
    linkopts = [
        "-lpangolin",
        "-lGL",
        "-lGLEW",
    ],
    defines = ["USE_EIGEN"],
    deps = [
        "//math:eigen_types",        
    ],
)

cc_library(
    name = "glsl_points",
    hdrs = ["glsl_points.h"],
    srcs = ["glsl_points.cc"],
    deps = [
        ":pangolin",
        "//math:eigen_types",        
        "//base:logging",
    ],
)

cc_binary(
    name = "pangolin_glsl",
    srcs = ["pangolin_glsl.cc"],
    deps = [
        "//math:eigen_types",        
        "//base:init",
        ":glsl_points",
    ],
)
