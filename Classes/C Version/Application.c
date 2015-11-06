/*
 * Application.c
 *
 *  Created on: Oct 31, 2015
 *      Author: rmerriam
 */

#include "Application.h"
//---------------------------------------------------------------------------------------------------------------------
struct LifoBuffer buffer;
//---------------------------------------------------------------------------------------------------------------------
void setup() {
	initBuffer(&buffer);
}
//---------------------------------------------------------------------------------------------------------------------
void loop() {
//	struct LifoBuffer buffer;
//	initBuffer(&buffer);

	uint8_t tempCharStorage;

	uint8_t i = 0;
	for (; bufferWrite(&buffer, 'A' + i) == BUFFER_OK; i++) {
	}

	while (bufferRead(&buffer, &tempCharStorage) == BUFFER_OK) {
	}
}
