NAME =			libft.a

COMP =			gcc -Wall -Werror -Wextra -I includes -c -o

OBJ_DIR =		obj/
SRC_DIR =		srcs/

CFIND =     	$(CFILE:%=$(SRC_DIR)%)

CFILE =			ft_strcmp.c

OFILE =			$(CFILE:%.c=%.o)

OBJ =			$(addprefix $(OBJ_DIR), $(OFILE))

all:			$(OBJ_DIR) $(NAME)
				@echo LIBFT COMPLETE

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME): $(OBJ)
				@echo Create: libft.a
				@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
				@ranlib $(NAME)

$(OBJ): $(CFIND)
				@$(MAKE) $(OFILE)

$(OFILE):
				@echo Create: $(@:obj/%=%)
				@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
				@/bin/rm -rf $(OBJ_DIR)
				@echo Cleaned libft object files

fclean:			clean
				@/bin/rm -f $(NAME)
				@echo Cleaned $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re
