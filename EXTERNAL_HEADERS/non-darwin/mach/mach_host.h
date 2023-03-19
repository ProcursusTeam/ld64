#pragma once

#include <mach/message.h>
#include <mach/mach_types.h>

typedef int *host_info_t;

#define HOST_VM_INFO 0
inline mach_port_t
mach_host_self(void) { return 0; }

inline kern_return_t
host_statistics(mach_port_t a, int b, host_info_t c, mach_msg_type_number_t *d)
{
	(void)a;
	(void)b;
	(void)c;
	(void)d;
	return 0;
}
