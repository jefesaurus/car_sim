package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "hello_box2d",
    srcs = ["hello_box2d.cc"],
    linkopts = [
        "-lBox2D",
    ],
    deps = [
        "//math:eigen_types",
        "//base:init",
        "//base:logging",
    ],
)
