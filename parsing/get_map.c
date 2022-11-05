#include "header.h"

int check_original_map(char *s, int i, char *map)
{
	int j;
	char *str;

	str = malloc(10000);
	if(!str)
		ft_allocation_err();
	j = 0;
	while(s[i] != '\n' && s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if(ft_strncmp(str, map, ft_strlen(str)) == 0)
		return(free(str), 1);
	return(free(str), 0);
}

int check_next_line_util(char *map, char *s)
{
	int i;
	i = -1;
	while(s[++i])
	{
		if(s[i] == '\n')
		{
			i++;
			while(s[i] == '\n')
				i++;
			if(check_original_map(s, i, map))
				break ;
		}
	}
	return (i);
}

int check_next_line(char **map, char *s)
{
	int i;
	int j;

	i = check_next_line_util(map[6], s);
	j = 0;
	while(s[i])
	{
		if(s[i] == '\n')
			j++;
		i++;
	}
	i = 0;
	while(map[i])
		i++;
	if(i - 6 - 1 != j)
		return(printf("Error in map !"), 0);
	return(1);
}

char **get_map(int fd)
{
    int		c;
	char	*buf;
	char	*s;
	char	**map;

    buf = (char *)malloc(sizeof(char) * (2));
	s = malloc(1);
    if (!buf)
	    return (NULL);
    c = 1;
    while (c > 0)
	{	
		c = read(fd, buf, 1);
		if (c == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[c] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	map = ft_split(s, '\n');
	if(check_next_line(map, s))
		return (free(s), map);
	return (ft_free_str_map(s, map));
}