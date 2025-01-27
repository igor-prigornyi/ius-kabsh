#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "NVG_Concept.h"
#include "NVG_Consts.h"

T_NVG_Float_64 Get_Random(T_NVG_Float_64 min, T_NVG_Float_64 max) {
    T_NVG_Float_64 range = (max - min);
    T_NVG_Float_64 div = RAND_MAX / range;
    return min + (rand() / div);
}

int main() {

    srand(time(NVG_Null));

    #define POINTS_SIZE 100

    T_NVG_Point_2D points_old[POINTS_SIZE];
    T_NVG_Point_2D points_new[POINTS_SIZE];

    T_NVG_Float_64 model_dx = 200;
    T_NVG_Float_64 model_dy = 300;
    T_NVG_Float_64 model_df = 8 * NVG_CONVERSION_DEG_TO_RAD;

    T_NVG_Size idx; for(idx = 0; idx < POINTS_SIZE; ++idx) {
        points_old[idx].x = Get_Random(-1920, 1920);
        points_old[idx].y = Get_Random(-1080, 1080);

        points_new[idx].x =  (points_old[idx].x - model_dx) * cos(model_df) + (points_old[idx].y - model_dy) * sin(model_df); /* + Get_Random(-3, 3); */
        points_new[idx].y = -(points_old[idx].x - model_dx) * sin(model_df) + (points_old[idx].y - model_dy) * cos(model_df); /* + Get_Random(-3, 3); */
    }

    T_NVG_Point_2D shift;
    T_NVG_Float_64 rotation;

    Concept_Kabsch(points_old, points_new, POINTS_SIZE, &shift, &rotation);

    printf("dx = %.16lf dy = %.16lf dphi = %.16lf\n", shift.x, shift.y, rotation * NVG_CONVERSION_RAD_TO_DEG);

    return 0;
}