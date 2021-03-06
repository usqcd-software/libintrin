#include "sse_mult_adj_su3_mat_vec_4dir.h"
#include <xmmintrin.h>

#ifdef __cplusplus
extern "C" { 
#endif

void
intrin_sse_mult_adj_su3_mat_vec_4dir(su3_matrixf aa[4], su3_vectorf *bb, su3_vectorf cc[4])
{

	 /* XMM Variables */
	 __m128 xmm2, xmm3, xmm0, xmm1, xmm6, xmm7, xmm4, xmm5;

	xmm0 = _mm_loadu_ps((float *)&((bb)->c[0]) );
	xmm1 = xmm0 ; 
	xmm1 = _mm_shuffle_ps( xmm1, xmm1, 0xB1 );
	xmm2 = _mm_loadu_ps((float *)&((bb)->c[1]) );
	xmm2 = _mm_shuffle_ps( xmm2, xmm2, 0xEB );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[0].e[0][0]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[0].e[1][0]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[0].e[2][0]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[0].e[0][1]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[0].e[1][1]) );
	xmm7 = _mm_loadh_pi(xmm7, (__m64 *)&((aa)[0].e[2][1]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm7 = _mm_add_ps( xmm7, xmm5 );
	xmm7 = _mm_add_ps( xmm7, xmm6 );
	xmm5 = xmm4 ; 
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x22 );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x77 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeu_ps((float *)&((cc)[0].c[0]), xmm5 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[0].e[0][2]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[0].e[1][2]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[0].e[2][2]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm5 = xmm4 ; 
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0x77 );
	xmm5 = _mm_shuffle_ps( xmm5, xmm5, 0x22 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeh_pi((__m64 *)&((cc)[0].c[2]), xmm5 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[1].e[0][0]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[1].e[1][0]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[1].e[2][0]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[1].e[0][1]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[1].e[1][1]) );
	xmm7 = _mm_loadh_pi(xmm7, (__m64 *)&((aa)[1].e[2][1]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm7 = _mm_add_ps( xmm7, xmm5 );
	xmm7 = _mm_add_ps( xmm7, xmm6 );
	xmm5 = xmm4 ; 
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x22 );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x77 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeu_ps((float *)&((cc)[1].c[0]), xmm5 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[1].e[0][2]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[1].e[1][2]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[1].e[2][2]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm5 = xmm4 ; 
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0x77 );
	xmm5 = _mm_shuffle_ps( xmm5, xmm5, 0x22 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeh_pi((__m64 *)&((cc)[1].c[2]), xmm5 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[2].e[0][0]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[2].e[1][0]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[2].e[2][0]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[2].e[0][1]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[2].e[1][1]) );
	xmm7 = _mm_loadh_pi(xmm7, (__m64 *)&((aa)[2].e[2][1]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm7 = _mm_add_ps( xmm7, xmm5 );
	xmm7 = _mm_add_ps( xmm7, xmm6 );
	xmm5 = xmm4 ; 
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x22 );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x77 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeu_ps((float *)&((cc)[2].c[0]), xmm5 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[2].e[0][2]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[2].e[1][2]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[2].e[2][2]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm5 = xmm4 ; 
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0x77 );
	xmm5 = _mm_shuffle_ps( xmm5, xmm5, 0x22 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeh_pi((__m64 *)&((cc)[2].c[2]), xmm5 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[3].e[0][0]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[3].e[1][0]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[3].e[2][0]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[3].e[0][1]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[3].e[1][1]) );
	xmm7 = _mm_loadh_pi(xmm7, (__m64 *)&((aa)[3].e[2][1]) );
	xmm7 = _mm_shuffle_ps( xmm7, xmm7, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm7 = _mm_mul_ps( xmm7, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm7 = _mm_add_ps( xmm7, xmm5 );
	xmm7 = _mm_add_ps( xmm7, xmm6 );
	xmm5 = xmm4 ; 
	xmm5 = _mm_shuffle_ps( xmm5, xmm7, 0x22 );
	xmm4 = _mm_shuffle_ps( xmm4, xmm7, 0x77 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeu_ps((float *)&((cc)[3].c[0]), xmm5 );
	xmm3 = _mm_loadl_pi(xmm3, (__m64 *)&((aa)[3].e[0][2]) );
	xmm3 = _mm_loadh_pi(xmm3, (__m64 *)&((aa)[3].e[1][2]) );
	xmm4 = _mm_loadh_pi(xmm4, (__m64 *)&((aa)[3].e[2][2]) );
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0xEE );
	xmm5 = xmm3 ; 
	xmm3 = _mm_mul_ps( xmm3, xmm0 );
	xmm5 = _mm_mul_ps( xmm5, xmm1 );
	xmm4 = _mm_mul_ps( xmm4, xmm2 );
	xmm6 = xmm5 ; 
	xmm6 = _mm_shuffle_ps( xmm6, xmm3, 0x4E );
	xmm5 = _mm_shuffle_ps( xmm5, xmm3, 0xE4 );
	xmm4 = _mm_add_ps( xmm4, xmm5 );
	xmm4 = _mm_add_ps( xmm4, xmm6 );
	xmm5 = xmm4 ; 
	xmm4 = _mm_shuffle_ps( xmm4, xmm4, 0x77 );
	xmm5 = _mm_shuffle_ps( xmm5, xmm5, 0x22 );
	 	 xmm4 = _mm_xor_ps( xmm4, _sse_sgn24.xmm );
	xmm5 = _mm_add_ps( xmm5, xmm4 );
	_mm_storeh_pi((__m64 *)&((cc)[3].c[2]), xmm5 );
}

#ifdef __cplusplus
}; 
#endif

