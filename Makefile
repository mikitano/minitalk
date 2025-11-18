# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 18:15:28 by mkitano           #+#    #+#              #
#    Updated: 2025/11/18 18:15:45 by mkitano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
EXEC_C = $(BIN_DIR)/$(CLIENT)
EXEC_S = $(BIN_DIR)/$(SERVER)

BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus
EXEC_BC = $(BIN_DIR)/$(BONUS_CLIENT)
EXEC_BS = $(BIN_DIR)/$(BONUS_SERVER)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
LIBFT_DIR = libftx
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT_SRC_FILES = client.c
SERVER_SRC_FILES = server.c
BONUS_CLIENT_SRC_FILES = client_bonus.c
BONUS_SERVER_SRC_FILES = server_bonus.c

CLIENT_SRCS = $(addprefix $(SRC_DIR)/, $(CLIENT_SRC_FILES))
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRC_FILES:.c=.o)) 
HEADERS = $(addprefix $(INCLUDE_DIR)/, minitalk.h)

SERVER_SRCS = $(addprefix $(SRC_DIR)/, $(SERVER_SRC_FILES))
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRC_FILES:.c=.o)) 
HEADERS = $(addprefix $(INCLUDE_DIR)/, minitalk.h)

BONUS_CLIENT_SRCS = $(addprefix $(SRC_DIR)/, $(BONUS_CLIENT_SRC_FILES))
BONUS_CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_CLIENT_SRC_FILES:.c=.o)) 
HEADERS = $(addprefix $(INCLUDE_DIR)/, minitalk.h)

BONUS_SERVER_SRCS = $(addprefix $(SRC_DIR)/, $(BONUS_SERVER_SRC_FILES))
BONUS_SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SERVER_SRC_FILES:.c=.o)) 
HEADERS = $(addprefix $(INCLUDE_DIR)/, minitalk.h)

CC = cc
AR = ar
ARFLAGS = crs

CCFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(INCLUDE_DIR) -I $(LIBFT_DIR)/include
LDFLAGS = -L $(LIBFT_DIR) -lft

RM = rm
RMFLAGS = -rf

all: $(EXEC_C) $(EXEC_S)

bonus: $(EXEC_BC) $(EXEC_BS)

$(EXEC_C) : $(CLIENT_OBJS) $(LIBFT)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CCFLAGS) $(CLIENT_OBJS) $(LDFLAGS) -o $(EXEC_C)
		@echo "[\033[0;32mOK\033[0m] $(CLIENT) COMPILED in $(BIN_DIR)/!"

$(EXEC_S) : $(SERVER_OBJS) $(LIBFT)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CCFLAGS) $(SERVER_OBJS) $(LDFLAGS) -o $(EXEC_S)
		@echo "[\033[0;32mOK\033[0m] $(SERVER) COMPILED in $(BIN_DIR)/!"

$(EXEC_BC) : $(BONUS_CLIENT_OBJS) $(LIBFT)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CCFLAGS) $(BONUS_CLIENT_OBJS) $(LDFLAGS) -o $(EXEC_BC)
		@echo "[\033[0;32mOK\033[0m] $(BONUS_CLIENT) COMPILED in $(BIN_DIR)/!"

$(EXEC_BS) : $(BONUS_SERVER_OBJS) $(LIBFT)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CCFLAGS) $(BONUS_SERVER_OBJS) $(LDFLAGS) -o $(EXEC_BS)
		@echo "[\033[0;32mOK\033[0m] $(BONUS_SERVER) COMPILED in $(BIN_DIR)/!"

$(LIBFT) :
		@echo "[\033[0;33m...\033[0m] CREATING libft..."
		@$(MAKE) -C $(LIBFT_DIR) --silent

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CCFLAGS) $(IFLAGS) -c $< -o $@
		@echo "[\033[0;32mOK\033[0m] COMPILED $<"

clean :
		@$(RM) $(RMFLAGS) $(OBJ_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean --silent
		@echo "[\033[0;32mOK\033[0m] CLEAR files!"

fclean : clean
		@$(RM) $(RMFLAGS) $(BIN_DIR)
		@$(MAKE) -C $(LIBFT_DIR) fclean --silent
		@echo "[\033[0;32mOK\033[0m] ALL CLEAR!"

re : fclean all
		$(info Project REBUILD!)

.PHONY: all clean fclean re