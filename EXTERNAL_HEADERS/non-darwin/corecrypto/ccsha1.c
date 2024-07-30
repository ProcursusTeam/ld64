#include <corecrypto/ccdigest.h>
#include <corecrypto/ccsha1.h>

#include <openssl/sha.h>

static void ccsha1_init(struct ccdigest_ctx *ctx_) {
	SHA_CTX *ctx = (SHA_CTX *)ctx_;
	SHA1_Init(ctx);
}

static void ccsha1_update(struct ccdigest_ctx *ctx_, size_t size, const void *data) {
	SHA_CTX *ctx = (SHA_CTX *)ctx_;
	SHA1_Update(ctx, (const uint8_t *)data, size);
}

static void ccsha1_final(struct ccdigest_ctx *ctx_, void *digest) {
	SHA_CTX *ctx = (SHA_CTX *)ctx_;
	SHA1_Final(digest, ctx);
}

static const struct ccdigest_info ccsha1_info = {
	sizeof(SHA_CTX),
	ccsha1_init,
	ccsha1_update,
	ccsha1_final
};

const struct ccdigest_info *ccsha1_di(void) {
	return &ccsha1_info;
}
