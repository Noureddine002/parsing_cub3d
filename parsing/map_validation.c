#include "header.h"

int check_six_lines(char *s)
{
    if (s[0] == 'N' && s[1] == 'O' && s[2] == ' ')
		return (1);
	else if (s[0] == 'S' && s[1] == 'O' && s[2] == ' ')
		return (1);
	else if (s[0] == 'W' && s[1] == 'E' && s[2] == ' ')
		return (1);
	else if (s[0] == 'E' && s[1] == 'A' && s[2] == ' ')
		return (1);
	else if (s[0] == 'F' && s[1] == ' ')
		return (1);
	else if (s[0] == 'C' && s[1] == ' ')
		return (1);
	else
		return (0);
}

int check_duplicate_direction(char **sixlines)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(sixlines[i])
	{
		j = i + 1;
		while(sixlines[j])
		{
			if(!ft_strncmp(sixlines[i], sixlines[j], 2))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char *read_xpm(int fd)
{
	int		c;
	char	*buf;
	char	*s;

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
	if(ft_strlen(s) == 0)
		return NULL;
	return (s);
}

int full_xpm(char *s)
{
	int fd;
	char *str;

	fd = open(s, O_RDONLY);
	str = read_xpm(fd);
	if(!str)
		return (0);
	return (1);
}

int check_xpm_files(char ** sixlines)
{
	int i;
	char *s;
	int j;

	i = 0;
	while(sixlines[i])
	{
		j = 0;
		if(!ft_strchr(sixlines[i], ','))
		{
			s = ft_strchr(sixlines[i], ' ');
			if(s[j] == ' ')
				while(s[j] == ' ')
					++s;
			if(open(s, O_RDWR, 777) == -1 || ft_strcmp(ft_strrchr(s, '.'), ".xpm") != 0 || !full_xpm(s))
				return (0);
			i++;
		}
		else
			i++;
	}
	return (1);
}

int check_colors_utils(char *s, int *k)
{
	int i;

	i = 0;
	while(s[i] == ' ')
		i++;
	while(s[i] && s[i] != ' ')
	{
		if(s[i] != ',' && !ft_isdigit(s[i]))
			return (0);
		if(s[i] == ',')
			(*k)++;
		i++;
	}
	if(s[i] == ' ')
		return (0);
	return (1);
}

int check_colors(char **sixlines, int i, int k, int j)
{
	char **tmp;
	char *str;

	while(sixlines[++i])
	{
		if(ft_strchr(sixlines[i], ','))
		{
			str = ft_strchr(sixlines[i], ' ');
			++str;
			if(!check_colors_utils(str, &k))
				return (0);
			if(k != 2)
				return (0);
			k = 0;
			tmp = ft_split(str, ',');
			j = -1;
			while(tmp[++j])
				if(ft_atoi(tmp[j]) > 255 || ft_atoi(tmp[j]) < 0)
					return 0;
			ft_free_str_map(NULL, tmp);
			if(j != 3)
				return (0);
		}
	}
	return (1);
}

int check_player(char **map, int i)
{
	int j;
	int p;

	p = 0;
	while(map[i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'E' || map[i][j] == 'W')
					p++;
		}
		i++;
	}
	if(p != 1)
		return (0);
	return (1);
}

int check_player_map_elems(char **map, int i,  char *p)
{
	int j;

	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' \
				&& map[i][j] != 'N' && map[i][j] != 'S' \
				&& map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != ' ')
					return (0);
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'E' || map[i][j] == 'W')
				*p = map[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

int check_map_utils(char **map, int i, int j, char p)
{
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0' \
		&& map[i][j + 1] != p)
		return (0);
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0' \
		&& map[i][j - 1] != p)
		return (0);
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0' \
		&& map[i + 1][j] != p)
		return (0);
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0' \
		&& map[i - 1][j] != p)
		return (0);
	return (1);
}

int check_map_surround(char **map, int i, char c, char p)
{
	int j;
	int k;

	k = 0;
	while(map[k])
		k++;
	while(map[i])
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][0] == c || (map[6][j] != '1' && map[6][j] != ' ' && i == 6) \
				|| (map[k - 1][j] != '1' && map[k - 1][j] != ' ' && i == k - 1))
					return (0);
			if(map[i][j] == c && i != 6 && i != k - 1)
				if(!check_map_utils(map, i, j, p))
					return(0);
		}
		i++;
	}
	return (1);
}