#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char* read_file()
{
        int fd;
        char* txt;
        int lenght;

        txt = malloc(sizeof(char*) * 200001);
        fd = open("input.txt", O_RDONLY);
        lenght = read(fd, txt, 200000);
        txt[lenght] = 0;
        return(txt);
}

int ft_count(char *str, char c) {
        int i;
        int count;

        i = 0;
        count = 0;
        while( str[i + 1] != 0) {
                if(str[i] == c) {
                        count++;
                }
                i++;
        }
        return(count);
}

int ft_lenght(char *str, char c) {
        int i;

        i = 0;
        while(str[i + 1] != 0) {
                if(str[i] == c) {
                        return(i);
                }
                i++;
        }
        return(i);
}


int ft_id_siege(char *str)
{
	int i;
	int min;
	int max;
	int row;
	int column;

	i = 0;
	min = 0;
	max = 127;
	while (i < 7) {
		if (str[i] == 'F') {
			max = max - ((max - min) / 2) - 1;
		} else if (str[i] == 'B') {
			min = min + ((max - min) / 2) + 1;
		}
		i++;
	}
	row = min;
	min = 0;
	max = 7; 
	while (i < 10) {
		if (str[i] == 'L') {
                        max = max - ((max - min) / 2) - 1; 
		} else if (str[i] == 'R') { 
                        min = min + ((max - min) / 2) + 1;
		}
                i++;
	}	
	column = min;
	return((row * 8) + column);
}

void ft_swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void ft_sort(int *id) 
{
	int i;
	int j;

	i = 0;
	while( id[i] != 0) {
		j = i + 1;
		while (id[j] != 0) {
			if (id[i] > id[j]) {
				ft_swap(&id[i], &id[j]);
			}
			j++;
		}	
		i++;
	}	
}

int ft_find_missing(int *id) {

	int i;

	ft_sort(id);
	i = 1;
	while (id[i + 1] != 0) {
		if (id[i] != id[i + 1] - 1) {
			return(id[i] + 1);
		}
		i++;
	}
	return(0);
}

int main()
{
	int i;
	int j;
	int max;

        char *str;
        int count;
        char **tab;
        int lenght;
	int *id;

        str =  read_file();
        count = ft_count(str, '\n');
        tab = malloc(sizeof(char *) * (count + 2));

        i = 0;
        while (i <= count) {
                j = 0;
                lenght = ft_lenght(str, '\n');
                tab[i] = malloc(sizeof(char) * (lenght + 1));
                while (j < lenght) {
                        tab[i][j] = *str;
                        str++;
                        j++;
                }
                tab[i][j] = 0;
                str++;
                i++;
        }
        tab[i] = 0;

	max = 0;
	i = 0;
	id = malloc(sizeof(int) * (count + 2));
	while (i <= count) {
		id[i] = ft_id_siege(tab[i]);
		if (id[i] > max) {
			max = id[i];
		}
		i++;
	}
	id[i] = 0;
	printf("id max : %d\n", max);
	printf("id_siege_manquant : %d\n",ft_find_missing(id));
	return(0);
}


