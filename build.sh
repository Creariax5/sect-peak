#!/bin/bash

echo "Start build"

# Set the source files
SOURCE_FILES=(
    "src/map/map.cpp"
    "src/map/planetMap.cpp"
    "src/map/spaceMap.cpp"
    "src/main.cpp"
    "src/var.cpp"
    "src/worldObj.cpp"
    "src/player.cpp"
    "src/select.cpp"
    "src/entity.cpp"
    "src/screens/loadingScreen.cpp"
    "src/screens/spaceScreen.cpp"
    "src/screens/planetScreen.cpp"
    "src/screens/currentScreen.cpp"
    "src/screens/hud/hud.cpp"
    "src/screens/hud/hudButton.cpp"
    )
# Set the output binary
OUTPUT_FILE="build/my_project"
# Directory for object files
OBJ_DIR="build"

# Include paths
INCLUDE_PATH="include"
# Library paths
LIBRARY_PATH="/usr/lib64"

# Ensure the build directory exists
mkdir -p $OBJ_DIR

# Compile each source file into an object file
for SOURCE_FILE in "${SOURCE_FILES[@]}"; do
    OBJ_FILE="$OBJ_DIR/$(basename ${SOURCE_FILE%.cpp}.o)"
    g++ -c $SOURCE_FILE -I$INCLUDE_PATH -o $OBJ_FILE
    if [ $? -ne 0 ]; then
        echo "Build failed during compilation of $SOURCE_FILE"
        exit 1
    fi
    OBJECT_FILES+=($OBJ_FILE)
done

# Link the object files into the final executable
g++ "${OBJECT_FILES[@]}" -L$LIBRARY_PATH -o $OUTPUT_FILE -lsfml-graphics -lsfml-window -lsfml-system

# Check if the link was successful
if [ $? -eq 0 ]; then
    echo "Build successful"
else
    echo "Build failed during linking"
    exit 1
fi

# Run the compiled program
./$OUTPUT_FILE
