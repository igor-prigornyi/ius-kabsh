#include "T_NVG_Point_2D.h"

/* Сложение координат точек */
T_NVG_Point_2D NVG_Point_2D_Addition(T_NVG_Point_2D lhs, T_NVG_Point_2D rhs) {
    return (T_NVG_Point_2D) { .x = lhs.x + rhs.x, .y = lhs.y + rhs.y };
}

/* Вычитание координат точек */
T_NVG_Point_2D NVG_Point_2D_Subtraction(T_NVG_Point_2D lhs, T_NVG_Point_2D rhs) {
    return (T_NVG_Point_2D) { .x = lhs.x - rhs.x, .y = lhs.y - rhs.y };
}

/* Умножение координат точки на число */
T_NVG_Point_2D NVG_Point_2D_Multiplication(T_NVG_Float_64 lhs, T_NVG_Point_2D rhs) {
    return (T_NVG_Point_2D) { .x = lhs * rhs.x, .y = lhs * rhs.y };
}

/* Сформировать точку с заданными координатами */
T_NVG_Point_2D NVG_Create_Point_2D(T_NVG_Float_64 x, T_NVG_Float_64 y) {
    return (T_NVG_Point_2D) { .x = x, .y = y };
}

/* Расформировать координаты точки (полностью, указатели не могут быть нулевыми) */
void NVG_Decompose_Point_2D_Full(const T_NVG_Point_2D* point_in, T_NVG_Float_64* x_out, T_NVG_Float_64* y_out) {
    *x_out = point_in->x;
    *y_out = point_in->y;
}

/* Расформировать координаты точки (частично, указатели могут быть нулевыми)*/
void NVG_Decompose_Point_2D_Partial(const T_NVG_Point_2D* point_in, T_NVG_Float_64* x_out, T_NVG_Float_64* y_out) {
    if(x_out != NVG_Null) {
        *x_out = point_in->x;
    }
    if(y_out != NVG_Null) {
        *y_out = point_in->y;
    }
}