#define _CRT_SECURE_NO_WARNINGS
#define KEY_LENGTH 8
#define OUTPUTFILE "output.txt"
#include "BACKPACK.h"
#include <stdlib.h>
#include <stdio.h>

TBackpack* init_tbackpack(void)
{
	TBackpack* tbackpack = NULL;
	tbackpack = (TBackpack*)malloc(sizeof(TBackpack));

	if (tbackpack != NULL)
	{
		tbackpack->private_key = (unsigned*)calloc(KEY_LENGTH, sizeof(unsigned));
		tbackpack->public_key = (unsigned*)calloc(KEY_LENGTH, sizeof(unsigned));
		tbackpack->N = 0;
		tbackpack->c = 0;
	}
	else
	{
		fprintf(stdout, "Out of memory!\n");
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
	fprintf(stdout, "Not available now. Wait in new update!\n");
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
		fprintf(stdout, " %4u ", tbackpack->public_key[i]);

	fprintf(stdout, "\n=|private key:                                      |=\n ");

	for (int i = 0; i < KEY_LENGTH; i++)
		fprintf(stdout, " %4u ", tbackpack->private_key[i]);

	fprintf(stdout, "\n=|N:                                                |=\n");
	fprintf(stdout, "  %u", tbackpack->N);
	fprintf(stdout, "\n=|c:                                                |=\n");
	fprintf(stdout, "  %u", tbackpack->c);

	fprintf(stdout, "\n=|__________________________________________________|=\n");
};

void generate_public_key_tbackpack(TBackpack* tbackpack)
{
	for (int i = 0; i < KEY_LENGTH; i++)
	{
		tbackpack->public_key[i] = (tbackpack->private_key[i] * tbackpack->c) % (tbackpack->N);
	}
};

void generate_private_key_tbackpack(TBackpack* tbackpack)
{
	fprintf(stdout,"Not ready. Wait for another update!\n");
};

void get_bits_array(char symbol, unsigned* array_of_bits) // little-endian format
{
	for (int i = 0; i < KEY_LENGTH; i++)
	{
		if ((symbol & (1 << i)) == 0)
			array_of_bits[i] = 0;
		else
			array_of_bits[i] = 1;
	}
};

int extended_gcd(int a, int b)//input N and c
{
	int p = 1, q = 0, r = 0, s = 1, x, y;
	while (a && b) {
		if (a >= b) {
			a = a - b;
			p = p - r;
			q = q - s;
		}
		else
		{
			b = b - a;
			r = r - p;
			s = s - q;
		}
	}
	if (a) {
		x = p;
		y = q;
	}
	else
	{
		x = r;
		y = s;
	}
	//printf("\n%d %d\n",x,y);
	return y;
}

int encrypt(char* filename, TBackpack* backpack)
{
	FILE* input_text;
	FILE* output_text;
	if (((input_text = fopen(filename, "r")) != NULL) && ((output_text = fopen(OUTPUTFILE, "w")) != NULL))
	{
		char symbol;
		do
		{
			symbol = fgetc(input_text);
			//printf("%c ", symbol);
			unsigned array_of_bits[KEY_LENGTH];
			get_bits_array(symbol, &array_of_bits[0]);
			int tmp = 0;
			for (int i = KEY_LENGTH; i > -1; i--)// big-endian
			{
				if (array_of_bits[i] == 1)
				{
					tmp += backpack->public_key[i];
				}
			}
			fprintf(output_text, "%04d", tmp);

		} while (symbol != EOF);
		//printf("END ENCRYPTION\n");
		fclose(input_text);
		fclose(output_text);

	}
	else {
		fprintf(stderr, "Can not open input file!\n");
		return 0;
	}

	return 1;
};



int decrypt(char* filename, TBackpack* backpack)
{
	unsigned inverse_element_c = extended_gcd(backpack->N, backpack->c);

	FILE* input_text;
	FILE* output_text;
	if (((input_text = fopen(filename, "r")) != NULL) && ((output_text = fopen(OUTPUTFILE, "w")) != NULL))
	{
		char symbol = 0;
		char tmp[4] = { 0, 0, 0, 0 };
		do
		{
			symbol = fgetc(input_text);
			if (symbol == EOF) {
				continue;
			}
			else {
			fseek(input_text, -1, SEEK_CUR);
			fread(&tmp, sizeof(char), 4, input_text);
			int encrypted_symbol = atoi(&tmp);
			unsigned weight = (encrypted_symbol * inverse_element_c) % backpack->N;
			for (int i = 7; i > -1; i--) {

				if (weight >= backpack->private_key[i])
				{
					weight -= backpack->private_key[i];
					symbol |= (1 << i);
				}
				else
					symbol &= ~(1 << i);
			}
			fprintf(output_text,"%c", symbol);
			symbol = 0;
			for (int i = 0; i < 4; i++)
				tmp[i] = 0;
			}

		} while (!(feof(input_text)));

		fclose(input_text);
		fclose(output_text);

	}
	else {
		fprintf(stderr, "Can not open input file!\n");
		return 0;
	}
	return 1;
};