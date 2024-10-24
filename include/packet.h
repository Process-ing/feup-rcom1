#ifndef _PACKET_H_
#define _PACKET_H_

#include <stdint.h>

#include "link_layer.h"

#define BASE_CONTROL_PACKET_SIZE     9
#define BASE_DATA_PACKET_SIZE        4
#define MAX_FILENAME_SIZE            (MAX_PAYLOAD_SIZE - BASE_CONTROL_PACKET_SIZE)
#define MAX_DATA_PACKET_PAYLOAD_SIZE (MAX_PAYLOAD_SIZE - BASE_DATA_PACKET_SIZE)

int readControlPacket(uint8_t* controlField, uint32_t *filesize, char *filename);
int readDataPacket(uint8_t *sequenceNumber, uint8_t *packetData);

int writeControlPacket(uint8_t controlField, uint32_t filesize, const char *filename);
int writeDataPacket(uint8_t sequenceNumber, uint16_t packetDataSize, const uint8_t *packetData);

#endif  // _PACKET_H_
