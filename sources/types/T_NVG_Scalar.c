#include "T_NVG_Scalar.h"

/* Сформировать скаляр с заданным значением и достоверностью */
T_NVG_Scalar NVG_Create_Scalar(T_NVG_Float_64 value, T_NVG_Bool valid) {
    return (T_NVG_Scalar){ .value = value, .valid = valid };
}

/* Расформировать скаляр (полностью, указатели не могут быть нулевыми) */
void NVG_Decompose_Scalar_Full(const T_NVG_Scalar* scalar_in, T_NVG_Float_64* value_out, T_NVG_Bool* valid_out) {
    *value_out = scalar_in->value;
    *valid_out = scalar_in->valid;
}

/* Расформировать скаляр (частично, указатели могут быть нулевыми)*/
void NVG_Decompose_Scalar_Partial(const T_NVG_Scalar* scalar_in, T_NVG_Float_64* value_out, T_NVG_Bool* valid_out) {
    if(value_out != NVG_Null) {
        *value_out = scalar_in->value;
    }
    if(valid_out != NVG_Null) {
        *valid_out = scalar_in->valid;
    }
}