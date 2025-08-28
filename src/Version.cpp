#include "Version.hpp"

auto rh::operator<<(std::ostream& os, const rh::version& v) -> std::ostream&
{ 
    return os << v.major << "." << v.minor << "." << v.patch;
}

auto std::formatter<rh::version>::format(const rh::version& v, std::format_context& ctx) const -> std::format_context::iterator
{
    return std::formatter<std::string>::format(
        std::format("{}.{}.{}", v.major, v.minor, v.patch),
        ctx
    );
}
