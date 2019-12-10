#define KEY_LENGTH 8
#include "BACKPACK.h"
#include <stdlib.h>
#include <stdio.h>

TBackpack* init_tbackpack(void)
{
    TBackpack* tbackpack = NULL;
    tbackpack = (TBackpack*)malloc(sizeof(TBackpack));

    if(tbackpack != NULL)
    {
        tbackpack->private_key =(unsigned*) calloc(KEY_LENGTH, sizeof(unsigned));
        tbackpack->public_key = (unsigned*) calloc(KEY_LENGTH, sizeof(unsigned));
        tbackpack->N = 0;
        tbackpack->c = 0;
    }
    else
    {
        fprintf(stdout,"Out of memory!\n");
        free(tbackpack);
        tbackpack = NULL;
    }

    return tbackpack;
};

void set_tbackpack_private_key(TBackpack* tbackpack, unsigned* private_key)
{
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        tbackpack->private_key[i] = private_key[i];
    }
};

void set_tbackpack_public_key(TBackpack* tbackpack, unsigned* public_key)
{
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        tbackpack->public_key[i] = public_key[i];
    }
};

void set_tbackpack_S(TBackpack* tbackpack, unsigned S)
{
    fprintf(stdout,"Not available now. Wait in new update!\n");
};

void set_tbackpack_N(TBackpack* tbackpack, unsigned N)
{
    tbackpack->N = N;
};

void set_tbackpack_c(TBackpack* tbackpack, unsigned c)
{
    tbackpack->c = c;
};

void print_tbackpack(TBackpack* tbackpack)
{
    fprintf(stdout, "=|                                                  |=\n");
    fprintf(stdout, "=|__________________TBACKPACK_DATA__________________|=\n");
    fprintf(stdout, "=|public key:                                       |=\n ");

    for (int i = 0; i < KEY_LENGTH; i++)
        fprintf(stdout," %u ",tbackpack->public_key[i]);

    fprintf(stdout,"\n=|private key:                                      |=\n ");

    for (int i = 0; i < KEY_LENGTH; i++)
        fprintf(stdout," %u ",tbackpack->private_key[i]);

    fprintf(stdout,"\n=|N:                                                |=\n");
    fprintf(stdout, "  %u", tbackpack->N);
    fprintf(stdout,"\n=|c:                                                |=\n");
    fprintf(stdout, "  %u", tbackpack->N);

    fprintf(stdout, "\n=|__________________________________________________|=\n");
    fprintf(stdout, "=|                                                  |=\n");
};

void generate_public_key_tbackpack(TBackpack* tbackpack)
{
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        tbackpack->public_key = (tbackpack->private_key[i] * tbackpack->c) % (tbackpack->N);
    }
};

int encrypt(TBackpack* backpack);
int decrypt(TBackpack* backpack);