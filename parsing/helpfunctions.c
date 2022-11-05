#include "header.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	a;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((a + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1 && s2)
	{
		while (s1[i])
			str[k++] = s1[i++];
		i = 0;
		while (s2[i])
			str[k++] = s2[i++];
		free((char *)s1);
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}

void	ft_allocation_err(void)
{
	write(2, "error in allocation\n", 20);
	exit(1);
}

char	**ft_free_str_map(char *s, char **map)
{
	int	i;

	i = 0;
	if (s)
		free(s);
	while (map[i])
		free(map[i++]);
	free(map);
	return (NULL);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if(!s1 || !s2)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
	&& s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	if (n > 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	c1;
	char	*str;
	int		i;

	c1 = (char )c;
	str = (char *)s;
	i = 0;
	if (c1 == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	char	*str;
	int		len;

	str = (char *)s;
	c1 = (char)c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c1)
			return (str + len);
		len--;
	}
	return (NULL);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	s;
	int ret;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
		||str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' )
		s = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	ret = r * s;
	if(ret > INT_MAX || ret < INT_MIN)
		return (0);
	return (ret);
}