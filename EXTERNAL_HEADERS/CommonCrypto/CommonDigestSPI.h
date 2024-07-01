#ifndef	_COMPAT_CC_DigestSPI_H_
#define _COMPAT_CC_DigestSPI_H_

#include <stdint.h>
#include <sys/types.h>

__BEGIN_DECLS

#define kCCDigestSHA256 10

typedef uint32_t CCDigestAlgorithm;

int
CCDigest(CCDigestAlgorithm algorithm,
         const uint8_t *data, size_t length, uint8_t *output);

__END_DECLS

#endif
