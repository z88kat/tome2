#pragma once

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>
#include <vector>

// Case-insensitive string equality
inline bool iequals(std::string_view a, std::string_view b)
{
	return a.size() == b.size() &&
		std::equal(a.begin(), a.end(), b.begin(),
			[](unsigned char x, unsigned char y) {
				return std::tolower(x) == std::tolower(y);
			});
}

// Case-insensitive substring search
inline bool icontains(std::string_view haystack, std::string_view needle)
{
	if (needle.empty()) return true;
	return std::search(
		haystack.begin(), haystack.end(),
		needle.begin(), needle.end(),
		[](unsigned char a, unsigned char b) {
			return std::tolower(a) == std::tolower(b);
		}) != haystack.end();
}

// Case-sensitive prefix check
inline bool starts_with(std::string_view s, std::string_view prefix)
{
	return s.size() >= prefix.size() && s.substr(0, prefix.size()) == prefix;
}

// Case-sensitive suffix check
inline bool ends_with(std::string_view s, std::string_view suffix)
{
	return s.size() >= suffix.size() && s.substr(s.size() - suffix.size()) == suffix;
}

// Case-sensitive equality (std::string_view overload for drop-in compatibility)
inline bool equals(std::string_view a, std::string_view b)
{
	return a == b;
}

// Split string by a single delimiter character
inline void split(std::vector<std::string> &result, std::string_view s, char delim)
{
	result.clear();
	std::size_t start = 0;
	std::size_t pos;
	while ((pos = s.find(delim, start)) != std::string_view::npos)
	{
		result.emplace_back(s.substr(start, pos - start));
		start = pos + 1;
	}
	result.emplace_back(s.substr(start));
}

// Join strings with a separator
inline std::string join(std::vector<std::string> const &v, std::string_view sep)
{
	std::string result;
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		if (i > 0) result += sep;
		result += v[i];
	}
	return result;
}

// Remove trailing whitespace in place
inline void trim_right(std::string &s)
{
	auto it = s.end();
	while (it != s.begin() && std::isspace(static_cast<unsigned char>(*(it - 1))))
		--it;
	s.erase(it, s.end());
}
