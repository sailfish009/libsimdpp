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

#ifndef LIBSIMDPP_SIMDPP_CORE_CMP_LT_H
#define LIBSIMDPP_SIMDPP_CORE_CMP_LT_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/core/bit_xor.h>
#include <simdpp/null/compare.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

/// @{
/** Compares the values of two signed int8x16 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xff : 0x0
    ...
    rN = (aN < bN) ? 0xff : 0x0
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
inline mask_int8x16 cmp_lt(int8x16 a, int8x16 b)
{
#if SIMDPP_USE_NULL
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_cmplt_epi8(a, b);
#elif SIMDPP_USE_NEON
    return vcltq_s8(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_cmplt((__vector int8_t)a, (__vector int8_t)b);
#endif
}

inline mask_int8x32 cmp_lt(int8x32 a, int8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_cmpgt_epi8(b, a);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_int8x32, cmp_lt, a, b);
#endif
}
/// @}

/// @{
/** Compares the values of two unsigned int8x16 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xff : 0x0
    ...
    rN = (aN < bN) ? 0xff : 0x0
    @endcode

    @par 128-bit version:
    @icost{SSE2-AVX2, 3-4}
    @icost{XOP, 1}

    @par 256-bit version:
    @icost{SSE2-AVX, 6-7}
    @icost{AVX2, 3-4}
    @icost{XOP, NEON, ALTIVEC, 2}
*/
inline mask_int8x16 cmp_lt(uint8x16 a, uint8x16 b)
{
#if SIMDPP_USE_NULL
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_XOP
    return _mm_comlt_epu8(a, b);
#elif SIMDPP_USE_SSE2
    uint8x16 bias = uint8x16::make_const(0x80);
    a = bit_xor(a, bias); // sub
    b = bit_xor(b, bias); // sub
    return _mm_cmplt_epi8(a, b);
#elif SIMDPP_USE_NEON
    return vcltq_u8(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_cmplt((__vector uint8_t)a, (__vector uint8_t)b);
#endif
}

inline mask_int8x32 cmp_lt(uint8x32 a, uint8x32 b)
{
#if SIMDPP_USE_AVX2
    uint8x32 bias = uint8x32::make_const(0x80);
    a = bit_xor(a, bias); // sub
    b = bit_xor(b, bias); // sub
    return _mm256_cmpgt_epi8(b, a);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_int8x32, cmp_lt, a, b);
#endif
}
/// @}

/// @{
/** Compares the values of two signed int16x8 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xffff : 0x0
    ...
    rN = (aN < bN) ? 0xffff : 0x0
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
inline mask_int16x8 cmp_lt(int16x8 a, int16x8 b)
{
#if SIMDPP_USE_NULL
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_cmplt_epi16(a, b);
#elif SIMDPP_USE_NEON
    return vcltq_s16(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_cmplt((__vector int16_t)a, (__vector int16_t)b);
#endif
}

inline mask_int16x16 cmp_lt(int16x16 a, int16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_cmpgt_epi16(b, a);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_int16x16, cmp_lt, a, b);
#endif
}
/// @}

/// @{
/** Compares the values of two unsigned int16x8 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xffff : 0x0
    ...
    rN = (aN < bN) ? 0xffff : 0x0
    @endcode

    @par 128-bit version:
    @icost{SSE2-AVX2, 3-4}
    @icost{XOP, 1}

    @par 256-bit version:
    @icost{SSE2-AVX, 6-7}
    @icost{AVX2, 3-4}
    @icost{XOP, NEON, ALTIVEC, 2}
*/
inline mask_int16x8 cmp_lt(uint16x8 a, uint16x8 b)
{
#if SIMDPP_USE_NULL
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_XOP
    return _mm_comlt_epu16(a, b);
#elif SIMDPP_USE_SSE2
    uint16x8 bias = uint16x8::make_const(0x8000);
    a = bit_xor(a, bias); // sub
    b = bit_xor(b, bias); // sub
    return _mm_cmplt_epi16(a, b);
#elif SIMDPP_USE_NEON
    return vcltq_u16(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_cmplt((__vector uint16_t)a, (__vector uint16_t)b);
#endif
}

inline mask_int16x16 cmp_lt(uint16x16 a, uint16x16 b)
{
#if SIMDPP_USE_AVX2
    uint16x16 bias = uint16x16::make_const(0x8000);
    a = bit_xor(a, bias); // sub
    b = bit_xor(b, bias); // sub
    return _mm256_cmpgt_epi16(b, a);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_int16x16, cmp_lt, a, b);
#endif
}
/// @}

