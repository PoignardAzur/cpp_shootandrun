##
## Makefile for shootandrun in /home/faure_o/rendu/cpp_va
## 
## Made by Olivier Faure
## Login   <faure_o@epitech.net>
## 
## Started on  Thu Jun 30 17:11:16 2016 Olivier Faure
## Last update Thu Jun 30 18:23:50 2016 Olivier Faure
##

have_term := $(shell echo $$TERM)

ifneq ($(have_term), xterm)
    color_str = @echo -n $1
    color_ln = @echo $1
else
    define color_str =
        @tput setaf $2
        @tput bold
        @echo -n $1
        @tput sgr0
    endef

    define color_ln =
        @tput setaf $2
        @tput bold
        @echo $1
        @tput sgr0
    endef
endif

CXX = 		clang++

RM = 		rm -rfv

NAME = 		shootandrun

CXXFLAGS +=	-W -Wall -Wextra
CXXFLAGS +=	-std=c++11 -O2
CXXFLAGS +=	-g3
LDFLAGS +=	-lsfml-graphics -lsfml-window -lsfml-system

SRCDIR = 	src
SRCS =		main.cpp		\
		LevelHandler.cpp	\
		Tilemap.cpp		\

OBJDIR = 	obj
OBJS =		$(SRCS:%.cpp=$(OBJDIR)/%.o)


all: 	info $(OBJS)
	@echo
	$(call color_ln, "Linking $(NAME)", 4)
	$(call color_str, "Flags are : ", 3)
	@echo $(LDFLAGS)
	@echo
	@$(CXX)  -o $(NAME) $(OBJS) $(LDFLAGS)

info:
	$(call color_ln, "Compiling "$(NAME), 4)
	$(call color_str, "Flags are : ", 3)
	@echo $(CXXFLAGS)
	@echo

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(call color_ln, "     Compiling $<", 2)
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	$(call color_ln, "Deleting obj folder", 4)
	@$(RM) $(OBJDIR)

fclean:	clean
	$(call color_ln, "Deleting binary", 4)
	@$(RM) $(NAME)


re:		fclean all

test:		fclean all clean

.PHONY: 	all clean fclean info re test

