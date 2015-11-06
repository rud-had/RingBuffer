/*
 * RingBuffer.cpp
 *
 *  Created on: Oct 31, 2015
 *      Author: rmerriam
 */
#include "Application.h"

namespace had {
//---------------------------------------------------------------------------------------------------------------------
RingBuffer::RingBuffer() :
		newest_index(), oldest_index() {
}
//---------------------------------------------------------------------------------------------------------------------
inline uint8_t nextIndex(uint8_t index) {
	return ++index % bufferSize;
}
//---------------------------------------------------------------------------------------------------------------------
RingBuffer::BufferStatus RingBuffer::bufferWrite(const uint8_t byte) {

	uint8_t next_index = nextIndex(newest_index);

	if (next_index == oldest_index) {
		return FULL;
	}

	data[newest_index] = byte;
	newest_index = next_index;

	return OK;
}
//---------------------------------------------------------------------------------------------------------------------
RingBuffer::BufferStatus RingBuffer::bufferRead(uint8_t& byte) {
	if (newest_index == oldest_index) {
		return EMPTY;
	}

	byte = data[oldest_index];
	oldest_index = nextIndex(oldest_index);

	return OK;
}
}

