CC = c++
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
NAME = Harl
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
FILE =  main Harl
HEADERS = Harl.hpp

SRCS = $(addsuffix .cpp, $(FILE))
OBJS = $(addsuffix .o, $(FILE))

%.o : %.cpp 
	@echo "$(BLUE)Building project ⏳.."
	@$(CC) $(CPPFLAGS)  -c -o $@ $< 

all: $(NAME)
	@echo "$(GREEN)✅ ALL DONE ✅"

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) -o $(NAME) $^


clean:
	@$(RM) $(OBJS)
	@echo  "$(RED)OBJS DELETED ☠ "

fclean: clean 
	@$(RM) $(NAME) $(LIBFT)
	@echo  "$(RED)ALL DELETED ☠ "


re: fclean all 