#include "BACKPACK.h"
#include <stdlib.h>
#include <stdio.h>

TBackpack* init_tbackpack(void)
{
    TBackpack* tbackpack = NULL;
    tbackpack = (TBackpack*)malloc(sizeof(TBackpack));

    if(tbackpack != NULL)
    {
        tbackpack->p[0] = 0;//may be wrong way
        tbackpack->b[0] = 0;//i think about it
        tbackpack->N = 0;
        tbackpack->c = 0;
    }
    else
    {
        printf("Out of memory!\n");
        free(tbackpack);
        tbackpack = NULL;
    }

    return tbackpack;
};

void set_p_tbackpack(TBackpack* tbackpack, unsigned* p)
{
    /*some code*/
};

void set_b_tbackpack(TBackpack* tbackpack, unsigned* b)
{
    /*some code*/
};

void set_N_tbackpack(TBackpack* tbackpack, unsigned N)
{
    tbackpack->N = N;
};

void set_c_tbackpack(TBackpack* tbackpack, unsigned c)
{
    tbackpack->N = c;
};