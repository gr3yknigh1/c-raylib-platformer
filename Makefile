PROJECT_NAME = c_raylib_platformer

# Utilities
MKDIR = mkdir -p
RM    = rm -r

# Paths
BUILD_DIR = build
EXEC = $(BUILD_DIR)/$(PROJECT_NAME)

# Build commands
MAKE_ALL        = make all
CMAKE_CONFIGURE = cmake . -B
CMAKE_BUILD     = cmake --build


.PHONY: all, main, clean

all: main

main: configure
	$(CMAKE_BUILD) $(BUILD_DIR)

configure:
	[ -d $(BUILD_DIR) ] || $(MKDIR) $(BUILD_DIR)
	$(CMAKE_CONFIGURE) $(BUILD_DIR)

run:
	[ -d $(BUILD_DIR) ] || $(MAKE_ALL)
	$(EXEC)

clean:
	$(RM) $(BUILD_DIR)

