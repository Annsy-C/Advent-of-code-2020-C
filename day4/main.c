#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_count(char *str, char c) {
	int i;
	int count;
	
	i = 0;
	count = 0;
	while( str[i + 1] != 0) {
		if((str[i] == c) && (str[i + 1] == c)) {
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
                if((str[i] == c) && (str[i + 1] == c)) {
                	return(i);
		}
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

char *ft_extract(char *tab) {
	int j;
	char *temp;

	j = 0;
	temp = tab;
	while ((temp[j] != 0) && (temp[j] != '\n') &&  (temp[j] != ' ')) {
        	j++;
        }
        temp[j] = 0;
	return(temp);
}

int ft_compare(int nb, int min, int max) 
{
	if ((nb >= min) && (nb <= max)) {
		return(1);
	} else {
		return(0);
	}
}

int ft_compare_str(char *str1, char *str2) 
{
	int i;

	i = 0;
	while (str1[i] && str2[i] && (str1[i] == str2[i])) {
		i++;
	}
	if (str1[i] == 0) {
		return(1);
	}
	return(0);

}

int ft_check_passeport(char *tab) 
{
	int i;
	int j;
	int lenght;
	int count;
	char *temp;

	i = 0;
	lenght = ft_lenght(tab, 0);
	count = 0;
	temp = malloc(sizeof (char) * 200);
	while(i+ 2 < lenght) {
		temp[0] = 0;
		j = 0;
		if ((tab[i] == 'b') && (tab[i + 1] == 'y') && (tab[i + 2] == 'r')) {
			temp = ft_extract(&tab[i+4]);
			if (ft_compare(atoi(temp), 1920, 2002) == 1) {
				count ++;
			} else {
				return(0); 
			}
		}
		else if ((tab[i] == 'i') && (tab[i + 1] == 'y') && (tab[i + 2] == 'r')) {
                	temp = ft_extract(&tab[i+4]);
                        if (ft_compare(atoi(temp), 2010, 2020) == 1) {
                                count ++;
                        } else {
                                return(0);
                        }
		}
		else if ((tab[i] == 'e') && (tab[i + 1] == 'y') && (tab[i + 2] == 'r')) {
                        temp = ft_extract(&tab[i+4]);
                        if (ft_compare(atoi(temp), 2020, 2030) == 1) {
                                count ++;
                        } else {
                                return(0);
                        }
                }
		else if ((tab[i] == 'h') && (tab[i + 1] == 'g') && (tab[i + 2] == 't')) {
                        temp = ft_extract(&tab[i+4]);
                        if ((temp[ft_lenght(temp, 0) - 1]=='c') && (temp[ft_lenght(temp, 0)]=='m')) {
				temp[ft_lenght(temp, 0) - 1] = 0;
				if (ft_compare(atoi(temp), 150, 193) == 1) {
					count++;
				}
				else {
					return(0);
				} 
                       } else if ((temp[ft_lenght(temp, 0) - 1]=='i') && (temp[ft_lenght(temp, 0)]=='n')) {
				temp[ft_lenght(temp, 0) - 1] = 0;
                                if (ft_compare(atoi(temp), 59, 76) == 1) {
                                        count++;
                           	}  
				else {
                                        return(0);
                                }
			} 
			else {
                                return(0);
                        }
                }
		else if ((tab[i] == 'h') && (tab[i + 1] == 'c') && (tab[i + 2] == 'l')) {
                        temp = ft_extract(&tab[i + 4]);
			if ((temp[0] == '#') && (ft_lenght(temp, 0) == 6)) {
				j = 1;
				while (temp[j] != 0) {
					if (((temp[j] >= '0') && (temp[j] <= '9')) || ((temp[j] >= 'a') && (temp[j] <= 'f'))) {
						j++;
					} else {
						return(0);
					}
				}
				count++;
			} else {
				return(0);
			}
                }
		else if ((tab[i] == 'e') && (tab[i + 1] == 'c') && (tab[i + 2] == 'l')) {
                        temp = ft_extract(&tab[i + 4]);
			if ((ft_compare_str(temp, "amb") == 1) || (ft_compare_str(temp, "blu") == 1) || (ft_compare_str(temp, "brn") == 1) || (ft_compare_str(temp, "gry") == 1) || (ft_compare_str(temp, "grn") == 1) ||
				(ft_compare_str(temp, "hzl") == 1) || (ft_compare_str(temp, "oth") == 1)) {
				count++;
			} else {
				return(0);
			}
                }
		else if ((tab[i] == 'p') && (tab[i + 1] == 'i') && (tab[i + 2] == 'd')) {
                	temp = ft_extract(&tab[i + 4]);
                        if (ft_lenght(temp, 0) == 8) {
                                j = 1;
                                while (temp[j] != 0) {
                                        if ((temp[j] >= '0') && (temp[j] <= '9')) {
                                                j++;
                                        } else {
                                                return(0);
                                        }
                                }
                                count++;
                        } else {
                                return(0);
                        }
		}
//		if ((tab[i] == 'c') && (tab[i + 1] == 'i') && (tab[i + 2] == 'd')) {
//			count++;
//              }
		i++;
	}
	if (count == 7) {
		return(1);
	}
	return(0);
}

int main() 
{
	int i;
	int j;

	char *str;
	int count;
	char **tab;
	int lenght;
	int valid_passport;

	str =  read_file();
	count = ft_count(str, '\n');
	tab = malloc(sizeof(char *) * (count + 1));

	i = 0;
	while (i < count) {
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
	
	i = 0;
	valid_passport = 0;
	while (i < count) {
		if (ft_check_passeport(tab[i]) == 1) {
			valid_passport++;
		}
		i++;
	}
	printf("%d", valid_passport);
}
