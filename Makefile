NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H = 	-I libft/includes

OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIB_DIR =	libft/

CFILE =		ft_printf.c \
			ft_initialize.c \
			ft_parse.c \
			ft_parse_flags.c \
			ft_parse_width.c \
			ft_parse_precision.c \
			ft_parse_size.c \
			ft_parse_type.c \
			ft_display.c \
			ft_display_d.c \
			ft_display_s.c \
			ft_display_u.c \
			ft_display_x.c \
			ft_display_p.c \
			ft_display_o.c \
			ft_display_ws.c \
			ft_display_c.c \
			ft_display_gz.c \
			ft_display_oth.c \
			ft_utils.c \
			ft_itoa_n.c \
			ft_get_arg.c

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
bonus:	all

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean fclean re
