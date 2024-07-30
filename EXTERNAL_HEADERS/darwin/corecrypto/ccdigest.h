#ifndef _CORECRYPTO_CCDIGEST_H_
#define _CORECRYPTO_CCDIGEST_H_

/* xnu-10063.121.3 corecrypto/ccdigest.h */

#include <stdint.h>
#include <stddef.h>

#define CC_ALIGNED(x) __attribute__((aligned(x)))
typedef int cc_impl_t;

typedef struct ccdigest_state *ccdigest_state_t;
typedef struct ccdigest_ctx *ccdigest_ctx_t;

struct ccdigest_info {
    size_t output_size;
    size_t state_size;
    size_t block_size;
    size_t oid_size;
    const unsigned char *oid;
    const void *initial_state;
    void(*compress)(ccdigest_state_t state, size_t nblocks,
                    const void *data);
    void(*final)(const struct ccdigest_info *di, ccdigest_ctx_t ctx,
                 unsigned char *digest);
    cc_impl_t impl;
};

struct ccdigest_ctx {
    uint8_t state[1];
} CC_ALIGNED(8);

#define ccdigest_ctx_size(_state_size_, _block_size_)  ((_state_size_) + sizeof(uint64_t) + (_block_size_) + sizeof(unsigned int))
#define cc_ctx_n(_type_, _size_) ((_size_ + sizeof(_type_) - 1) / sizeof(_type_))
#define ccdigest_di_size(_di_)  (ccdigest_ctx_size((_di_)->state_size, (_di_)->block_size))
#define ccdigest_di_decl(_di_, _name_)  struct ccdigest_ctx _name_ [cc_ctx_n(struct ccdigest_ctx, ccdigest_di_size(_di_))];

void ccdigest_init(const struct ccdigest_info *di, ccdigest_ctx_t ctx);
void ccdigest_update(const struct ccdigest_info *di, ccdigest_ctx_t ctx,
                     size_t len, const void *data);
inline void ccdigest_final(const struct ccdigest_info *di, ccdigest_ctx_t ctx, unsigned char *digest)
{
    di->final(di,ctx,digest);
}
#endif
