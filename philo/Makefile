NAME = philo

SRC =	main.c\
		parse_data.c\
		program_init.c\
		routine.c\
		routine_b.c\
		take_action.c\
		utils/ft_atoi.c\
		utils/ft_strlen.c\
		utils/utils_a.c\
		utils/utils_b.c

SRC_MAP = srcs/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

FLAGS = -Wall -Werror -Wextra

CC = clang

HDRS = -I includes/

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $@ $^ $(HDRS) $(FLAGS)
	@echo "\033[1m\033[32mSuccessfully Compiled\033[39m"

%.o: %.c
	$(CC) -o $@ -c $<  $(HDRS) $(FLAGS)

clean: 
	@rm $(OBJS)
	@echo "\033[1m\033[33mCleaning Object Files\033[39m"

fclean: 
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "\033[1m\033[31mPurged Objects and Executables\033[39m"

re: fclean all

.PHONY: all clean fclean re philo