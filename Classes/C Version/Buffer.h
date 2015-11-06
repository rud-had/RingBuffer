/*
 * Buffer.h
 *
 *  Created on: Oct 30, 2015
 *      Author: rmerriam
 */

#ifndef LIFOBUFFER_H_
#define LIFOBUFFER_H_

typedef unsigned char uint8_t;

enum BufferStatus {BUFFER_OK, BUFFER_EMPTY, BUFFER_FULL};
#define BUFFER_SIZE 16

//---------------------------------------------------------------------------------------------------------------------
struct LifoBuffer {
	uint8_t data[BUFFER_SIZE];
	uint8_t newest_index;
	uint8_t oldest_index;
};
//---------------------------------------------------------------------------------------------------------------------
void initBuffer(struct LifoBuffer* buffer);
enum BufferStatus bufferWrite(struct LifoBuffer* buffer, uint8_t byte);
enum BufferStatus bufferRead(struct LifoBuffer* buffer, uint8_t *byte);

#endif /* LIFOBUFFER_H_ */
