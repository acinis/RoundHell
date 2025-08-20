#include "VersionDef.hpp"

consteval auto rh::Version::operator<=>(const rh::Version& other) const noexcept -> std::strong_ordering
{
    if (major != other.major) {
        return major <=> other.major;
    }
    else if (minor != other.minor) {
        return minor <=> other.minor;
    }
    else {
        return patch <=> other.patch;
    }
}

consteval auto rh::Version::operator==(const rh::Version& other) const noexcept -> bool
{
    return
        major == other.major &&
        minor == other.minor &&
        patch == other.patch
    ;
}

consteval rh::Version rh::Version::current() noexcept
{
    return rh::Version{
        ROUNDHELL_VERSION_MAJOR,
        ROUNDHELL_VERSION_MINOR,
        ROUNDHELL_VERSION_PATCH
    };
}
