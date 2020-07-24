#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define B_S 512 //Block Size set to 512 bytes.
#define F_N_S 8 //File Size set to 8 bytes.

typedef uint8_t BYTE; //To create BYTE.

bool start_new_jpeg(BYTE buffer[]); //To check if a file is jpeg or not.

int main(int argc, char *argv[])
{
    if (argc != 2) //To make sure only one argument is entered.
    {
        printf("Error: ./recover enter 1 argument only.\n");
        return 1;
    }
    FILE *If = fopen(argv[1], "r"); //To open the file entered as the argument.
    if (If == NULL)
    {
        printf("Error: File not found"); //In case the name entered is not an existing file.
        return 1;
    }

    BYTE buffer[B_S];
    int file_index = 0;
    bool first_found = false;
    FILE *Of;
    while (fread(buffer, B_S, 1, If)) //Used to read and identify the file as a jpeg or not.
    {
        if (start_new_jpeg(buffer))
        {
            if (!first_found)
            {
                first_found = true; //Turns it to to true.
            }
            else
            {
                fclose(Of);
            }
            char filename[F_N_S];
            sprintf(filename, "%03i.jpg", file_index++);
            Of = fopen(filename, "w"); //To write the file.
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
    //Because the first 4 digits of any jpeg are 0xff, 0xd8, 0xff & 0xe(1 to f).
    //To easily and quickly identify the 4th digit, the 0xe part is kept while the last no. is converted to 0.
}
