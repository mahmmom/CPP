NAME = identify

SRCS = main.cpp Base.cpp Identify.cpp
OBJS = $(SRCS:%.cpp=obj/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Create the obj directory if it doesn't exist
$(shell mkdir -p obj)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule to compile .cpp files to .o files in the obj directory
obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
