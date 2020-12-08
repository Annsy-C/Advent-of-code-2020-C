#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_count(char *str, char c) {
	int i;
	int count;
	
	i = 0;
	count = 0;
	while( str[i] != 0) {
		if(str[i] == c) {
			count++;
		}
		i++;
	}
	return(count);
}

char* read_file()
{
	int fd;
	char* txt;
	int lenght;

	txt = malloc(sizeof(char*) * 20001);
	fd = open("input.txt", O_RDONLY);
	lenght = read(fd, txt, 20000);
	txt[lenght] = 0;
	return(txt);
}

int ft_advent_1(int* tab, int count, int result){
	int i;
	int j;
	int k;

	i = 0;
	while (i < count) {
		j = i + 1;
		while (j < count) {
			k = j + 1;
			while (k < count) {
				if ((tab[i] + tab[j] + tab[k]) == result) {
					return (tab[i] * tab[j] * tab[k]);
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return(0);
}

int main() 
{
	int i;
	int j;

	char *str;
	int count;
	int *tab;

	str =  read_file();
	count = ft_count(str, '\n');
	tab = malloc(sizeof(int) * count);

	i = 0;
	while (i < count) {
		tab[i] = atoi(str);
		while(*str != '\n') {
			str++;
		}
		str++;
		i++;
	}
	printf("%d", ft_advent_1(tab, count, 2020));
}
