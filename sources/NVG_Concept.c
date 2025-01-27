#include "math.h"

#include "NVG_Concept.h"

/* НВГ.КОНЦЕПТ.ЦЕНТРОИД Вычисление координат центроида системы точек на плоскости */
static T_NVG_Point_2D Concept_Centroid(const T_NVG_Point_2D* points, T_NVG_Size points_size) {

    T_NVG_Point_2D centroid = NVG_Zero_Point_2D;

    T_NVG_Size idx = 0; for(idx = 0; idx < points_size; ++ idx) {
        centroid.x += points[idx].x;
        centroid.y += points[idx].y;
    }

    centroid.x /= (T_NVG_Float_64)points_size;
    centroid.y /= (T_NVG_Float_64)points_size;

    return centroid;
}

/* НВГ.КОНЦЕПТ.ВАРИАЦИЯ Вычисление вариации системы точек на плоскости (суммы квадратов расстояний до центроида) */
static T_NVG_Float_64 Concept_Variance(const T_NVG_Point_2D* points, T_NVG_Size points_size, T_NVG_Point_2D centroid) {

    T_NVG_Float_64 variance = 0;

    T_NVG_Size idx = 0; for(idx = 0; idx < points_size; ++ idx) {
        variance += pow(points[idx].x - centroid.x, 2) + pow(points[idx].y - centroid.y, 2);
    }

    variance /= (T_NVG_Float_64)points_size;

    return variance;
}

/* НВГ.КОНЦЕПТ.КОВМАТ Вычисление ковариационной матрицы для координат системы точек на плоскости в двух различных системах координат */
static T_NVG_Matrix_2x2 Concept_Covariance_Matrix(const T_NVG_Point_2D* points_old,
                                                  const T_NVG_Point_2D* points_new,
                                                        T_NVG_Size      points_size,
                                                        T_NVG_Point_2D  centroid_old,
                                                        T_NVG_Point_2D  centroid_new) {

    T_NVG_Matrix_2x2 covariance_matrix = NVG_Zero_Matrix_2x2;

    T_NVG_Size idx = 0; for(idx = 0; idx < points_size; ++ idx) {
        covariance_matrix.a_11 += (points_old[idx].x - centroid_old.x) * (points_new[idx].x - centroid_new.x);
        covariance_matrix.a_12 += (points_old[idx].x - centroid_old.x) * (points_new[idx].y - centroid_new.y);
        covariance_matrix.a_21 += (points_old[idx].y - centroid_old.y) * (points_new[idx].x - centroid_new.x);
        covariance_matrix.a_22 += (points_old[idx].y - centroid_old.y) * (points_new[idx].y - centroid_new.y);
    }

    covariance_matrix.a_11 /= (T_NVG_Float_64)points_size;
    covariance_matrix.a_12 /= (T_NVG_Float_64)points_size;
    covariance_matrix.a_21 /= (T_NVG_Float_64)points_size;
    covariance_matrix.a_22 /= (T_NVG_Float_64)points_size;

    return covariance_matrix;
}

/* НВГ.КОНЦЕПТ.КАБШ Вычисление смещения и поворота двумерной системы координат по координатам набора точек в старой и новой системах координат */
void Concept_Kabsch(const T_NVG_Point_2D* points_old,
                    const T_NVG_Point_2D* points_new,
                          T_NVG_Size      points_size,
                          T_NVG_Point_2D* shift_out,
                          T_NVG_Float_64* rotation_out) {

    const T_NVG_Point_2D C_old = Concept_Centroid(points_old, points_size);
    const T_NVG_Point_2D C_new = Concept_Centroid(points_new, points_size);

    const T_NVG_Float_64 sigma = Concept_Variance(points_old, points_size, C_old);

    const T_NVG_Matrix_2x2 H = Concept_Covariance_Matrix(points_old, points_new, points_size, C_old, C_new);

    T_NVG_Matrix_2x2 U, S, V;
    NVG_Matrix_2x2_Singular_Value_Decomposition(H, &U, &S, &V);

    const T_NVG_Matrix_2x2 R = NVG_Matrix_2x2_Multiplication(U, NVG_Matrix_2x2_Transposition(V));

    const T_NVG_Float_64 scale = sigma / NVG_Matrix_2x2_Trace(S);

    *shift_out = NVG_Point_2D_Subtraction(C_old, NVG_Point_2D_Multiplication(scale, NVG_Matrix_2x2_Multiplication_Point_2D_right(R, C_new)));
    *rotation_out = atan2(R.a_21, R.a_11);
}