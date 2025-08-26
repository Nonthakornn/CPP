NAME = ex02
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp
BUILD_DIR = build
SRC_FILES = main.cpp Bureaucrat.cpp AForm.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp\
			PresidentialPardonForm.cpp

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
				$(RM) *.txt

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re