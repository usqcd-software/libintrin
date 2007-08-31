#include "sse_mult_su3_mat_vec_sum_4dir.h"
#include <xmmintrin.h>

#ifdef __cplusplus
extern "C" { 
#endif

void
intrin_sse_mult_su3_mat_vec_sum_4dir(su3_matrixf aa[4], su3_vectorf* bb0, su3_vectorf* bb1, su3_vectorf* bb2, su3_vectorf* bb3, su3_vectorf* cc)
{

	 /* XMM Variables */
	 __m128 xmm2, xmm3, xmm0, xmm1, xmm6, xmm7, xmm4, xmm5;

	xmm0 = _mm_loadl_pi(xmm0, (__m64 *)&((bb0)->c[0]) );
	xmm1 = _mm_loadl_pi(xmm1, (__m64 *)&((bb0)->c[1]) );
	xmm2 = _mm_loadl_pi(xmm2, (__m64 *)&((bb0)->c[2]) );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0x44 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x44 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0x44 );
	xmm3 = _mm_load_ss((float *)&((aa)[0].e[0][0].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[1][0].real) );
	xmm3 = _mm_shuffle_ps( xmm3, xmm7, 0x00 );
	xmm4 = _mm_load_ss((float *)&((aa)[0].e[0][1].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[1][1].real) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm4 = _mm_mul_ps( xmm4, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[0].e[0][2].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[1][2].real) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[2][0].real) );
	xmm6 = _mm_load_ss((float *)&((aa)[0].e[2][1].real) );
	xmm6 = _mm_shuffle_ps( xmm6, xmm7, 0x00 );
	xmm6 = _mm_mul_ps( xmm6, xmm1 );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0xB1 );
	 	 xmm0 = _mm_xor_ps( xmm0, _sse_sgn13.xmm );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x11 );
	 	 xmm1 = _mm_xor_ps( xmm1, _sse_sgn13.xmm );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB1 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn13.xmm );
	xmm4 = _mm_load_ss((float *)&((aa)[0].e[0][0].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[1][0].imag) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm4 = _mm_mul_ps( xmm4, xmm0 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[0].e[0][1].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[1][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm5 = _mm_load_ss((float *)&((aa)[0].e[0][2].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[1][2].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	_mm_storeu_ps((float *)&((cc)->c[0]), xmm3 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[0].e[2][0].imag) );
	xmm5 = _mm_load_ss((float *)&((aa)[0].e[2][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm6 = _mm_add_ps( xmm6, xmm5 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB4 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn4.xmm );
	xmm7 = _mm_loadl_pi(xmm7, (__m64 *)&((aa)[0].e[2][2]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0x05 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	xmm7 = xmm6 ; 
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	_mm_storel_pi((__m64 *)&((cc)->c[2]), xmm6 );
	xmm0 = _mm_loadl_pi(xmm0, (__m64 *)&((bb1)->c[0]) );
	xmm1 = _mm_loadl_pi(xmm1, (__m64 *)&((bb1)->c[1]) );
	xmm2 = _mm_loadl_pi(xmm2, (__m64 *)&((bb1)->c[2]) );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0x44 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x44 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0x44 );
	xmm3 = _mm_load_ss((float *)&((aa)[1].e[0][0].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[1][0].real) );
	xmm3 = _mm_shuffle_ps( xmm3, xmm7, 0x00 );
	xmm4 = _mm_load_ss((float *)&((aa)[1].e[0][1].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[1][1].real) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm4 = _mm_mul_ps( xmm4, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[1].e[0][2].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[1][2].real) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[2][0].real) );
	xmm6 = _mm_load_ss((float *)&((aa)[1].e[2][1].real) );
	xmm6 = _mm_shuffle_ps( xmm6, xmm7, 0x00 );
	xmm6 = _mm_mul_ps( xmm6, xmm1 );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0xB1 );
	 	 xmm0 = _mm_xor_ps( xmm0, _sse_sgn13.xmm );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x11 );
	 	 xmm1 = _mm_xor_ps( xmm1, _sse_sgn13.xmm );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB1 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn13.xmm );
	xmm4 = _mm_load_ss((float *)&((aa)[1].e[0][0].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[1][0].imag) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm4 = _mm_mul_ps( xmm4, xmm0 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[1].e[0][1].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[1][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm5 = _mm_load_ss((float *)&((aa)[1].e[0][2].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[1][2].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm7 = _mm_loadu_ps((float *)&((cc)->c[0]) );
	xmm7 = _mm_add_ps( xmm7, xmm3 );
	_mm_storeu_ps((float *)&((cc)->c[0]), xmm7 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[1].e[2][0].imag) );
	xmm5 = _mm_load_ss((float *)&((aa)[1].e[2][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm6 = _mm_add_ps( xmm6, xmm5 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB4 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn4.xmm );
	xmm7 = _mm_loadl_pi(xmm7, (__m64 *)&((aa)[1].e[2][2]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0x05 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	xmm7 = xmm6 ; 
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	xmm7 = _mm_loadl_pi(xmm7, (__m64 *)&((cc)->c[2]) );
	xmm7 = _mm_add_ps( xmm7, xmm6 );
	_mm_storel_pi((__m64 *)&((cc)->c[2]), xmm7 );
	xmm0 = _mm_loadl_pi(xmm0, (__m64 *)&((bb2)->c[0]) );
	xmm1 = _mm_loadl_pi(xmm1, (__m64 *)&((bb2)->c[1]) );
	xmm2 = _mm_loadl_pi(xmm2, (__m64 *)&((bb2)->c[2]) );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0x44 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x44 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0x44 );
	xmm3 = _mm_load_ss((float *)&((aa)[2].e[0][0].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[1][0].real) );
	xmm3 = _mm_shuffle_ps( xmm3, xmm7, 0x00 );
	xmm4 = _mm_load_ss((float *)&((aa)[2].e[0][1].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[1][1].real) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm4 = _mm_mul_ps( xmm4, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[2].e[0][2].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[1][2].real) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[2][0].real) );
	xmm6 = _mm_load_ss((float *)&((aa)[2].e[2][1].real) );
	xmm6 = _mm_shuffle_ps( xmm6, xmm7, 0x00 );
	xmm6 = _mm_mul_ps( xmm6, xmm1 );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0xB1 );
	 	 xmm0 = _mm_xor_ps( xmm0, _sse_sgn13.xmm );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x11 );
	 	 xmm1 = _mm_xor_ps( xmm1, _sse_sgn13.xmm );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB1 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn13.xmm );
	xmm4 = _mm_load_ss((float *)&((aa)[2].e[0][0].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[1][0].imag) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm4 = _mm_mul_ps( xmm4, xmm0 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[2].e[0][1].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[1][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm5 = _mm_load_ss((float *)&((aa)[2].e[0][2].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[1][2].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm7 = _mm_loadu_ps((float *)&((cc)->c[0]) );
	xmm7 = _mm_add_ps( xmm7, xmm3 );
	_mm_storeu_ps((float *)&((cc)->c[0]), xmm7 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[2].e[2][0].imag) );
	xmm5 = _mm_load_ss((float *)&((aa)[2].e[2][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm6 = _mm_add_ps( xmm6, xmm5 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB4 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn4.xmm );
	xmm7 = _mm_loadl_pi(xmm7, (__m64 *)&((aa)[2].e[2][2]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0x05 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	xmm7 = xmm6 ; 
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	xmm7 = _mm_loadl_pi(xmm7, (__m64 *)&((cc)->c[2]) );
	xmm7 = _mm_add_ps( xmm7, xmm6 );
	_mm_storel_pi((__m64 *)&((cc)->c[2]), xmm7 );
	xmm0 = _mm_loadl_pi(xmm0, (__m64 *)&((bb3)->c[0]) );
	xmm1 = _mm_loadl_pi(xmm1, (__m64 *)&((bb3)->c[1]) );
	xmm2 = _mm_loadl_pi(xmm2, (__m64 *)&((bb3)->c[2]) );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0x44 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x44 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0x44 );
	xmm3 = _mm_load_ss((float *)&((aa)[3].e[0][0].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[1][0].real) );
	xmm3 = _mm_shuffle_ps( xmm3, xmm7, 0x00 );
	xmm4 = _mm_load_ss((float *)&((aa)[3].e[0][1].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[1][1].real) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm4 = _mm_mul_ps( xmm4, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[3].e[0][2].real) );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[1][2].real) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[2][0].real) );
	xmm6 = _mm_load_ss((float *)&((aa)[3].e[2][1].real) );
	xmm6 = _mm_shuffle_ps( xmm6, xmm7, 0x00 );
	xmm6 = _mm_mul_ps( xmm6, xmm1 );
	xmm0 = _mm_shuffle_ps( xmm0, xmm0, 0xB1 );
	 	 xmm0 = _mm_xor_ps( xmm0, _sse_sgn13.xmm );
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0x11 );
	 	 xmm1 = _mm_xor_ps( xmm1, _sse_sgn13.xmm );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB1 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn13.xmm );
	xmm4 = _mm_load_ss((float *)&((aa)[3].e[0][0].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[1][0].imag) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x00 );
	xmm4 = _mm_mul_ps( xmm4, xmm0 );
	xmm3 = _mm_add_ps( xmm3, xmm4 );
	xmm5 = _mm_load_ss((float *)&((aa)[3].e[0][1].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[1][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm5 = _mm_load_ss((float *)&((aa)[3].e[0][2].imag) );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[1][2].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm2 );
	xmm3 = _mm_add_ps( xmm3, xmm5 );
	xmm7 = _mm_loadu_ps((float *)&((cc)->c[0]) );
	xmm7 = _mm_add_ps( xmm7, xmm3 );
	_mm_storeu_ps((float *)&((cc)->c[0]), xmm7 );
	xmm1 = _mm_shuffle_ps( xmm1, xmm0, 0x44 );
	xmm7 = _mm_load_ss((float *)&((aa)[3].e[2][0].imag) );
	xmm5 = _mm_load_ss((float *)&((aa)[3].e[2][1].imag) );
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x00 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm6 = _mm_add_ps( xmm6, xmm5 );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xB4 );
	 	 xmm2 = _mm_xor_ps( xmm2, _sse_sgn4.xmm );
	xmm7 = _mm_loadl_pi(xmm7, (__m64 *)&((aa)[3].e[2][2]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0x05 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	xmm7 = xmm6 ; 
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm6 = _mm_add_ps( xmm6, xmm7 );
	xmm7 = _mm_loadl_pi(xmm7, (__m64 *)&((cc)->c[2]) );
	xmm7 = _mm_add_ps( xmm7, xmm6 );
	_mm_storel_pi((__m64 *)&((cc)->c[2]), xmm7 );
}

#ifdef __cplusplus
}; 
#endif

