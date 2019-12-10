#define KEY_LENGTH 8
#include <stdio.h>
#include "BACKPACK.h"

void info()
{
    fprintf(stdout, "\n=======================BACKPACK=======================\n");
    fprintf(stdout, "=                                                    =\n");
    fprintf(stdout, "=                                                    =\n");
    fprintf(stdout, "======================================================\n");
    fprintf(stdout, "= Created by:                                        =\n");
    fprintf(stdout, "=_Grigoriy Bykovskiy                       programmer=\n");
    fprintf(stdout, "=_Nikita Gogol                              team lead=\n");
    fprintf(stdout, "=_Dmitriy Pastuhov                           talisman=\n");
    fprintf(stdout, "======================================================\n");
    fprintf(stdout, "=                                                    =\n");
    fprintf(stdout, "=                                                    =\n");
    fprintf(stdout, "======================================================\n");
    fprintf(stdout, "=_______________________OUTPUT_______________________=\n");
    fprintf(stdout, "=|                                                  |=\n");
};

int main()
{
    unsigned tmp_private_key[KEY_LENGTH] = {7, 12, 24, 51, 95, 195, 387, 772};
    unsigned tmp_c = 13;
    unsigned tmp_N = 2047;
    info();
    TBackpack* backpack = init_tbackpack();
    print_tbackpack(backpack);
    set_tbackpack_c(backpack, tmp_c);
    set_tbackpack_N(backpack, tmp_N);
    set_tbackpack_private_key(backpack, tmp_private_key);
    print_tbackpack(backpack);
    return 0;
}