#if !defined( MEMFILE_H )

#include <assert.h>
#include <string.h>

#ifdef WIN32
	#define inline __inline
	#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS
	#endif
#endif

#pragma push_macro( "LOOP_0" )
#pragma push_macro( "LOOP_0( F, N )" )
#pragma push_macro( "LOOP_1( F, N ) F( 1 )" )
#pragma push_macro( "LOOP_2( F, N ) LOOP_1( F, N ), F( 2 )" )
#pragma push_macro( "LOOP_3( F, N ) LOOP_2( F, N ), F( 3 )" )
#pragma push_macro( "LOOP_4( F, N ) LOOP_3( F, N ), F( 4 )" )
#pragma push_macro( "LOOP_5( F, N ) LOOP_4( F, N ), F( 5 )" )
#pragma push_macro( "LOOP_6( F, N ) LOOP_5( F, N ), F( 6 )" )
#pragma push_macro( "LOOP_7( F, N ) LOOP_6( F, N ), F( 7 )" )
#pragma push_macro( "LOOP_8( F, N ) LOOP_7( F, N ), F( 8 )" )
#pragma push_macro( "ITERATE_0( F )" )
#pragma push_macro( "ITERATE_1( F ) F( 1 )" )
#pragma push_macro( "ITERATE_2( F ) ITERATE_1( F ) F( 2 )" )
#pragma push_macro( "ITERATE_3( F ) ITERATE_2( F ) F( 3 )" )
#pragma push_macro( "ITERATE_4( F ) ITERATE_3( F ) F( 4 )" )
#pragma push_macro( "ITERATE_5( F ) ITERATE_4( F ) F( 5 )" )
#pragma push_macro( "ITERATE_6( F ) ITERATE_5( F ) F( 6 )" )
#pragma push_macro( "ITERATE_7( F ) ITERATE_6( F ) F( 7 )" )
#pragma push_macro( "ITERATE_8( F ) ITERATE_7( F ) F( 8 )" )
#pragma push_macro( "ITERATE" )
#pragma push_macro( "LOOP" )
#pragma push_macro( "SCANF_PARAMS" )
#pragma push_macro( "SCANF_ARGS" )
#pragma push_macro( "FSCANF_FUNC" )

#define LOOP_0( F, N )
#define LOOP_1( F, N ) F( 1 )
#define LOOP_2( F, N ) LOOP_1( F, N ), F( 2 )
#define LOOP_3( F, N ) LOOP_2( F, N ), F( 3 )
#define LOOP_4( F, N ) LOOP_3( F, N ), F( 4 )
#define LOOP_5( F, N ) LOOP_4( F, N ), F( 5 )
#define LOOP_6( F, N ) LOOP_5( F, N ), F( 6 )
#define LOOP_7( F, N ) LOOP_6( F, N ), F( 7 )
#define LOOP_8( F, N ) LOOP_7( F, N ), F( 8 )

#define ITERATE_0( F )
#define ITERATE_1( F ) F( 1 )
#define ITERATE_2( F ) ITERATE_1( F ) F( 2 )
#define ITERATE_3( F ) ITERATE_2( F ) F( 3 )
#define ITERATE_4( F ) ITERATE_3( F ) F( 4 )
#define ITERATE_5( F ) ITERATE_4( F ) F( 5 )
#define ITERATE_6( F ) ITERATE_5( F ) F( 6 )
#define ITERATE_7( F ) ITERATE_6( F ) F( 7 )
#define ITERATE_8( F ) ITERATE_7( F ) F( 8 )

#define ITERATE( F, N ) ITERATE_##N( F )

#define LOOP( F, N ) LOOP_##N( F, N )

//--------------------------------------------------------------------------------------------------
typedef struct
{
	const char* ptr;
	int bytes_read;
} MEM_FILE;

//--------------------------------------------------------------------------------------------------
inline void OpenFileInMemory( MEM_FILE* file, const void* data )
{
	file->ptr = (const char*)data;
	file->bytes_read = 0;
}

//--------------------------------------------------------------------------------------------------
inline void FormatMemfileBuffer( const char* format, char* formatBuffer )
{
	int i;

#ifdef _DEBUG
	assert( strlen( format ) + 1 < 256 - 3 );
#endif

	for ( i = 0; format[ i ]; ++i )
	{
		formatBuffer[ i ] = format[ i ];
	}

	formatBuffer[ i ] = '%';
	formatBuffer[ i + 1 ] = 'n';
	formatBuffer[ i + 2 ] = 0;
}

//--------------------------------------------------------------------------------------------------
#define SCANF_PARAMS( N ) \
	void* argument_##N

#define SCANF_ARGS( N ) \
	argument_##N

#define FSCANF_FUNC( N ) \
	inline int fscanf( MEM_FILE* file, const char* format, LOOP( SCANF_PARAMS, N ) ) \
	{ \
		char buffer[ 256 ]; \
		int bytes_read; \
		int ret; \
		FormatMemfileBuffer( format, buffer ); \
		ret = sscanf( file->ptr + file->bytes_read, buffer, LOOP( SCANF_ARGS, N ), &bytes_read ); \
		file->bytes_read += bytes_read; \
		return ret; \
	}

ITERATE( FSCANF_FUNC, 8 )

#pragma pop_macro( "LOOP_0" )
#pragma pop_macro( "LOOP_0( F, N )" )
#pragma pop_macro( "LOOP_1( F, N ) F( 1 )" )
#pragma pop_macro( "LOOP_2( F, N ) LOOP_1( F, N ), F( 2 )" )
#pragma pop_macro( "LOOP_3( F, N ) LOOP_2( F, N ), F( 3 )" )
#pragma pop_macro( "LOOP_4( F, N ) LOOP_3( F, N ), F( 4 )" )
#pragma pop_macro( "LOOP_5( F, N ) LOOP_4( F, N ), F( 5 )" )
#pragma pop_macro( "LOOP_6( F, N ) LOOP_5( F, N ), F( 6 )" )
#pragma pop_macro( "LOOP_7( F, N ) LOOP_6( F, N ), F( 7 )" )
#pragma pop_macro( "LOOP_8( F, N ) LOOP_7( F, N ), F( 8 )" )
#pragma pop_macro( "ITERATE_0( F )" )
#pragma pop_macro( "ITERATE_1( F ) F( 1 )" )
#pragma pop_macro( "ITERATE_2( F ) ITERATE_1( F ) F( 2 )" )
#pragma pop_macro( "ITERATE_3( F ) ITERATE_2( F ) F( 3 )" )
#pragma pop_macro( "ITERATE_4( F ) ITERATE_3( F ) F( 4 )" )
#pragma pop_macro( "ITERATE_5( F ) ITERATE_4( F ) F( 5 )" )
#pragma pop_macro( "ITERATE_6( F ) ITERATE_5( F ) F( 6 )" )
#pragma pop_macro( "ITERATE_7( F ) ITERATE_6( F ) F( 7 )" )
#pragma pop_macro( "ITERATE_8( F ) ITERATE_7( F ) F( 8 )" )
#pragma pop_macro( "ITERATE" )
#pragma pop_macro( "LOOP" )
#pragma pop_macro( "SCANF_PARAMS" )
#pragma pop_macro( "SCANF_ARGS" )
#pragma pop_macro( "FSCANF_FUNC" )

#define MEMFILE_H
#endif
