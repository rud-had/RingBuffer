/*
 * RingBuffer.h
 #include "Arduino.h"
 *
 *  Created on: Oct 31, 2015
 *      Author: rmerriam
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_
namespace had {

using uint8_t = unsigned char;
const uint8_t bufferSize = 16;

class RingBuffer {
	uint8_t data[bufferSize];
	uint8_t newest_index;
	uint8_t oldest_index;

public:
	enum BufferStatus {
		OK, EMPTY, FULL
	};

	RingBuffer();

	BufferStatus bufferWrite(const uint8_t byte);
	enum BufferStatus bufferRead(uint8_t& byte);
};
}
#endif /* RINGBUFFER_H_ */
