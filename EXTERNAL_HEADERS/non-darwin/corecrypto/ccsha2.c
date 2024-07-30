#include <corecrypto/ccdigest.h>
#include <corecrypto/ccsha2.h>

#include <openssl/sha.h>

static void ccsha256_init(struct ccdigest_ctx *ctx_) {
	SHA256_CTX *ctx = (SHA256_CTX *)ctx_;
	SHA256_Init(ctx);
}

static void ccsha256_update(struct ccdigest_ctx *ctx_, size_t size, const void *data) {
	SHA256_CTX *ctx = (SHA256_CTX *)ctx_;
	SHA256_Update(ctx, (const uint8_t *)data, size);
}

static void ccsha256_final(struct ccdigest_ctx *ctx_, void *digest) {
	SHA256_CTX *ctx = (SHA256_CTX *)ctx_;
	SHA256_Final(digest, ctx);
}

static const struct ccdigest_info ccsha256_info = {
	sizeof(SHA256_CTX),
	ccsha256_init,
	ccsha256_update,
	ccsha256_final
};

const struct ccdigest_info *ccsha256_di(void) {
	return &ccsha256_info;
}
