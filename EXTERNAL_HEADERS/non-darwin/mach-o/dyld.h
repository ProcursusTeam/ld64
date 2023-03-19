/*
 * Copyright (c) 1999-2008 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#ifndef _MACH_O_DYLD_H_
#define _MACH_O_DYLD_H_


#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <mach-o/loader.h>
#include <Availability.h>

#if __cplusplus
extern "C" {
#endif 

/*
 * _NSGetExecutablePath() copies the path of the main executable into the buffer. The bufsize parameter
 * should initially be the size of the buffer.  The function returns 0 if the path was successfully copied,
 * and *bufsize is left unchanged. It returns -1 if the buffer is not large enough, and *bufsize is set 
 * to the size required. 
 * 
 * Note that _NSGetExecutablePath will return "a path" to the executable not a "real path" to the executable. 
 * That is the path may be a symbolic link and not the real file. With deep directories the total bufsize 
 * needed could be more than MAXPATHLEN.
 */
extern int _NSGetExecutablePath(char* buf, uint32_t* bufsize);

#if __cplusplus
}
#endif 

#endif /* _MACH_O_DYLD_H_ */
