#pragma once

#include <optional>
#include <cppqc/Arbitrary.h>

namespace cppqc {

template<typename T>
std::optional<T> arbitraryStdOptional(RngEngine &rng, std::size_t size)
{
	std::uniform_int_distribution<> distribution(0, 4);

	if (distribution(rng) == 0)
	{
		return std::nullopt;
	}
	else
	{
		return Arbitrary<T>::unGen(rng, size);
	}
}

template<typename T>
std::vector<std::optional<T>> shrinkStdOptional(std::optional<T> shrinkInput)
{
	std::vector<std::optional<T>> result;

	if (shrinkInput)
	{
		result.push_back(std::nullopt);

		for (auto const &t: Arbitrary<T>::shrink(*shrinkInput))
		{
			result.push_back(t);
		}
	}

	return result;
}

template <typename T>
class ArbitraryImpl<std::optional<T>> {

public:
	static const typename Arbitrary<std::optional<T>>::unGenType unGen;

	static const typename Arbitrary<std::optional<T>>::shrinkType shrink;

};

template <typename T>
const typename Arbitrary<std::optional<T>>::unGenType
ArbitraryImpl<std::optional<T>>::unGen = arbitraryStdOptional<T>;

template <typename T>
const typename Arbitrary<std::optional<T>>::shrinkType
ArbitraryImpl<std::optional<T>>::shrink = shrinkStdOptional<T>;

} // namespace cppqc
