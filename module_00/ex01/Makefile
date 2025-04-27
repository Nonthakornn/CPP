NAME = phonebook 
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADERS = Contact.hpp phoneBook.hpp
BUILD_DIR = build
SRC_FILES = main.cpp Contact.cpp phoneBook.cpp
OBJ_FILES = $(SRC_FILES:%.cpp= $(BUILD_DIR)/%.o)

all:			$(NAME)

$(NAME):		$(OBJ_FILES)
				$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_FILES):	$(BUILD_DIR)/%.o: %.cpp Makefile $(HEADERS) | $(BUILD_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
				@mkdir -p $(BUILD_DIR)

clean:
				$(RM) $(BUILD_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

