#pragma once

#include <optional>
#include <jsoncons/json.hpp>
#include <string>

namespace squelch {

template <class T>
std::optional<T> get_optional(jsoncons::json const &json, std::string const &key)
{
	if (!json.contains(key))
	{
		return std::nullopt;
	}

	auto value = json.at(key);

	if (!value.is<T>())
	{
		return std::nullopt;
	}

	return value.as<T>();
}

} // namespace squelch
