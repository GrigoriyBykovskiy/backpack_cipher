#ifndef BACKPACK_CIPHER_BACKPACK_H
#define BACKPACK_CIPHER_BACKPACK_H

typedef struct{
    unsigned p[8];
    unsigned b[8];
    unsigned N;
    unsigned c;
} TBackpack;

TBackpack* init_tbackpack(void);
void set_p_tbackpack(TBackpack* tbackpack, unsigned* p);
void set_b_tbackpack(TBackpack* tbackpack, unsigned* b);
void set_N_tbackpack(TBackpack* tbackpack, unsigned N);
void set_c_tbackpack(TBackpack* tbackpack, unsigned c);

int generate_public_key();
int encrypt();
int decrypt();

#endif //BACKPACK_CIPHER_BACKPACK_H
