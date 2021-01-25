add_library(libintrin sse_add_su3_vector.c
	sse_mult_adj_su3_mat_4vec.c
	sse_mult_adj_su3_mat_hwvec.c
	sse_mult_su3_mat_hwvec.c
	sse_mult_adj_su3_mat_vec_4dir.c
	sse_mult_adj_su3_mat_vec.c
	sse_mult_su3_an.c
	sse_mult_su3_mat_vec.c
	sse_mult_su3_mat_vec_sum_4dir.c
	sse_mult_su3_na.c
	sse_mult_su3_nn.c
	sse_scalar_mult_add_su3_matrix.c
	sse_scalar_mult_add_su3_vector.c
	sse_su3_projector.c
	sse_sub_four_su3_vecs.c
)

target_include_directories( libintrin PUBLIC
						   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
						   $<INSTALL_INTERFACE:include> )
target_include_directories( libintrin PUBLIC
						   $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/../include>
						   $<INSTALL_INTERFACE:include> )
install(TARGETS libintrin
		EXPORT libintrin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		RUNTIME DESTINATION bin
)