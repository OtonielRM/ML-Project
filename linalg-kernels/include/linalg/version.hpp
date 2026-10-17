#pragma once

namespace linalg {

struct Version {
    int major;
    int minor;
    int patch;
};

// Library version, injected from CMake's project(VERSION ...) at build time.
Version version() noexcept;

}  // namespace linalg
