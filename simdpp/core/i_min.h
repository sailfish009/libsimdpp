/*  libsimdpp
    Copyright (C) 2013  Povilas Kanapickas povilas@radix.lt
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_I_MIN_H
#define LIBSIMDPP_SIMDPP_CORE_I_MIN_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/core/blend.h>
#include <simdpp/core/cmp_lt.h>
#include <simdpp/null/math.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif


/// @{
/** Computes minimum of signed 8-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 8}
    @icost{SSE4.1-AVX, NEON, ALTIVEC, 2}
*/
inline int8x16 min(int8x16 a, int8x16 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epi8(a, b);
#elif SIMDPP_USE_SSE2
    mask_int8x16 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_s8(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_min((__vector int8_t)a, (__vector int8_t)b);
#endif
}

inline int8x32 min(int8x32 a, int8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epi8(a, b);
#else
    SIMDPP_VEC_ARRAY_IMPL2(int8x32, min, a, b);
#endif
}
/// @}

/// @{
/** Computes minimum of the unsigned 8-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
inline uint8x16 min(uint8x16 a, uint8x16 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_min_epu8(a, b);
#elif SIMDPP_USE_NEON
    return vminq_u8(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_min((__vector uint8_t)a, (__vector uint8_t)b);
#endif
}

inline uint8x32 min(uint8x32 a, uint8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epu8(a, b);
#else
    SIMDPP_VEC_ARRAY_IMPL2(uint8x32, min, a, b);
#endif
}
/// @}

/// @{
/** Computes minimum of the signed 16-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
inline int16x8 min(int16x8 a, int16x8 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_min_epi16(a, b);
#elif SIMDPP_USE_NEON
    return vminq_s16(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_min((__vector int16_t)a, (__vector int16_t)b);
#endif
}

inline int16x16 min(int16x16 a, int16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epi16(a, b);
#else
    SIMDPP_VEC_ARRAY_IMPL2(int16x16, min, a, b);
#endif
}
/// @}

/// @{
/** Computes minimum of the unsigned 16-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 6-7}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 12-13}
    @icost{SSE4.1-AVX, NEON, ALTIVEC, 2}
*/
inline uint16x8 min(uint16x8 a, uint16x8 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epu16(a, b);
#elif SIMDPP_USE_SSE2
    mask_int16x8 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_u16(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_min((__vector uint16_t)a, (__vector uint16_t)b);
#endif
}

inline uint16x16 min(uint16x16 a, uint16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epu16(a, b);
#else
    SIMDPP_VEC_ARRAY_IMPL2(uint16x16, min, a, b);
#endif
}
/// @}

/// @{
/** Computes minimum of the signed 32-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 8}
    @icost{SSE4.1-AVX, NEON, ALTIVEC, 2}
*/
inline int32x4 min(int32x4 a, int32x4 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epi32(a, b);
#elif SIMDPP_USE_SSE2
    mask_int32x4 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_s32(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_min((__vector int32_t)a, (__vector int32_t)b);
#endif
}

inline int32x8 min(int32x8 a, int32x8 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epi32(a, b);
#else
    SIMDPP_VEC_ARRAY_IMPL2(int32x8, min, a, b);
#endif
}
/// @}

/// @{
/** Computes minimum of the unsigned 32-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 6-7}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 12-13}
    @icost{SSE4.1-AVX, NEON, ALTIVEC, 2}
*/
inline uint32x4 min(uint32x4 a, uint32x4 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epu32(a, b);
#elif SIMDPP_USE_SSE2
    mask_int32x4 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_u32(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_min((__vector uint32_t)a, (__vector uint32_t)b);
#endif
}

inline uint32x8 min(uint32x8 a, uint32x8 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epu32(a, b);
#else
    SIMDPP_VEC_ARRAY_IMPL2(uint32x8, min, a, b);
#endif
}
/// @}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

