#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <string.h>

typedef struct s_map
{
    int a;
    
} t_map;

size_t	ft_strlen(const	char *s);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_allocation_err(void);
int print_error(char *str, int ret);
char	**ft_free_str_map(char *s, char **map);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);


//parsing
int check_extension(char *str);
char **get_map(int fd);
int check_map_ressources(char **map, t_map *test);
int check_six_lines(char *s);
int check_duplicate_direction(char **sixlines);
int check_xpm_files(char ** sixlines);
int check_colors(char **sixlines, int i, int k, int j);
int check_player_map_elems(char **map, int i,  char *p);
int check_player(char **map, int i);
int check_map_surround(char **map, int i, char c, char p);

#endif
