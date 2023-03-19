#ifndef _UUID_H_
#define _UUID_H_

#include <stdint.h>

typedef char uuid_string_t[37];
typedef uint8_t uuid_t[16];

struct uuid {
	uint32_t	time_low;
	uint16_t	time_mid;
	uint16_t	time_hi_and_version;
	uint16_t	clock_seq;
	uint8_t	node[6];
};

#if __cplusplus
extern "C" {
#endif
void uuid_generate_random(uuid_t out);
void uuid_unpack(const uuid_t in, struct uuid *uu);
void uuid_pack(const struct uuid *uu, uuid_t ptr);
void uuid_unparse(const uuid_t uu, uuid_string_t out);
void uuid_unparse_upper(const uuid_t uu, uuid_string_t out);
#if __cplusplus
}
#endif

#endif
