CONFIG += qt console

SOURCES += code.cpp

win32 {
  QMAKE_CXXFLAGS += -std=c++1y
}

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

