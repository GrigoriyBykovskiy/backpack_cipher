#ifndef BACKPACK_CIPHER_BACKPACK_H
#define BACKPACK_CIPHER_BACKPACK_H

typedef struct{
    unsigned p[8];
    unsigned b[8];
    unsigned N;
    unsigned c;
} TBackpack;

TBackpack* init_tbackpack(void);
int set_p_tbackpack(TBackpack* tBackpack, unsigned* p);
int set_b_tbackpack(TBackpack* tBackpack, unsigned* b);
int set_N_tbackpack(TBackpack* tBackpack, unsigned N);
int set_c_tbackpack(TBackpack* tBackpack, unsigned c);

int generate_public_key();
int encrypt();
int decrypt();

#endif //BACKPACK_CIPHER_BACKPACK_H
