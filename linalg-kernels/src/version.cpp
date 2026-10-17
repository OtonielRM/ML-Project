#include "linalg/version.hpp"

namespace linalg {

Version version() noexcept {
    return {LINALG_VERSION_MAJOR, LINALG_VERSION_MINOR, LINALG_VERSION_PATCH};
}

}  // namespace linalg
