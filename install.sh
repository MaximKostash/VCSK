#!/bin/bash

REPO_URL="https://github.com/MaximKostash/VCSK.git"
REPO_NAME="VCSK"
INSTALL_DIR="$HOME/bin"
EXECUTABLE_NAME="vcsk"

if ! command -v git &> /dev/null
then
    echo "Error: git is not installed. Please install git."
    exit 1
fi

if ! command -v cmake &> /dev/null
then
    echo "Error: cmake is not installed. Please install cmake."
    exit 1
fi

if ! pkg-config --exists glib-2.0
then
    echo "Error: glib is not installed. Please install glib."
    exit 1
fi

if ! pkg-config --exists gio-2.0
then
    echo "Error: gio is not installed. Please install gio."
    exit 1
fi

echo "All dependencies are installed."

if [ ! -d "$REPO_NAME" ]; then
    git clone "$REPO_URL"
    if [ $? -ne 0 ]; then
        echo "Error: Failed to clone the repository. Please check your internet connection and the repository URL."
        exit 1
    fi
else
    echo "Repository already exists. Skipping cloning."
fi

cd "$REPO_NAME"

BUILD_DIR="build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

cmake ..
if [ $? -ne 0 ]; then
    echo "Error: Failed to execute cmake."
    exit 1
fi

make
if [ $? -ne 0 ]; then
    echo "Error: Failed to execute make."
    exit 1
fi

if [ ! -f "$EXECUTABLE_NAME" ]; then
    echo "Error: Executable file '$EXECUTABLE_NAME' not found."
    echo "Please ensure your executable file is named '$EXECUTABLE_NAME' in CMakeLists.txt."
    exit 1
fi

mkdir -p "$INSTALL_DIR"
cp "$EXECUTABLE_NAME" "$INSTALL_DIR"
if [ $? -ne 0 ]; then
    echo "Error: Failed to copy the executable file."
    exit 1
fi

ln -sf "$INSTALL_DIR/$EXECUTABLE_NAME" "$HOME/.local/bin/$EXECUTABLE_NAME"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create the symbolic link."
    exit 1
fi

if ! grep -q "$HOME/.local/bin" ~/.bashrc; then
    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
    echo "Directory $HOME/.local/bin has been added to PATH. You can run your program after opening a new session or running 'source ~/.bashrc'."
else
    echo "Directory $HOME/.local/bin is already in PATH"
fi

echo "Installation completed successfully. Your executable file is located in $INSTALL_DIR"
echo "You can run your program by typing '$EXECUTABLE_NAME' in the terminal."