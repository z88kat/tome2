#pragma once

#include "key_queue_fwd.hpp"

#include <cassert>
#include <cstddef>
#include <vector>


/*
 * Low-level key queue handling — fixed-capacity circular buffer.
 */
class key_queue {

private:
	std::vector<char> m_buf;
	std::size_t m_capacity;
	std::size_t m_head = 0;  // index of oldest element
	std::size_t m_size = 0;

	std::size_t next(std::size_t i) const { return (i + 1) % m_capacity; }

public:
	/*
	 * Overflow signal
	 */
	enum class push_result_t {
		OK,
		QUEUE_OVERFLOW,
	};

public:
	explicit key_queue(std::size_t k)
		: m_buf(k), m_capacity(k)
	{
	}

	void clear()
	{
		m_head = 0;
		m_size = 0;
	}

	bool full() const { return m_size == m_capacity; }

	void push_back(char c)
	{
		if (full())
		{
			return; // Ignore
		}

		m_buf[(m_head + m_size) % m_capacity] = c;
		++m_size;
	}

	push_result_t push_front(char k)
	{
		if (full())
		{
			return push_result_t::QUEUE_OVERFLOW;
		}

		m_head = (m_head + m_capacity - 1) % m_capacity;
		m_buf[m_head] = k;
		++m_size;
		return push_result_t::OK;
	}

	char front() const
	{
		assert(!empty());
		return m_buf[m_head];
	}

	char pop_front()
	{
		assert(!empty());
		char ch = m_buf[m_head];
		m_head = next(m_head);
		--m_size;
		return ch;
	}

	bool empty() const
	{
		return m_size == 0;
	}

};
