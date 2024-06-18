# Snake Game on IOS

This is a classic Snake game implementation using C++ and the SFML library on macOS.

## Prerequisites

Before running the Snake game, ensure that you have the following installed on your macOS system:

- Xcode Command Line Tools
- Homebrew package manager
- SFML library

## Installation

1. Install Xcode Command Line Tools:
   - Open the Terminal.
   - Run the following command to install Xcode Command Line Tools:
     ```
     xcode-select --install
     ```
   - A pop-up window will appear asking you to install the command line tools. Click "Install" and follow the instructions.

2. Install Homebrew (if not already installed):
   - Open the Terminal.
   - Run the following command to install Homebrew:
     ```
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     ```
   - Follow the on-screen instructions to complete the installation.

3. Install the SFML library:
   - Open the Terminal.
   - Run the following command to install SFML using Homebrew:
     ```
     brew install sfml
     ```
   - Wait for the installation to complete.

4. Install the FreeType library:
   - Open the Terminal.
   - Run the following command to install FreeType using Homebrew:
     ```
     brew install freetype
     ```
   - Wait for the installation to complete.

5. Update the SFML library paths:
   - Locate the installed FreeType library file by running the following command in the Terminal:
     ```
     find /opt/homebrew/Cellar/freetype -name libfreetype.dylib
     ```
   - Take note of the path where the `libfreetype.dylib` file is found.
   - Run the following commands in the Terminal, replacing `/path/to/libfreetype.dylib` with the actual path found in the previous step:
     ```
     sudo install_name_tool -change /usr/local/opt/freetype/lib/libfreetype.dylib /path/to/libfreetype.dylib /usr/local/lib/libsfml-graphics.2.6.1.dylib
     sudo install_name_tool -change /usr/local/opt/freetype/lib/libfreetype.dylib /path/to/libfreetype.dylib /usr/local/lib/libsfml-graphics.dylib
     ```
   - Enter your macOS user password when prompted.

## Building and Running the Snake Game

1. Clone or download the Snake game project files to your local machine.

2. Open the Terminal and navigate to the project directory.

3. Compile the Snake game code using the following command:g++ -o snake snake.cpp -I/usr/local/include -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
  
4. Run the Snake game executable:
./snake
Copy
The Snake game window should open, and you can start playing using the arrow keys to control the snake's movement.

## Troubleshooting

If you encounter any issues while running the Snake game, please check the following:

- Ensure that you have followed all the installation steps correctly.
- Verify that the SFML and FreeType libraries are installed in the correct paths.
- Check that the SFML library paths have been updated correctly using the `install_name_tool` command.
- Make sure you are compiling the code with the correct compiler flags and linking against the necessary SFML libraries.

If you still face any problems or have further questions, please consult the SFML documentation, forums, or seek assistance from the SFML community.

Enjoy playing the Snake game!

