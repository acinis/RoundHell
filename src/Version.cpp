#include "Version.hpp"

auto rh::operator<<(std::ostream& os, const rh::Version& v) -> std::ostream&
{ 
    return os << v.major << "." << v.minor << "." << v.patch;
}

auto std::formatter<rh::Version>::format(const rh::Version& v, std::format_context& ctx) const -> std::format_context::iterator
{
    return std::formatter<std::string>::format(
        std::format("{}.{}.{}", v.major, v.minor, v.patch),
        ctx
    );
}
