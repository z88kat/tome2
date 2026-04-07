#pragma once

#include <cstddef>
#include <vector>

/**
 * 2D grid of T's.
 */
template <typename T>
struct grid {

private:
	std::vector<T> m_data;
	std::size_t m_width  = 0;
	std::size_t m_height = 0;

public:
	/**
	 * Get reference to tile.
	 */
	T &operator ()(std::size_t x, std::size_t y)
	{
		return m_data[y * m_width + x];
	}

	/**
	 * Get const reference to tile.
	 */
	T const &operator ()(std::size_t x, std::size_t y) const
	{
		return m_data[y * m_width + x];
	}

	/**
	 * Resize grid. Existing elements are not preserved.
	 */
	void resize(std::size_t new_width, std::size_t new_height)
	{
		m_width  = new_width;
		m_height = new_height;
		m_data.assign(m_width * m_height, T{});
	}

	/**
	 * Get current width.
	 */
	std::size_t width() const
	{
		return m_width;
	}

	/**
	 * Get current height.
	 */
	std::size_t height() const
	{
		return m_height;
	}

	/**
	 * Set width. Same caveats apply as for resize().
	 */
	void width(std::size_t w)
	{
		resize(w, m_height);
	}

	/**
	 * Set height. Same caveats apply as for resize().
	 */
	void height(std::size_t h)
	{
		resize(m_width, h);
	}

};
