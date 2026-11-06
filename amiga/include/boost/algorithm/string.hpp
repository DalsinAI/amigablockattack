/* The few Boost string calls Block Attack makes (there is no Boost for the
 * Amiga here): ends_with, replace_all, split with is_any_of.
 * The AmiCradle Team. GPL 2 or later, like Block Attack. */
#ifndef AMIGA_BOOST_ALGORITHM_STRING_HPP
#define AMIGA_BOOST_ALGORITHM_STRING_HPP
#include <string>
#include <vector>

namespace boost {
namespace algorithm {

inline bool ends_with(const std::string& s, const std::string& end) {
	return s.size() >= end.size() && s.compare(s.size() - end.size(), end.size(), end) == 0;
}

inline void replace_all(std::string& s, const std::string& from, const std::string& to) {
	if (from.empty())
		return;
	for (size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
		s.replace(pos, from.size(), to);
}

struct any_of_t {
	std::string chars;
	bool operator()(char c) const { return chars.find(c) != std::string::npos; }
};

inline any_of_t is_any_of(const std::string& chars) {
	return any_of_t{chars};
}

inline std::vector<std::string>& split(std::vector<std::string>& out, const std::string& s, const any_of_t& sep) {
	out.clear();
	std::string part;
	for (char c : s) {
		if (sep(c)) {
			out.push_back(part);
			part.clear();
		}
		else {
			part += c;
		}
	}
	out.push_back(part);
	return out;
}

}  // namespace algorithm
using algorithm::ends_with;
using algorithm::replace_all;
using algorithm::is_any_of;
using algorithm::split;
}  // namespace boost
#endif
