/*
 * Buffer->c
 *
 *  Created on: Oct 30, 2015
 *      Author: rmerriam
 */
#include "Application.h"
//---------------------------------------------------------------------------------------------------------------------
 void initBuffer(struct LifoBuffer* b) {
	b->newest_index = 0;
	b->oldest_index = 0;
}
//---------------------------------------------------------------------------------------------------------------------
uint8_t nextIndex(uint8_t index) {
	return ++index % BUFFER_SIZE;
}
//---------------------------------------------------------------------------------------------------------------------
enum BufferStatus bufferWrite(struct LifoBuffer* buffer, uint8_t byte) {

	uint8_t next_index = nextIndex(buffer->newest_index);

	if (next_index == buffer->oldest_index) {
		return BUFFER_FULL;
	}

	buffer->data[buffer->newest_index] = byte;
	buffer->newest_index = next_index;

	return BUFFER_OK;
}
//---------------------------------------------------------------------------------------------------------------------
enum BufferStatus bufferRead(struct LifoBuffer* buffer, uint8_t *byte) {
	if (buffer->newest_index == buffer->oldest_index) {
		return BUFFER_EMPTY;
	}

	*byte = buffer->data[buffer->oldest_index];
	buffer->oldest_index = nextIndex(buffer->oldest_index);

	return BUFFER_OK;
}
//---------------------------------------------------------------------------------------------------------------------
//void dumpBuffer(struct Buffer* buffer) {
//
//	for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
//		if (buffer->oldest_index == buffer->newest_index
//				&& buffer->newest_index == i) {
//			printf("=");
//		} else if (buffer->oldest_index == i) {
//			printf("[");
//		} else if (buffer->newest_index == i) {
//			printf("]");
//		} else {
//			printf("v");
//		}
//	}
//	printf("\n");
//
//	for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
//		printf("%c", buffer->data[i]);
//	}
//	printf("\n");
//}
