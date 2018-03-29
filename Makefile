# change these to proper directories where each file should be
SRCDIR      = src
OBJDIR      = obj
BINDIR      = bin
EXECUTABLE	= jigsaw
TARGET      = $(BINDIR)/$(EXECUTABLE)

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f


CXX_GENERATION_FLAGS= -O2 -g -c
CXX_INCLUDE_PATHS=  -I./src
CXX_WARNING_FLAGS= -Wall -fmessage-length=0
CXX_WINDOW_FLAGS=
CXXFLAGS= $(CXX_GENERATION_FLAGS) $(CXX_INCLUDE_PATHS) $(CXX_WARNING_FLAGS) $(CXX_WINDOW_FLAGS) 	

SFMLLIBS = -lsfml-graphics -lsfml-window -lsfml-system
DATALIBS = -ljsoncpp
LIBS =  $(SFMLLIBS) $(DATALIBS)
LDFLAGS =  $(LIBS) -Wall 


$(TARGET): $(OBJECTS)
	@$(CXX) $(OBJECTS) $(LDFLAGS) -o $@ 
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"



all:$(TARGET)

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(TARGET)
	@echo "Executable removed!"

