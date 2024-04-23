# Directories
SRC_DIR 	= src
OBJ_DIR 	= obj
BIN_DIR 	= bin
INC_DIR 	= inc
LOG_DIR 	= tmp
VSC_DIR 	= .vscode

# Compiler
CC = cc
DEBUG_FLAGS = -g     
NCURSES = -lncurses
PTHREAD = -lpthread

# Flags
CLEAN_FLAG      = clean
CLEAN_LOG_FLAG  = clean_log

# Targets
SERVER_TARGET := $(BIN_DIR)/server

# Compile the source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/server.c $(INC_DIR)/server.h
	$(CC) -c $< -o $@ $(DEBUG_FLAGS)   
	
# Create the SERVER executable
$(SERVER_TARGET): $(OBJ_DIR)/server.o
	$(CC) $< -o $@ $(NCURSES) $(PTHREAD) $(DEBUG_FLAGS)      

$(SERVER_FLAG): $(SERVER_TARGET)

# Clean object and binary files
$(CLEAN_FLAG):
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/* $(VSC_DIR)

# Clean log files
$(CLEAN_LOG_FLAG):
	rm -f $(LOG_DIR)/*.log
