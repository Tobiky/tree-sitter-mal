// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterMal",
    products: [
        .library(name: "TreeSitterMal", targets: ["TreeSitterMal"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterMal",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterMalTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterMal",
            ],
            path: "bindings/swift/TreeSitterMalTests"
        )
    ],
    cLanguageStandard: .c11
)
