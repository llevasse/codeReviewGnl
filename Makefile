#---COMMON_VAR-----------------------------------
NAME			=	review
CC				=	cc
RM				=	rm -rf

SRC1			=	repo_1/get_next_line.c repo_1/get_next_line_utils.c
SRC2			=	repo_2/get_next_line.c repo_2/get_next_line_utils.c
MAIN			=	main.c
OBJS1			=	$(SRC1:.c=.o)
OBJS2			=	$(SRC2:.c=.o)
INC1			= -I repo_1
INC2			= -I repo_2

# ----
FLAGS			=	-Wall -Werror -Wextra

#---RULES----------------------------------------

all:			$(NAME)

$(NAME):		$(OBJS1) $(OBJS2)
				$(CC) $(FLAGS) $(INC1) $(OBJS1) $(MAIN) -o $@_repo1
				$(CC) $(FLAGS) $(INC2) $(OBJS2) $(MAIN) -o $@_repo2

%.o:	%.c
				$(CC) $(FLAGS) -c $< -o $@


clean:
				$(RM) $(OBJS1) $(OBJS2)

fclean:			clean
				rm -f $(NAME)_repo1 $(NAME)_repo2

re:				fclean all

.PHONY:			all clean fclean re
