#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_count1(char *str, char c) {
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

int ft_count2(char *str, char c) {
	int i;

	i = 0;
	while((str[i] != 0) && (str[i] != c)) {
		i++;
	}
	return(i); 
}

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

long int ft_check_trees(char **tab, int right, int down) 
{
	int i;
	int j;

	long int count;
	int lenght;

	i = 0;
	j = 0;
	count = 0;
	lenght = ft_count2(tab[i], 0);
	while(tab[i] != 0) {
		if (tab[i][(j % lenght)] == '#') {
			count++;
		}
		i = i + down;
		j = j + right;
	}
	return count;
}

int main() 
{
	int i;
	int j;

	char *str;
	int count;
	char **tab;

	str =  read_file();
	count = ft_count1(str, '\n');
	tab = malloc(sizeof(char *) * (count + 1));

	i = 0;
	while (i < count) {
		j = 0;
		tab[i] = malloc(sizeof(char) * (ft_count2(str, '\n') + 1));
		while(*str != '\n') {
			tab[i][j] = *str;	
			j++;
			str++;
		}
		tab[i][j] = 0;
		str++;
		i++;
	}
	tab[i] = 0;
	printf("%ld\n", ft_check_trees(tab, 3, 1));
	printf("%ld\n",(ft_check_trees(tab,1,1) * ft_check_trees(tab,3,1) * ft_check_trees(tab,5,1) * ft_check_trees(tab,7,1) * ft_check_trees(tab,1,2)));
}
