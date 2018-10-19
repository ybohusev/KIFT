.PHONY: all, clean, fclean, re

SERVER = server
CLIENT = client

COMP = gcc

FLAGS += -Wall -Wextra -Werror
SPHINX_FLAGS = -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\"
COMPFLAGS = `pkg-config --cflags pocketsphinx sphinxbase`
LINLFLAGS = `pkg-config --libs pocketsphinx sphinxbase`

DIR_SERVER_SRC = server_src
DIR_SERVER_OBJ = server_obj
DIR_CLIENT_SRC = client_src
DIR_CLIENT_OBJ = client_obj
DIR_INC = ./includes

SRC_SERVER = 

SRC_SERVER += server.c
SRC_SERVER += define_command.c
SRC_SERVER += commands.c
SRC_SERVER += execute_command.c
SRC_SERVER += log.c
SRC_SERVER += init_sock.c
SRC_SERVER += listen_client.c

SERVER_SRCS = $(addprefix $(DIR_SERVER_SRC)/,$(SRC_SERVER))
SERVER_OBJS = $(addprefix $(DIR_SERVER_OBJ)/,$(SRC_SERVER:.c=.o))

SRC_CLIENT = 

SRC_CLIENT += client.c
SRC_CLIENT += init_sphinx.c
SRC_CLIENT += mic.c
SRC_CLIENT += send_to_server.c
SRC_CLIENT += init_sock.c
SRC_CLIENT += interface.c

CLIENT_SRCS = $(addprefix $(DIR_CLIENT_SRC)/,$(SRC_CLIENT))
CLIENT_OBJS = $(addprefix $(DIR_CLIENT_OBJ)/,$(SRC_CLIENT:.c=.o))

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	@$(COMP) -o $(SERVER) $(SERVER_OBJS) $(LINLFLAGS) -I $(DIR_INC)

$(CLIENT): $(CLIENT_OBJS)
	@$(COMP) -o $(CLIENT) $(CLIENT_OBJS) $(LINLFLAGS) -I $(DIR_INC)

$(DIR_SERVER_OBJ)/%.o: $(DIR_SERVER_SRC)/%.c
	@mkdir -p $(DIR_SERVER_OBJ)
	@$(COMP) -c -I $(DIR_INC) $(COMPFLAGS) -o $@ -c $<

$(DIR_CLIENT_OBJ)/%.o: $(DIR_CLIENT_SRC)/%.c
	@mkdir -p $(DIR_CLIENT_OBJ)
	@$(COMP) -c $(SPHINX_FLAGS) -I $(DIR_INC) $(COMPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(DIR_SERVER_OBJ)
	@rm -rf $(DIR_CLIENT_OBJ)

fclean: clean
	@rm	-f logs
	@rm	-f sphinx_log
	@rm -f $(SERVER)
	@rm -f $(CLIENT)

re: fclean all