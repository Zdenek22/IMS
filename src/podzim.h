#ifndef PODZIM
#define PODZIM

#define TERIDOX_VAL			1126.0
#define COMMAND_36_VAL		4385.0
#define DECIS_MEGA_VAL		1472.0
#define KARATE_ZENON_VAL	2341.0
#define STUTOX_VAL			181.5
#define CCC_VAL				121.0
#define CARAMBA_VAL			1057.4
#define NURELLE_VAL			1020.0

void aplikaceHerbicidu(float* naklady, float pole, float* naftaCelkemm);
void krytonosecSesulovy(float* naklady, float pole, float* naftaCelkem);
void drepcik(float* naklady, float pole, float* naftaCelkem);
void hrabosi(float* naklady, float pole, float* naftaCelkem);
void regRustu(float* naklady, float pole, float* naftaCelkem);
void pilatka(float* naklady, float pole, float* naftaCelkem);

#endif