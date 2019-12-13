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
/*
int main()
{
	unsigned tmp_private_key[KEY_LENGTH] = { 7, 12, 24, 51, 95, 195, 387, 772 };
	unsigned tmp_c = 13;
	unsigned tmp_N = 2047;
	//info();
	TBackpack* backpack = init_tbackpack();
	//print_tbackpack(backpack);
	set_tbackpack_c(backpack, tmp_c);
	set_tbackpack_N(backpack, tmp_N);
	set_tbackpack_private_key(backpack, tmp_private_key);
	generate_public_key_tbackpack(backpack);
	//print_tbackpack(backpack);
	encrypt("test.txt", backpack);
	decrypt("output.txt", backpack);
	return 0;
}
*/
int main(int argc, char** argv)
{
	if (argc == 4) {

		char* keys[3] = { "-g", "-e", "-d" };
		int is_key = 0;
		unsigned tmp_private_key[KEY_LENGTH] = { 7, 12, 24, 51, 95, 195, 387, 772 };
		unsigned tmp_c = 13;
		unsigned tmp_N = 2047;
		TBackpack* backpack = init_tbackpack();
		set_tbackpack_c(backpack, tmp_c);
		set_tbackpack_N(backpack, tmp_N);
		set_tbackpack_private_key(backpack, tmp_private_key);
		generate_public_key_tbackpack(backpack);


		for (int i = 0; i < 3; i++)
		{
			if (strcmp(keys[i], argv[1]) == 0)
			{
				switch (i)
				{
				case 0:
					is_key = 1;
					print_tbackpack(backpack);
					break;

				case 1:
					is_key = 1;
					encrypt(argv[2], backpack);
					break;

				case 2:
					is_key = 1;
					decrypt(argv[2], backpack);
					break;

				default:
					break;
				}
			}
		}

		if (is_key == 0) fprintf(stderr, "ANTA BAKA?! Wrong parameter has been transferred\n");

	}
	else
		fprintf(stderr, "ANTA BAKA?! Only 3 parameters are requirted!\n");

	return 0;
}