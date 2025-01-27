#ifndef _T_NVG_COORDINATE_H_
#define _T_NVG_COORDINATE_H_

#include "T_NVG_Basic.h"

/* Структура географических координат */
typedef struct {
    T_NVG_Float_64 Fi;    /* Широта  в радианах [ -Pi/2 ... Pi/2 ] */
    T_NVG_Float_64 Lm;    /* Долгота в радианах [ -Pi   ... Pi ] */
    T_NVG_Bool     valid; /* Достоверность */
} T_NVG_Coordinate;

/* Нулевые недостоверные координаты */
#define NVG_Zero_Invalid_Coordinate (T_NVG_Coordinate){ .Fi = 0.0, .Lm = 0.0, .valid = NVG_False }

/* Нулевые достоверные координаты */
#define NVG_Zero_Valid_Coordinate (T_NVG_Coordinate){ .Fi = 0.0, .Lm = 0.0, .valid = NVG_True }

/* Сформировать координату с заданной широтой, долготой и достоверностью */
T_NVG_Coordinate NVG_Create_Coordinate(T_NVG_Float_64 Fi, T_NVG_Float_64 Lm, T_NVG_Bool valid);

/* Расформировать координату (полностью, указатели не могут быть нулевыми) */
void NVG_Decompose_Coordinate_Full(const T_NVG_Coordinate* coord_in, T_NVG_Float_64* Fi_out, T_NVG_Float_64* Lm_out, T_NVG_Bool* valid_out);

/* Расформировать координату (частично, указатели могут быть нулевыми)*/
void NVG_Decompose_Coordinate_Partial(const T_NVG_Coordinate* coord_in, T_NVG_Float_64* Fi_out, T_NVG_Float_64* Lm_out, T_NVG_Bool* valid_out);

#endif /* _T_NVG_COORDINATE_H_ */