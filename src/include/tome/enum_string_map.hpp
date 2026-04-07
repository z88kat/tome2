#pragma once

#include <cassert>
#include <map>
#include <string>

/**
 * Bidirectional mapping between enumerated values
 * and strings.
 */
template <class E>
class EnumStringMap {

public:
	EnumStringMap(EnumStringMap const &) = delete;
	EnumStringMap &operator=(EnumStringMap const &) = delete;

private:
	std::map<E, std::string> m_to_string;
	std::map<std::string, E> m_to_enum;

public:
	explicit EnumStringMap(std::initializer_list< std::pair<E, const char *> > in) {
		for (auto es : in)
		{
			m_to_string.emplace(es.first, es.second);
			m_to_enum.emplace(es.second, es.first);
		}
		// Sanity check that there were no
		// duplicate mappings.
		assert(m_to_string.size() == in.size());
		assert(m_to_enum.size() == in.size());
	}

	const char *stringify(E e) const {
		auto i = m_to_string.find(e);
		assert(i != m_to_string.end() && "Missing mapping for enumerated value");
		return i->second.c_str();
	}

	E parse(std::string const &s) const {
		return parse(s.c_str());
	}

	E parse(const char *s) const {
		E e;
		bool result = parse(s, &e);
		assert(result && "Missing string->enum mapping");
		return e;
	}

	bool parse(std::string const &s, E *e) const {
		return parse(s.c_str(), e);
	}

	bool parse(const char *s, E *e) const {
		auto i = m_to_enum.find(s);
		if (i == m_to_enum.end())
		{
			return false;
		}

		*e = i->second;
		return true;
	}
};
