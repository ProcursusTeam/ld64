#ifndef __COMPAT_CORECRYPTO_CCSHA256__
#define __COMPAT_CORECRYPTO_CCSHA256__

#include <corecrypto/ccdigest.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define	CCSHA256_OUTPUT_SIZE 32
const struct ccdigest_info *ccsha256_di(void);

#ifdef __cplusplus
}
#endif

#endif /* __COMPAT_CORECRYPTO_CCSHA256__ */
