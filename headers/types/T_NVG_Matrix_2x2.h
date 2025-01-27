#ifndef _T_NVG_MATRIX_2X2_H_
#define _T_NVG_MATRIX_2X2_H_

#include "T_NVG_Basic.h"
#include "T_NVG_Point_2D.h"

/* Структура матрицы 2x2 */
typedef struct {
    T_NVG_Float_64 a_11, a_12;
    T_NVG_Float_64 a_21, a_22;
} T_NVG_Matrix_2x2;

/* Нулевая матрица 2x2 */
#define NVG_Zero_Matrix_2x2 (T_NVG_Matrix_2x2) { .a_11 = 0, .a_12 = 0,  \
                                                 .a_21 = 0, .a_22 = 0 } \

/* Единичная матрица 2x2 */
#define NVG_Identity_Matrix_2x2 (T_NVG_Matrix_2x2) { .a_11 = 1, .a_12 = 0,  \
                                                     .a_21 = 0, .a_22 = 1 } \

/* Анти-единичная матрица 2x2 */
#define NVG_Anti_Identity_Matrix_2x2 (T_NVG_Matrix_2x2) { .a_11 = 0, .a_12 = 1,  \
                                                          .a_21 = 1, .a_22 = 0 } \

/* Вычисление определителя для матрицы 2x2 */
T_NVG_Float_64 NVG_Matrix_2x2_Determinant(T_NVG_Matrix_2x2 matrix);

/* Вычисление следа матрицы для матрицы 2x2 */
T_NVG_Float_64 NVG_Matrix_2x2_Trace(T_NVG_Matrix_2x2 matrix);

/* Получение транспонированной матрицы для матрицы 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Transposition(T_NVG_Matrix_2x2 matrix);

/* Получение обратной матрицы для матрицы 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Inverse(T_NVG_Matrix_2x2 matrix);

/* Сложение матриц 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Addition(T_NVG_Matrix_2x2 lhs, T_NVG_Matrix_2x2 rhs);

/* Вычитание матриц 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Subtraction(T_NVG_Matrix_2x2 lhs, T_NVG_Matrix_2x2 rhs);

/* Умножение матриц 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Multiplication(T_NVG_Matrix_2x2 lhs, T_NVG_Matrix_2x2 rhs);

/* Умножение матрицы 2x2 на столбец 2x1 */
T_NVG_Point_2D NVG_Matrix_2x2_Multiplication_Point_2D_right(T_NVG_Matrix_2x2 lhs, T_NVG_Point_2D rhs);

/* Умножение столбца 1x2 на матрицу 2x2 */
T_NVG_Point_2D NVG_Matrix_2x2_Multiplication_Point_2D_left(T_NVG_Point_2D lhs, T_NVG_Matrix_2x2 rhs);

/* Сингулярное разложение матрицы 2x2 */
void NVG_Matrix_2x2_Singular_Value_Decomposition(T_NVG_Matrix_2x2 H, T_NVG_Matrix_2x2* U_out, T_NVG_Matrix_2x2* S_out, T_NVG_Matrix_2x2* V_out);

#endif /* _T_NVG_MATRIX_2X2_H_ */