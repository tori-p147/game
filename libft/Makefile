
NAME = libft.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_memcpy.c ft_bzero.c ft_strlcpy.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c
BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstnew.c 
INCLUDES = -I.

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)

all: $(NAME) bonus

clean: 
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:
	@$(RM) $(NAME) $(OBJS) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re bonus