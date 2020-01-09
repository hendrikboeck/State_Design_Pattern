#########################################################################
# XRay State Machine (C++ Implementation)                               #
# Copyright (C) 2020 by Hendrik Boeck                                   #
#                                                                       #
# This program is free software: you can redistribute it and/or modify  #
# it under the terms of the GNU General Public License as published by  #
# the Free Software Foundation, either version 3 of the License, or     #
# (at your option) any later version.                                   #
#                                                                       #
# This program is distributed in the hope that it will be useful,       #
# but WITHOUT ANY WARRANTY; without even the implied warranty of        #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
# GNU General Public License for more details.                          #
#                                                                       #
# You should have received a copy of the GNU General Public License     #
# along with this program.  If not, see <http://www.gnu.org/licenses/>. #
#########################################################################

##
# Filename: Makefile
# Project : XRay State Machine (C++)
# Author  : Hendrik Boeck
# Version : 2020/01/02
#

# OS - SETTINGS
# Sets the target platform for the project
# Valid values for variable platform are unix and windows
ifeq ($(OS),Windows_NT)
PLATFORM = windows
else
PLATFORM = unixlike
endif

# COMPILER - SETTINGS
CXX = gcc
CXXFLAGS = -Wall
LDFLAGS =

# MAKEFILE SETTINGS
APP = XRayMachine
EXT = .c
SRCDIR = src
ifeq ($(OS),Windows_NT)
BUILDDIR = build\$(PLATFORM)
OBJDIR = $(BUILDDIR)\obj
else
BUILDDIR = build/$(PLATFORM)
OBJDIR = $(BUILDDIR)/obj
endif

# Source- and Objectfiles (path to files)
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(BUILDDIR)/%.d)
BUILD = build $(BUILDDIR) $(OBJDIR)

# Unix OS variables and clean settings
RM = rm
DELOBJ = $(OBJ) $(DEP)

# Windows OS variables and clean settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o) $(OBJ:$(OBJDIR)/%.o=$(BUILDDIR)\\*.d)

##
# TARGETS OF MAKEFILE
#

all: $(BUILDDIR)/$(APP)

# Build the app out of obj-files
$(BUILDDIR)/$(APP): $(OBJ)
	@echo "build $@"
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Create all dependencies
$(BUILDDIR)/%.d: $(SRCDIR)/%$(EXT)
	@echo "build $@ from $<"
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:$(BUILDDIR)/%.d=$(OBJDIR)/%.o) >$@

# Inlude all .h files
-include $(DEP)

# Building the o-files out of cpp-files with it's h-files  
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	@echo "build $@ from $<"
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

##
# CLEANING AND CREATING FOLDERS FOR UNIX
#

# Creates directories, if none exist
.PHONY: dir
dir:
	@echo "Building Directories"
	@mkdir -p $(BUILD)

# Cleans up the whole project
.PHONY: clean
clean:
	$(RM) -r -f $(DELOBJ)

# Only removes .d-files
.PHONY: tidy
tidy:
	$(RM) -f $(DEP)

##
# CLEANING AND CREATING FOLDERS IN WINDOWS
#

# Creates directories, if none exist
.PHONY: dirw
dirw:
	@echo "Building Directories"
	@mkdir $(BUILD)

# Cleans up the whole project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ)

# Only removes .d-files
.PHONY: tidyw
tidyw:
	$(DEL) $(DEP)
