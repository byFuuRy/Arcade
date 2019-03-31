##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## Makefile
##

SHELL	=	/bin/sh

INCLUDES=	-iquote Arcade/core/include -iquote Arcade/common/include

CORE	=	arcade
SFML	=	./lib/lib_arcade_sfml.so
SDL2	=	./lib/lib_arcade_sdl2.so
NCUR	=	./lib/lib_arcade_ncurses2.so
NIBBLER	=	./games/lib_arcade_nibbler.so

############ CORE ############
COMMON_SRC=	Arcade/common/src/ASprite.cpp	\
			Arcade/common/src/ATexture.cpp	\
			Arcade/common/src/Color.cpp		\
			Arcade/common/src/Rect.cpp		\
			Arcade/common/src/Vector.cpp

CORE_SRC=	Arcade/core/src/Core.cpp	\
			Arcade/core/src/Main.cpp

COMMON_OBJ=	$(COMMON_SRC:.cpp=.o)
CORE_OBJ=	$(CORE_SRC:.cpp=.o)
##############################

########## GRAPHICS ##########
NCUR_SRC=	Arcade/graphicals/ncurses/src/NCursesGraphicLib.cpp	\
			Arcade/graphicals/ncurses/src/NCursesRenderer.cpp	\
			Arcade/graphicals/ncurses/src/NCursesSprite.cpp		\
			Arcade/graphicals/ncurses/src/NCursesTexture.cpp

NCUR_OBJ=	$(NCUR_SRC:.cpp=.o)
##############################

############ GAME ############
NIBBLER_SRC=	Arcade/games/nibbler/src/NibblerGame.cpp

NIBBLER_OBJ=	$(NIBBLER_SRC:.cpp=.o)
##############################

CXX		=	g++
CXXFLAGS=	-Wall -Wextra

all:		core graphicals games

$(CORE):	CXXFLAGS+=	$(INCLUDES) -fPIC
$(CORE):	LDFLAGS	=	-ldl
$(CORE):	$(CORE_OBJ) $(COMMON_OBJ)
			$(CXX) -o $(CORE) $(COMMON_OBJ) $(CORE_OBJ) $(LDFLAGS)

$(NCUR):	INCLUDES+=	-iquote Arcade/graphicals/ncurses/include
$(NCUR):	CXXFLAGS+=	$(INCLUDES) -fPIC
$(NCUR):	LDFLAGS	=	-lncurses -shared
$(NCUR):	$(NCUR_OBJ) $(COMMON_OBJ)
			$(CXX) -o $(NCUR) $(COMMON_OBJ) $(NCUR_OBJ) $(LDFLAGS)

$(NIBBLER):	INCLUDES+=	-iquote Arcade/games/nibbler/include
$(NIBBLER):	CXXFLAGS+=	$(INCLUDES) -fPIC
$(NIBBLER):	LDFLAGS	=	-shared
$(NIBBLER):	$(NIBBLER_OBJ) $(COMMON_OBJ)
			$(CXX) -o $(NIBBLER) $(COMMON_OBJ) $(NIBBLER_OBJ) $(LDFLAGS)

core:		$(CORE)

graphicals:	$(NCUR)

games:		$(NIBBLER)

clean:
			$(RM) $(COMMON_OBJ)
			$(RM) $(CORE_OBJ)
			$(RM) $(NCUR_OBJ)
			$(RM) $(NIBBLER_OBJ)

fclean:		clean
			$(RM) $(CORE)
			$(RM) $(NCUR)
			$(RM) $(NIBBLER)

re:			fclean all

.PHONY:		all core clean fclean