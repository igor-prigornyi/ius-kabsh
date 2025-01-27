#include <math.h>
#include "T_NVG_Matrix_2x2.h"

/* Вычисление определителя для матрицы 2x2 */
T_NVG_Float_64 NVG_Matrix_2x2_Determinant(T_NVG_Matrix_2x2 matrix) {
    return matrix.a_11 * matrix.a_22 - matrix.a_12 * matrix.a_21;
}

/* Вычисление следа матрицы для матрицы 2x2 */
T_NVG_Float_64 NVG_Matrix_2x2_Trace(T_NVG_Matrix_2x2 matrix) {
    return matrix.a_11 + matrix.a_22;
}

/* Получение транспонированной матрицы для матрицы 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Transposition(T_NVG_Matrix_2x2 matrix) {
    return (T_NVG_Matrix_2x2) { .a_11 = matrix.a_11, .a_12 = matrix.a_21,
                                .a_21 = matrix.a_12, .a_22 = matrix.a_22 };
}

/* Получение обратной матрицы для матрицы 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Inverse(T_NVG_Matrix_2x2 matrix) {

    T_NVG_Float_64 det = NVG_Matrix_2x2_Determinant(matrix);

    return (T_NVG_Matrix_2x2) { .a_11 =  matrix.a_22 / det, .a_12 = -matrix.a_12 / det,
                                .a_21 = -matrix.a_21 / det, .a_22 =  matrix.a_11 / det };
}

/* Сложение матриц 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Addition(T_NVG_Matrix_2x2 lhs, T_NVG_Matrix_2x2 rhs) {
    return (T_NVG_Matrix_2x2) { .a_11 = lhs.a_11 + rhs.a_11, .a_12 = lhs.a_12 + rhs.a_12,
                                .a_21 = lhs.a_21 + rhs.a_21, .a_22 = lhs.a_22 + rhs.a_22 };
}

/* Вычитание матриц 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Subtraction(T_NVG_Matrix_2x2 lhs, T_NVG_Matrix_2x2 rhs) {
    return (T_NVG_Matrix_2x2) { .a_11 = lhs.a_11 - rhs.a_11, .a_12 = lhs.a_12 - rhs.a_12,
                                .a_21 = lhs.a_21 - rhs.a_21, .a_22 = lhs.a_22 - rhs.a_22 };
}

/* Умножение матриц 2x2 */
T_NVG_Matrix_2x2 NVG_Matrix_2x2_Multiplication(T_NVG_Matrix_2x2 lhs, T_NVG_Matrix_2x2 rhs) {
    return (T_NVG_Matrix_2x2) { .a_11 = lhs.a_11 * rhs.a_11 + lhs.a_12 * rhs.a_21, .a_12 = lhs.a_11 * rhs.a_12 + lhs.a_12 * rhs.a_22,
                                .a_21 = lhs.a_21 * rhs.a_11 + lhs.a_22 * rhs.a_21, .a_22 = lhs.a_21 * rhs.a_12 + lhs.a_22 * rhs.a_22 };
}

/* Умножение матрицы 2x2 на столбец 2x1 */
T_NVG_Point_2D NVG_Matrix_2x2_Multiplication_Point_2D_right(T_NVG_Matrix_2x2 lhs, T_NVG_Point_2D rhs) {
    return (T_NVG_Point_2D) { .x = lhs.a_11 * rhs.x + lhs.a_12 * rhs.y ,
                              .y = lhs.a_21 * rhs.x + lhs.a_22 * rhs.y };
}

/* Умножение столбца 1x2 на матрицу 2x2 */
T_NVG_Point_2D NVG_Matrix_2x2_Multiplication_Point_2D_left(T_NVG_Point_2D lhs, T_NVG_Matrix_2x2 rhs) {
    return (T_NVG_Point_2D) { .x = lhs.x * rhs.a_11 + lhs.y * rhs.a_21 ,
                              .y = lhs.x * rhs.a_12 + lhs.y * rhs.a_22 };
}

/* Сингулярное разложение матрицы 2x2 */
void NVG_Matrix_2x2_Singular_Value_Decomposition(T_NVG_Matrix_2x2 H, T_NVG_Matrix_2x2* U_out, T_NVG_Matrix_2x2* S_out, T_NVG_Matrix_2x2* V_out) {

    #define NVG_EPS_SVD 1e-8

    const T_NVG_Float_64 C_1 = pow(H.a_11, 2) + pow(H.a_12, 2) + pow(H.a_21, 2) + pow(H.a_22, 2);
    const T_NVG_Float_64 C_2 = (pow(H.a_11 + H.a_22, 2) + pow(H.a_12 - H.a_21, 2)) * (pow(H.a_11 - H.a_22, 2) + pow(H.a_12 + H.a_21, 2));

    /* Собственные значения матрицы (H^T * H) */
    const T_NVG_Float_64 lambda_1 = (C_1 + sqrt(C_2)) / 2;
    const T_NVG_Float_64 lambda_2 = (C_1 - sqrt(C_2)) / 2;

    /* Вычисление матрицы S */
    *S_out = (T_NVG_Matrix_2x2){ .a_11 = sqrt(lambda_1), .a_12 = 0,
                                 .a_21 = 0,              .a_22 = sqrt(lambda_2) };
    
    /* Вычисление матрицы V с защитой от деления на ноль */
    if(fabs(H.a_11 * H.a_12 + H.a_21 * H.a_22) > NVG_EPS_SVD) {

        const T_NVG_Float_64 C_lambda_1 = -(pow(H.a_11, 2) + pow(H.a_21, 2) - lambda_1) / (H.a_11 * H.a_12 + H.a_21 * H.a_22);
        const T_NVG_Float_64 C_lambda_2 = -(pow(H.a_11, 2) + pow(H.a_21, 2) - lambda_2) / (H.a_11 * H.a_12 + H.a_21 * H.a_22);

        *V_out = (T_NVG_Matrix_2x2){ .a_11 = 1          / sqrt(1 + pow(C_lambda_1, 2)), .a_12 = 1          / sqrt(1 + pow(C_lambda_2, 2)),
                                     .a_21 = C_lambda_1 / sqrt(1 + pow(C_lambda_1, 2)), .a_22 = C_lambda_2 / sqrt(1 + pow(C_lambda_2, 2)) };
    }
    else {
        *V_out = NVG_Identity_Matrix_2x2;
    }

    /* Вычисление матрицы U с защитой от деления на ноль */
    if(fabs(lambda_1) > NVG_EPS_SVD && fabs(lambda_2) > NVG_EPS_SVD) {
        *U_out = NVG_Matrix_2x2_Multiplication(H, NVG_Matrix_2x2_Multiplication(*V_out, NVG_Matrix_2x2_Inverse(*S_out)));
    }
    else if(fabs(lambda_1) > NVG_EPS_SVD) {

        /*
        *U_out = (T_NVG_Matrix_2x2){ .a_11 = H.a_11 / (V_out->a_11 * sqrt(lambda_1)), .a_12 = 1,
                                     .a_21 = H.a_12 / (V_out->a_11 * sqrt(lambda_1)), .a_22 = 1 };
        */
    }
    else {
        /* Этот случай возможен только при H == NVG_Zero_Matrix_2x2 */
    }
    
    /* Если det(U) = -1, то переносим знак минуса в матрицу V, так как требуется построить матрицу U с det(U) = 1 */
    if(NVG_Matrix_2x2_Determinant(*U_out) < 0) {
        U_out->a_12 *= -1;
        U_out->a_22 *= -1;
        V_out->a_12 *= -1;
        V_out->a_22 *= -1;
    }
}