#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define B_S 512
#define F_N_S 8

typedef uint8_t BYTE;

bool start_new_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: ./recover enter 1 argument only.\n");
        return 1;
    }
    FILE *If = fopen(argv[1], "r");
    if (If == NULL)
    {
        printf("Error: File not found");
        return 1;
    }

    BYTE buffer[B_S];
    int file_index = 0;
    bool first_found = false;
    FILE *Of;
    while (fread (buffer, B_S, 1, If))
    {
        if (start_new_jpeg(buffer))
        {
            if (!first_found)
            {
                first_found = true;
            }
            else
            {
                fclose(Of);
            }
            char filename[F_N_S];
            sprintf(filename, "%03i.jpg", file_index++);
            Of = fopen(filename, "w");
            if (Of == NULL)
            {
                return 1;
            }
            fwrite(buffer, B_S, 1, Of);
        }
        else if (first_found)
        {
            fwrite(buffer, B_S, 1, Of);
        }
    }
    fclose(Of);
    fclose(If);
}
bool start_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
