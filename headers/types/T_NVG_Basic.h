#ifndef _T_NVG_BASIC_H_
#define _T_NVG_BASIC_H_

typedef signed   char T_NVG_Int_8;  /* Знаковое    8-битное целое число (int8_t)  */
typedef unsigned char T_NVG_UInt_8; /* Беззнаковое 8-битное целое число (uint8_t) */

typedef signed   short int T_NVG_Int_16;  /* Знаковое    16-битное целое число (int16_t)  */
typedef unsigned short int T_NVG_UInt_16; /* Беззнаковое 16-битное целое число (uint16_t) */

typedef signed   int T_NVG_Int_32;  /* Знаковое    32-битное целое число (int32_t)  */
typedef unsigned int T_NVG_UInt_32; /* Беззнаковое 32-битное целое число (uint32_t) */

typedef signed   long long int T_NVG_Int_64;  /* Знаковое    64-битное целое число (int64_t)  */
typedef unsigned long long int T_NVG_UInt_64; /* Беззнаковое 64-битное целое число (uint64_t) */

typedef float  T_NVG_Float_32; /* Знаковое 32-битное число с плавающей точкой (float)  */
typedef double T_NVG_Float_64; /* Знаковое 64-битное число с плавающей точкой (double) */

typedef unsigned char T_NVG_Bool; /* Логический тип (bool) */

#define NVG_False 0 /* Ложь/значение недостоверно (false) */
#define NVG_True  1 /* Истина/значение достоверно (true)  */

typedef unsigned char T_NVG_Byte; /* Байтовый тип (byte) */

typedef unsigned long int T_NVG_Size; /* Тип размерности (size_t) */

typedef void* T_NVG_Pointer; /*  */

#define NVG_Null 0 /* Нулевой указатель (nullptr) */

#endif /* _T_NVG_BASIC_H_ */