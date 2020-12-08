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

	txt = malloc(sizeof(char*) * 200001);
	fd = open("input.txt", O_RDONLY);
	lenght = read(fd, txt, 200000);
	txt[lenght] = 0;
	return(txt);
}

struct password {
	int min;
	int max;
	char c;
	char word[1000];
};


int ft_check_password1(struct password p) {
	int i;
	int count;

	i = 0;
	count = 0;
	while (p.word[i] != 0) {
		if (p.word[i] == p.c) {
			count++;
		}
		i++;
	}
	if ((p.min <= count) && (count <= p.max)) {
		return(1);
	}
	return(0);
}

int ft_check_password2(struct password p) {
	if (((p.word[p.min - 1] == p.c) && (p.word[p.max - 1] != p.c)) || ((p.word[p.min - 1] != p.c) && (p.word[p.max - 1] == p.c))) {
		return(1);
	}
	return (0);
}

int main() 
{
	int i;
	int j;

	char *str;
	int count;
	struct password *tab;
	int check;

	str =  read_file();
	count = ft_count(str, '\n');
	tab = malloc(sizeof(struct password) * count);

	i = 0;
	while (i < count) {
		tab[i].min = atoi(str);
		while(*str != '-') {
			str++;
		}
		str++;
		tab[i].max = atoi(str);
		while (*str!= ' ') {
			str++;
		}
		str++;
		tab[i].c = *str;
		str = str + 3;
		j = 0;
		while(*str != '\n') {
			tab[i].word[j] = *str;
			str++;
			j++;
		}
		tab[i].word[j] = 0;
		str++;
		i++; 
	}
	i = 0;
	check = 0;
	while (i < count) {
		if (ft_check_password2(tab[i]) == 1) {
			check++;
		}
		i++;
	}
	printf("%d", check);
}
