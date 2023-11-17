CC = cc

CXXFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src

OBJ_DIR = ./obj

BONUS_DIR = ./bonus

# result file name
TARGET =

BONUS = 

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

OBJS = $(SRCS:.c=.o)

OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o,$(OBJS))

.PHONY: clean fclean re all bonus

all: $(TARGET) 

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# bonus target build
$(BONUS) :

bonus: $(BONUS)

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(TARGET) $(BONUS)
	
re: fclean all
