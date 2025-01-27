#ifndef _T_NVG_POINT_2D_H_
#define _T_NVG_POINT_2D_H_

#include "T_NVG_Basic.h"

/* Структура декартовых координат точки на плоскости */
typedef struct {
    T_NVG_Float_64 x; /* Абсцисса */
    T_NVG_Float_64 y; /* Ордината */
} T_NVG_Point_2D;

/* Точка с нулевыми координатами */
#define NVG_Zero_Point_2D (T_NVG_Point_2D){ .x = 0, .y = 0 }

/* Сложение координат точек */
T_NVG_Point_2D NVG_Point_2D_Addition(T_NVG_Point_2D lhs, T_NVG_Point_2D rhs);

/* Вычитание координат точек */
T_NVG_Point_2D NVG_Point_2D_Subtraction(T_NVG_Point_2D lhs, T_NVG_Point_2D rhs);

/* Умножение координат точки на число */
T_NVG_Point_2D NVG_Point_2D_Multiplication(T_NVG_Float_64 lhs, T_NVG_Point_2D rhs);

/* Сформировать точку с заданными координатами */
T_NVG_Point_2D NVG_Create_Point_2D(T_NVG_Float_64 x, T_NVG_Float_64 y);

/* Расформировать координаты точки (полностью, указатели не могут быть нулевыми) */
void NVG_Decompose_Point_2D_Full(const T_NVG_Point_2D* point_in, T_NVG_Float_64* x_out, T_NVG_Float_64* y_out);

/* Расформировать координаты точки (частично, указатели могут быть нулевыми)*/
void NVG_Decompose_Point_2D_Partial(const T_NVG_Point_2D* point_in, T_NVG_Float_64* x_out, T_NVG_Float_64* y_out);

#endif /* _T_NVG_POINT_2D_H_ */