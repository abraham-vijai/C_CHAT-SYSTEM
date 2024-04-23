# Directories
SRC_DIR 	= src
OBJ_DIR 	= obj
BIN_DIR 	= bin
INC_DIR 	= inc
LOG_DIR 	= tmp
CLIENT_DIR 	= chat-client
SERVER_DIR 	= chat-server
VSC_DIR = .vscode

# Compiler
CC = cc
DEBUG_FLAGS = -g     
NCURSES = -lncurses
PTHREAD = -lpthread

# Targets
SERVER_TARGET := $(SERVER_DIR)/$(BIN_DIR)/server
CLIENT_TARGET := $(CLIENT_DIR)/$(BIN_DIR)/client

# Flags
SERVER_FLAG     = server
CLIENT_FLAG     = client
CLEAN_FLAG      = clean
CLEAN_LOG_FLAG  = clean_log
ALL_FLAG        = all

# Compile the source files
$(SERVER_DIR)/$(OBJ_DIR)/%.o: $(SERVER_DIR)/$(SRC_DIR)/server.c $(SERVER_DIR)/$(INC_DIR)/server.h
	$(CC) -c $< -o $@ $(DEBUG_FLAGS)   

$(CLIENT_DIR)/$(OBJ_DIR)/%.o: $(CLIENT_DIR)/$(SRC_DIR)/client.c $(CLIENT_DIR)/$(INC_DIR)/client.h
	$(CC) -c $< -o $@ $(DEBUG_FLAGS)   
	
# Create the server executable
$(SERVER_TARGET): $(SERVER_DIR)/$(OBJ_DIR)/server.o
	$(CC) $< -o $@ $(PTHREAD) $(DEBUG_FLAGS)   

# Create the client executable
$(CLIENT_TARGET): $(CLIENT_DIR)/$(OBJ_DIR)/client.o
	$(CC) $< -o $@ $(NCURSES) $(PTHREAD) $(DEBUG_FLAGS)      

# Combine client and server compilation
$(ALL_FLAG): $(SERVER_TARGET) $(CLIENT_TARGET)

# Clean object and binary files
$(CLEAN_FLAG):
	rm -rf $(SERVER_DIR)/$(OBJ_DIR)/*.o $(SERVER_DIR)/$(BIN_DIR)/* $(SERVER_DIR)/$(VSC_DIR)
	rm -rf $(CLIENT_DIR)/$(OBJ_DIR)/*.o $(CLIENT_DIR)/$(BIN_DIR)/* $(CLIENT_DIR)/$(VSC_DIR)

# Clean log files
$(CLEAN_LOG_FLAG):
	rm -f $(SERVER_DIR)/$(LOG_DIR)/*.log
	rm -f $(CLIENT_DIR)/$(LOG_DIR)/*.log	

# Phony targets
.PHONY: $(SERVER_FLAG) $(CLIENT_FLAG) $(ALL_FLAG) $(CLEAN_FLAG) $(CLEAN_LOG_FLAG)

# Define target-specific variables
$(SERVER_FLAG): CC  	:= $(CC)
$(CLIENT_FLAG): CC  	:= $(CC)
$(ALL_FLAG): CC   		:= $(CC)
$(CLEAN_FLAG): CC     	:= $(CC)
$(CLEAN_LOG_FLAG): CC	:= $(CC)

# Rules to compile server, client, or all
$(SERVER_FLAG): $(SERVER_TARGET)
$(CLIENT_FLAG): $(CLIENT_TARGET)


