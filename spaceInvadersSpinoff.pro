CONFIG += qt console

SOURCES += code.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra # -Werror
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

