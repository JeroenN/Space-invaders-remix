CONFIG += qt console

SOURCES += code.cpp

win32 {
  QMAKE_CXXFLAGS += -std=c++1y
}

unix:!macx {
  QMAKE_CXXFLAGS += -std=c++11
}

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

