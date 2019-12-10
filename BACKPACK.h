#ifndef BACKPACK_CIPHER_BACKPACK_H
#define BACKPACK_CIPHER_BACKPACK_H

typedef struct{
    unsigned* private_key;
    unsigned* public_key;
    unsigned S;
    unsigned N;
    unsigned c;
}TBackpack;


TBackpack* init_tbackpack(void);
void print_tbackpack(TBackpack* tbackpack);
void set_tbackpack_private_key(TBackpack* tbackpack, unsigned* private_key);
void set_tbackpack_public_key(TBackpack* tbackpack, unsigned* public_key);
void set_tbackpack_S(TBackpack* tbackpack, unsigned S);
void set_tbackpack_N(TBackpack* tbackpack, unsigned N);
void set_tbackpack_c(TBackpack* tbackpack, unsigned c);
void generate_public_key_tbackpack(TBackpack* tbackpack);

int encrypt(TBackpack* backpack);
int decrypt(TBackpack* backpack);

#endif //BACKPACK_CIPHER_BACKPACK_H
