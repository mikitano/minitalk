# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkitano <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 16:26:27 by mkitano           #+#    #+#              #
#    Updated: 2025/07/26 16:26:30 by mkitano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRC_DIR := src
OBJ_DIR := obj

CC := cc
AR := ar
ARFLAGS := crs

CCFLAGS := -Wall -Wextra -Werror
DEPFLAGS := -MMD -MP
CPPFLAGS := -I include -I src/core -I src/gnl -I src/printf

RM = rm
RMFLAGS = -rf

CORE = ft_isalpha.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strdup.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

GNL = get_next_line.c

PRINTF = ft_printf.c \
	ft_address_hex.c \
	ft_putchar.c \
	ft_putnbr_dec.c \
	ft_putnbr_hex.c \
	ft_putnbr_u.c \
	ft_putstr.c \
	ft_strchr.c 

CORE_SRCS = $(addprefix $(SRC_DIR)/core/, $(CORE))
GNL_SRCS = $(addprefix $(SRC_DIR)/gnl/, $(GNL))
PRINTF_SRCS = $(addprefix $(SRC_DIR)/printf/, $(PRINTF))

CORE_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CORE_SRCS))
GNL_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(GNL_SRCS))
PRINTF_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(PRINTF_SRCS))

OBJECTS_ALL = $(CORE_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
DEPS = $(OBJECTS_ALL:.o=.d)

all : $(NAME)

$(NAME) : $(OBJECTS_ALL)
	$(AR) $(ARFLAGS) $@ $(OBJECTS_ALL)
	$(info CREATED $(NAME))

-include $(DEPS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CCFLAGS) $(DEPFLAGS) $(CPPFLAGS) -c $< -o $@

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	$(info All objects DELETED!)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	$(info Full clean COMPLETED!)

re: fclean all
	$(info Project REBUILD!)

.PHONY: all clean fclean re