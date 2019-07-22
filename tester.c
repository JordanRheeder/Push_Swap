#include "libft/libft.h"
#include "push_swap.h"
#include "stdio.h"

int     only_digits(char *str)
{
	int i;
	
	i = 0;
	while (*str)
	{
		if (!ft_isdigit(*str) && (!ft_iswhitespace(*str)))
			return (0);
		str++;
	}
	return (1);
}

int     dupe_check_str(char **str)
{
	int i;
	int j;
	int k;
	int x;

	i = 1;
	j = 1;
	k = 0;
	x = 0;
	while (str[i])
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			while (str[i][k] == str[i + j][k] && str[i][k])
			{
				if (str[i][k] != str[i + j][k])
					break ;
				k++;
			}
		   j++;
		}
		i++;
	}
	return (1);
}

int     dupe_check(int ac, char **av)
{
	char **str;
	int i;
	int j;

	i = 1;
	str = NULL;
	if (ac == 2)
	{
		str = ft_strsplit(av[1], ' ');
		i = 0;
	}
	else
		str = av;
	while (str[i])
	{
		j = 1;
		while(str[i + j] != '\0')
		{
			if (ft_strequ(str[i], str[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int     dupe_check_int(char **str)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (str[i])
	{
		j = 1;
		printf("i=[%d]\n", i);      // remove <---
		while(str[i + j] != '\0')
		{
			printf("j=[%d]\n", j); // remove MEE!:D
			if (ft_strequ(str[i], str[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		valid_number(int ac, char **av)
{
	char **str;
	int i;
	int j;
	int k;
	
	k = 0;
	i = 1;
	j = 0;
	str = NULL;
	if (ac == 2)
	{
		str = ft_strsplit(av[1], ' ');
		i = 0;
		j = 0;
	}
	else
		str = av;
	printf("str = %s\n\n", str[i]);
	while (str[j])
	{
		if (ft_int_overflows(str[j]))
			return (0);
		j++;
	}
	return (1);
}

int main(int ac, char **av)
{
	printf("returned : %d\n", valid_number(ac ,&*av));
	return (0);
}