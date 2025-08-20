#ifndef ROUNDHELL_VERSION_HPP
#define ROUNDHELL_VERSION_HPP

#include <compare>
#include <format>
#include <ostream>
#include <string>

namespace rh {

struct Version final
{
    int major = 0;
    int minor = 0;
    int patch = 0;

    consteval auto operator<=>(const Version& other) const noexcept -> std::strong_ordering;

    consteval auto operator==(const Version& other) const noexcept -> bool;

    static consteval Version current() noexcept;
};

auto operator<<(std::ostream& os, const Version& v) -> std::ostream&;

} // namespace rh

template<>
struct std::formatter<rh::Version> : std::formatter<std::string>
{
    auto format(const rh::Version& v, std::format_context& ctx) const -> std::format_context::iterator;
};

#include "Version.ipp"

#endif // ROUNDHELL_VERSION_HPP
