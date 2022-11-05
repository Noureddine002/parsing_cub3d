#include "header.h"

int validate_map(char **six_lines, char **map, t_map *test)
{
    int i;
    char p;
    (void)test;

    i = -1;
    p = 0;
    while(six_lines[++i])
        if(!check_six_lines(six_lines[i]))
            return(printf("ERROR !"), 0);
    if(!check_duplicate_direction(six_lines))
        return(printf("Similar Directions !"), 0);
    if(!check_xpm_files(six_lines))
        return(printf("problem in textures !"), 0);
    if(!check_colors(six_lines, -1, 0, -1))
        return(printf("Invalid colors !"), 0);
    if(!check_player(map, i))
        return(printf("Error in player count !"), 0);
    if(!check_player_map_elems(map, 6, &p))
        return(printf("Invalid element in map !"), 0);
    if(!check_map_surround(map, 6, '0', p))
        return(printf("Map is invalid empty is not surrounded !"), 0);
    if(!check_map_surround(map, 6, p, '0'))
        return(printf("Map is invalid player is not surrounded !"), 0);
    //struct info
    return (1);
}

int check_map_ressources(char **map, t_map *test)
{
    int i;
    char **six_lines;

    (void)test;
    if(!map)
        return(0);
    i = -1;
    six_lines = malloc(sizeof(char *) * 6 + 1);
    if(!six_lines)
        ft_allocation_err();
    while(map[++i] && i < 6)
        six_lines[i] = ft_strdup(map[i]);
    six_lines[i] = NULL;
    if(!validate_map(six_lines, map, test))
    {
        ft_free_str_map(NULL, six_lines);
        return(0);
    }
    return(1);
}