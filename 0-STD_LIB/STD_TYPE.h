#ifndef STD_TYPE_H
#define STD_TYPE_H

//Numeric Data Types
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;
typedef signed long long int sint64;
typedef float f32;
typedef double f64;
typedef long double f128;

//Null Pointer
#define Null ((void*) 0)

//Boolean Data Type
typedef enum{
	False,
	True
}bool;

//Mask Macro
#define MASK(X) 1<<X


#endif
