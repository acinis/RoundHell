#ifndef ROUNDHELL_VERSION_HPP
#define ROUNDHELL_VERSION_HPP

#include <compare>
#include <format>
#include <ostream>
#include <string>

namespace rh {

struct version final
{
    int major = 0;
    int minor = 0;
    int patch = 0;

    consteval auto operator<=>(const version& other) const noexcept -> std::strong_ordering;

    consteval auto operator==(const version& other) const noexcept -> bool;

    static consteval version current() noexcept;
};

auto operator<<(std::ostream& os, const version& v) -> std::ostream&;

} // namespace rh

template<>
struct std::formatter<rh::version> : std::formatter<std::string>
{
    auto format(const rh::version& v, std::format_context& ctx) const -> std::format_context::iterator;
};

#include "version.ipp"

#endif // ROUNDHELL_VERSION_HPP
