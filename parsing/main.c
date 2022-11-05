#include "header.h"

int print_error(char *str, int ret)
{
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
    return (ret);
}

int main(int ac, char **av)
{
    int fd;
    char **map;
    t_map *test;

    test = malloc(sizeof(t_map));
	if (ac != 2)
	{
		printf("Error\n2 Arguments Needed\n");
		exit (1);
	}
    if(!check_extension(av[1]))
        return(printf("bad extension !"), 0);
    fd = open(av[1], O_RDONLY);
    if(fd == -1)
        return (printf("File not Found\n"), close(fd), 1);
    map = get_map(fd);
    if(!check_map_ressources(map, test))
        exit(0);
    puts("OKKKKKKKKKKK");
    return 0;
}