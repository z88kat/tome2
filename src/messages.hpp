#pragma once

#include "h-basic.hpp"
#include "message.hpp"

#include <cassert>
#include <deque>
#include <cstddef>

/**
 * Game message buffer — fixed-capacity circular buffer backed by a deque.
 */
class Messages final {

private:
	std::deque<message> m_buffer;
	std::size_t m_capacity;

public:

	/**
	 * Create message buffer with space for given
	 * number of messages.
	 */
	explicit Messages(std::size_t n)
		: m_capacity(n)
	{
	}

	/**
	 * Get the current number of messages.
	 */
	s16b size() const;

	/**
	 * Get message of given age. Age must be
	 * in the half-open interval [0, message_num).
	 *
	 * The reference is only valid as long as
	 * no messages are added.
	 */
	message const &at(int age) const;

	/**
	 * Add a message.
	 */
	void add(const char *msg, byte color);

	/**
	 * Add a message.
	 */
	void add(std::string const &msg, byte color);

	/**
	 * Add a message.
	 */
	void add(message const &);

};
