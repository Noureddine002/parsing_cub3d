NAME = cub
FLAGS = -Wall -Werror -Wextra
CC = gcc

SRCS = 	main.c \
		check_extension.c \
		helpfunctions.c\
		ft_split.c \
		get_map.c \
		check_map_elements.c \
		map_validation.c \
		get_struct_info.c


OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp header.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all