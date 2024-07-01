/*
 * unparse.c -- convert a UUID to string
 *
 * Copyright (C) 1996, 1997 Theodore Ts'o.
 *
 * %Begin-Header%
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, and the entire permission notice in its entirety,
 *    including the disclaimer of warranties.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ALL OF
 * WHICH ARE HEREBY DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * %End-Header%
 */

#include <stdio.h>

#include "uuid.h"

void uuid_unparse(const uuid_t uu, uuid_string_t out)
{
	const uint8_t *uuid_array = (const uint8_t *)uu;
	unsigned int uuid_index;
	static const char *fmt = "0123456789abcdef";
	
	for ( uuid_index = 0; uuid_index < sizeof(uuid_string_t); ++uuid_index ) {
		// insert '-' after the 4th, 6th, 8th, and 10th uuid byte
		switch (uuid_index) {
		case 4:
		case 6:
		case 8:
		case 10:
			*out++ = '-';
			break;
		}
		// insert uuid byte as two hex characters
		*out++ = fmt[*uuid_array >> 4];
		*out++ = fmt[*uuid_array++ & 0xF];
	}
	*out = 0;
}

void uuid_unparse_upper(const uuid_t uu, uuid_string_t out)
{
	const uint8_t *uuid_array = (const uint8_t *)uu;
	unsigned int uuid_index;
	static const char *fmt = "0123456789ABCDEF";
	
	for ( uuid_index = 0; uuid_index < sizeof(uuid_string_t); ++uuid_index ) {
		// insert '-' after the 4th, 6th, 8th, and 10th uuid byte
		switch (uuid_index) {
		case 4:
		case 6:
		case 8:
		case 10:
			*out++ = '-';
			break;
		}
		// insert uuid byte as two hex characters
		*out++ = fmt[*uuid_array >> 4];
		*out++ = fmt[*uuid_array++ & 0xF];
	}
	*out = 0;
}
