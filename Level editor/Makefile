#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := Line.cpp Rectangle.cpp Sprite.cpp ObjectContainer.cpp game.cpp Circle.cpp
# header files in this project
HEADERS := object.hpp game.hpp Rectangle.hpp Circle.hpp Line.hpp Sprite.hpp actions.hpp ObjectContainer.hpp GameOperators.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
