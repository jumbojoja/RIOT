/*
 * Copyright (C) 2023 TU Dresden
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    sys_hashes_sha512_256 SHA-512/256
 * @ingroup     sys_hashes_unkeyed
 * @brief       Implementation of the SHA-512/256 hashing function
 * @{
 *
 * @file
 * @brief       Header definitions for the SHA512/256 hash function
 *
 * @author      Mikolai Gütschow <mikolai.guetschow@tu-dresden.de>
 */

#ifndef HASHES_SHA512_256_H
#define HASHES_SHA512_256_H

#include <inttypes.h>
#include <stddef.h>

#include "hashes/sha512_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Length of SHA512_256 digests in bytes
 */
#define SHA512_256_DIGEST_LENGTH (32)

/**
 * @brief 1024 Bit (128 Byte) internally used block size for sha512_256
 */
#define SHA512_256_INTERNAL_BLOCK_SIZE (128)

/**
 * @brief Context for cipher operations based on sha512_256
 */
typedef sha512_common_context_t sha512_256_context_t;

/**
 * @brief SHA-512/256 initialization.  Begins a SHA-512/256 operation.
 *
 * @param ctx  sha512_256_context_t handle to init, must not be NULL
 */
void sha512_256_init(sha512_256_context_t *ctx);

/**
 * @brief Add bytes into the hash
 *
 * @param ctx      sha512_256_context_t handle to use, must not be NULL
 * @param[in] data Input data
 * @param[in] len  Length of @p data
 */
static inline void sha512_256_update(sha512_256_context_t *ctx, const void *data, size_t len)
{
    sha512_common_update(ctx, data, len);
}

/**
 * @brief SHA-512/256 finalization.  Pads the input data, exports the hash value,
 * and clears the context state.
 *
 * @param ctx           sha512_256_context_t handle to use, must not be NULL
 * @param[out] digest   pointer to resulting digest, this is the hash of all the bytes.
 *                      Length must be at least SHA512_256_DIGEST_LENGTH
 */
static inline void sha512_256_final(sha512_256_context_t *ctx, void *digest)
{
    sha512_common_final(ctx, digest, SHA512_256_DIGEST_LENGTH);
}

/**
 * @brief A wrapper function to simplify the generation of a hash. This is
 * useful for generating sha512_256 for one single buffer in a single step.
 *
 * @param[in] data      pointer to the buffer to generate hash from
 * @param[in] len       length of the buffer
 * @param[out] digest   optional pointer to an array for the result, length must
 *                      be at least SHA512_256_DIGEST_LENGTH
 */
void sha512_256(const void *data, size_t len, void *digest);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* HASHES_SHA512_256_H */
