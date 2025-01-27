#include "T_NVG_Coordinate.h"

/* Сформировать координату с заданной широтой, долготой и достоверностью */
T_NVG_Coordinate NVG_Create_Coordinate(T_NVG_Float_64 Fi, T_NVG_Float_64 Lm, T_NVG_Bool valid) {
    return (T_NVG_Coordinate){ .Fi = Fi, .Lm = Lm, .valid = valid };
}

/* Расформировать координату (полностью, указатели не могут быть нулевыми) */
void NVG_Decompose_Coordinate_Full(const T_NVG_Coordinate* coord_in, T_NVG_Float_64* Fi_out, T_NVG_Float_64* Lm_out, T_NVG_Bool* valid_out) {
    *Fi_out    = coord_in->Fi;
    *Lm_out    = coord_in->Lm;
    *valid_out = coord_in->valid;
}

/* Расформировать координату (частично, указатели могут быть нулевыми)*/
void NVG_Decompose_Coordinate_Partial(const T_NVG_Coordinate* coord_in, T_NVG_Float_64* Fi_out, T_NVG_Float_64* Lm_out, T_NVG_Bool* valid_out) {
    if (Fi_out != NVG_Null) {
        *Fi_out = coord_in->Fi;
    }
    if (Lm_out != NVG_Null) {
        *Lm_out = coord_in->Lm;
    }
    if (valid_out != NVG_Null) {
        *valid_out = coord_in->valid;
    }
}