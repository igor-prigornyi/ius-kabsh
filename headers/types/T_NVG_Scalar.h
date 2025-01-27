#ifndef _T_NVG_SCALAR_H_
#define _T_NVG_SCALAR_H_

#include "T_NVG_Basic.h"

/* Структура скаляра */
typedef struct {
    T_NVG_Float_64 value; /* Значение (в любых единицах)*/
    T_NVG_Bool     valid; /* Достоверность */
} T_NVG_Scalar;

/* Нулевой недостоверный скаляр */
#define NVG_Zero_Invalid_Scalar (T_NVG_Scalar){ .value = 0.0, .valid = NVG_False }

/* Нулевой достоверный скаляр */
#define NVG_Zero_Valid_Scalar (T_NVG_Scalar){ .value = 0.0, .valid = NVG_True }

/* Сформировать скаляр с заданным значением и достоверностью */
T_NVG_Scalar NVG_Create_Scalar(T_NVG_Float_64 value, T_NVG_Bool valid);

/* Расформировать скаляр (полностью, указатели не могут быть нулевыми) */
void NVG_Decompose_Scalar_Full(const T_NVG_Scalar* scalar_in, T_NVG_Float_64* value_out, T_NVG_Bool* valid_out);

/* Расформировать скаляр (частично, указатели могут быть нулевыми)*/
void NVG_Decompose_Scalar_Partial(const T_NVG_Scalar* scalar_in, T_NVG_Float_64* value_out, T_NVG_Bool* valid_out);

#endif /* _T_NVG_SCALAR_H_ */