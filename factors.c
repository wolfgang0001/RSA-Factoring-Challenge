#include <stdlib.h>
#include <stdio.h>

int factorize(char *n);
int main(int argc, char *argv[])
{   
    size_t len = 0;
    ssize_t read = 1;
    char *line;
    FILE *file;
	unsigned long long i, num = 0;
	int flag = 0;

    if (argc != 2)
    {
        printf("Usage: factor <filename>\n");
        exit(1);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while ((read = getline(&line, &len, file)) > 0)
	{
		num = strtoull(line, NULL, 10);
		for (i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				printf("%llu=%llu*%llu\n", num, num/i, i);
				break;
			}
		}
		
	}
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
