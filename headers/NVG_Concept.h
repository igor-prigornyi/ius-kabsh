#ifndef _NVG_CONCEPT_H_
#define _NVG_CONCEPT_H_

#include "T_NVG_Matrix_2x2.h"
#include "T_NVG_Point_2D.h"

/* НВГ.КОНЦЕПТ.КАБШ Вычисление смещения и поворота двумерной системы координат по координатам набора точек в старой и новой системах координат */
void Concept_Kabsch(const T_NVG_Point_2D* points_old,
                    const T_NVG_Point_2D* points_new,
                          T_NVG_Size      points_size,
                          T_NVG_Point_2D* shift_out,
                          T_NVG_Float_64* rotation_angle_out);

#endif /* _NVG_CONCEPT_H_ */