/// @{
/** Compares the values of two signed int32x4 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xffffffff : 0x0
    ...
    rN = (aN < bN) ? 0xffffffff : 0x0
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
inline mask_int32x4 cmp_lt(int32x4 a, int32x4 b)
{
#if SIMDPP_USE_NULL
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_cmplt_epi32(a, b);
#elif SIMDPP_USE_NEON
    return vcltq_s32(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_cmplt((__vector int32_t)a, (__vector int32_t)b);
#endif
}

inline mask_int32x8 cmp_lt(int32x8 a, int32x8 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_cmpgt_epi32(b, a);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_int32x8, cmp_lt, a, b);
#endif
}
/// @}

/// @{
/** Compares the values of two unsigned int32x4 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xffffffff : 0x0
    ...
    rN = (aN < bN) ? 0xffffffff : 0x0
    @endcode

    @par 128-bit version:
    @icost{SSE2-AVX2, 3-4}
    @icost{XOP, 1}

    @par 256-bit version:
    @icost{SSE2-AVX, 6-7}
    @icost{AVX2, 3-4}
    @icost{XOP, NEON, ALTIVEC, 2}
*/
inline mask_int32x4 cmp_lt(uint32x4 a, uint32x4 b)
{
#if SIMDPP_USE_NULL
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_XOP
    return _mm_comlt_epu32(a, b);
#elif SIMDPP_USE_SSE2
    uint32x4 bias = uint32x4::make_const(0x80000000);
    a = bit_xor(a, bias); // sub
    b = bit_xor(b, bias); // sub
    return _mm_cmplt_epi32(a, b);
#elif SIMDPP_USE_NEON
    return vcltq_u32(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_cmplt((__vector uint32_t)a, (__vector uint32_t)b);
#endif
}

inline mask_int32x8 cmp_lt(uint32x8 a, uint32x8 b)
{
#if SIMDPP_USE_AVX2
    uint32x8 bias = uint32x8::make_const(0x80000000);
    a = bit_xor(a, bias); // sub
    b = bit_xor(b, bias); // sub
    return _mm256_cmpgt_epi32(b, a);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_int32x8, cmp_lt, a, b);
#endif
}
/// @}

/// @{
/** Compares the values of two float32x4 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xffffffff : 0x0
    ...
    rN = (aN < bN) ? 0xffffffff : 0x0
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
inline mask_float32x4 cmp_lt(float32x4 a, float32x4 b)
{
#if SIMDPP_USE_NULL
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_AVX
    return _mm_cmp_ps(a, b, _CMP_LT_OQ);
#elif SIMDPP_USE_SSE2
    return _mm_cmplt_ps(a, b);
#elif SIMDPP_USE_NEON
    return vcltq_f32(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_cmplt((__vector float)a, (__vector float)b);
#endif
}

inline mask_float32x8 cmp_lt(float32x8 a, float32x8 b)
{
#if SIMDPP_USE_AVX
    return _mm256_cmp_ps(a, b, _CMP_LT_OQ);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_float32x8, cmp_lt, a, b);
#endif
}
/// @}

/// @{
/** Compares the values of two float64x2 vectors for less-than

    @code
    r0 = (a0 < b0) ? 0xffffffffffffffff : 0x0
    ...
    rN = (aN < bN) ? 0xffffffffffffffff : 0x0
    @endcode

    @par 128-bit version:
    @novec{NEON, ALTIVEC}

    @par 256-bit version:
    @novec{NEON, ALTIVEC}
    @icost{SSE2-SSE4.1, 2}
*/
inline mask_float64x2 cmp_lt(float64x2 a, float64x2 b)
{
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    return null::cmp_lt(a, b);
#elif SIMDPP_USE_AVX
    return _mm_cmp_pd(a, b, _CMP_LT_OQ);
#elif SIMDPP_USE_SSE2
    return _mm_cmplt_pd(a, b);
#endif
}

inline mask_float64x4 cmp_lt(float64x4 a, float64x4 b)
{
#if SIMDPP_USE_AVX
    return _mm256_cmp_pd(a, b, _CMP_LT_OQ);
#else
    SIMDPP_VEC_ARRAY_IMPL2(mask_float64x4, cmp_lt, a, b);
#endif
}
/// @}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

