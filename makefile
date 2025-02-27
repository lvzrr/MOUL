NAME      := moul-bin

CC        := cc
CFLAGS    := -Wall -Werror -Wextra -O3

SRCDIR    := src
BUILDDIR  := .cache
TESTBDIR  := .test_cache

SRC       := $(wildcard $(SRCDIR)/*.c)
OBJ       := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))

OBJ       := $(filter-out $(MOL_OBJ), $(OBJ))

all: clean $(NAME)

$(NAME): $(OBJ) $(MOL_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MOL_OBJ)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	mkdir -p $(TESTBDIR)

clean:
	rm -rf $(BUILDDIR) $(TESTBDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

install:
	grep -qxF "export MOUL='$USER/.moul/'" ~/.zshrc || echo "export MOUL='$USER/.moul/'" >> ~/.zshrc
	grep -qxF "export MOUL_TEST_BIN='$USER/.moul/.test_cache'" ~/.zshrc || echo "export MOUL_TEST_BIN='$USER/.moul/.test_cache'" >> ~/.zshrc
	grep -qxF "export MOUL_BIN='~/.moul/.cache'" ~/.zshrc || echo "export MOUL_BIN='~/.moul/.cache'" >> ~/.zshrc
	grep -qxF "alias moul='$USER/.moul/moul-bin'" ~/.zshrc || echo "alias moul='$USER/.moul/moul-bin'" >> ~/.zshrc
	@echo "Installation complete! Please restart your shell or run 'source ~/.zshrc' to apply changes."
	$(MAKE) all

.PHONY: all clean fclean re install
