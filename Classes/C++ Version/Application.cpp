/*
 * Application.cpp
 *
 *  Created on: Oct 31, 2015
 *      Author: rmerriam
 */

#include "Application.h"
//---------------------------------------------------------------------------------------------------------------------
had::RingBuffer r_buffer;

//---------------------------------------------------------------------------------------------------------------------
void setup() {
}
//---------------------------------------------------------------------------------------------------------------------
void loop() {
//	had::RingBuffer r_buffer;

	uint8_t tempCharStorage;

	for (int i = 0; r_buffer.bufferWrite('A' + i) == had::RingBuffer::OK; i++) {
	}

	while (r_buffer.bufferRead(tempCharStorage) == had::RingBuffer::OK) {
	}
}
