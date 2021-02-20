# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 15:04:29 by cromalde          #+#    #+#              #
#    Updated: 2021/01/26 15:25:37 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		-*- Makefile -*-	 #

NAME		=	cub3D
INC			=	-I ./minilibx1 ./minilibx2 ./libft
INCL		=	-I includes/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
LFLAGS 		=	-L ./minilibx1  -L ./minilibx2
FRAMEFLAG	=	-lmlx -framework OpenGL -framework AppKit
AR			=	ar rc
RM			=	rm -rf
PARAM		=	srcs/params_parsing/ft_utils.c \
				srcs/params_parsing/get_texture.c \
				srcs/params_parsing/parsingfunc.c \
				srcs/params_parsing/gt_res_flr_sky.c \
				srcs/params_parsing/map_parsing.c \
				srcs/params_parsing/map_utils.c \
				srcs/params_parsing/save_obj.c 

MOV			=	srcs/movement/key_event.c \
				srcs/movement/movement.c \
				srcs/movement/pitch_crc_jmp.c \
				srcs/movement/rotation.c \
				srcs/movement/mouse.c

SRCS		=	srcs/main.c \
				srcs/game.c \
				srcs/bitmap.c \
				srcs/img_init.c \
				srcs/spriter.c \
				srcs/text_init.c \
				srcs/usefutils.c \
				srcs/put_flornsky.c \
				srcs/initrend.c \
				srcs/wall_rend.c \
				srcs/putobjs.c \
				srcs/weapon.c \
				srcs/hud.c \
				srcs/game_over.c \
				srcs/ammodda.c \
				srcs/ft_utils_2.c \
				$(PARAM) \
				$(MOV)

OBJS		= $(SRCS:.c=.o)

.PHONY:		all re clean fclean bonus test

all:	${NAME}
	@echo "\033[0;32mMaking up All you'r project"
	@echo "\033[0m"

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) $(INC) $(INLC) -c $< -o $@

$(NAME): $(OBJS)
	make bonus -C ./libft
	make -C ./minilibx1
	cp ./minilibx1/libmlx.dylib ./
	$(CC) $(CFLAGS) $(LFLAGS) $(FRAMEFLAG) $(OBJS) $(INCL) ./libft/libft.a -o $(NAME)

bonus:	$(NAME)
	@echo "\n\033[0;33mRunning Bonus"
	./$(NAME) "Bon_map.cub"
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	@make clean -C ./libft
	$(RM) $(OBJS)
	$(RM) Cube3dshot.bmp
	@echo "\033[0m"

fclean:	clean
	@echo "\033[0;31mRemoving executable"
	@make fclean -C ./libft
	$(RM) $(NAME)
	@echo "\033[0m"

re:	fclean all
