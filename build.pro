# Define the project type and target
TEMPLATE = app
TARGET = MyQtApp

# Include directories
INCLUDEPATH += $$PWD/include

# Source files
SOURCES += \
    main.cpp \
    mainwindow.cpp

# Header files
HEADERS += \
    mainwindow.h

# UI files
FORMS += \
    mainwindow.ui

# Resources
RESOURCES += \
    resources.qrc

# Common Configurations
CONFIG += c++11
QT += core gui widgets

# Platform-Specific Configurations

# Windows
win32 {
    # Compiler options
    QMAKE_CXXFLAGS += -O2

    # Linker options
    QMAKE_LFLAGS += -Wl,-subsystem,windows

    # Include platform-specific libraries
    LIBS += -luser32 -lgdi32

    # Define Windows-specific macros
    DEFINES += WINDOWS_BUILD
}

# macOS
macx {
    # Compiler options
    QMAKE_CXXFLAGS += -O2 -Wall

    # Linker options
    QMAKE_LFLAGS += -Wl,-dead_strip

    # Frameworks and libraries specific to macOS
    LIBS += -framework Cocoa -framework IOKit -framework CoreVideo

    # Define macOS-specific macros
    DEFINES += MACOS_BUILD

    # macOS app bundle setup
    CONFIG += app_bundle
    ICON = MyQtApp.icns
}

# Linux
unix:!macx {
    # Compiler options
    QMAKE_CXXFLAGS += -O2 -Wall

    # Linker options
    QMAKE_LFLAGS += -Wl,-O1

    # Libraries specific to Linux
    LIBS += -lm -ldl -lpthread

    # Define Linux-specific macros
    DEFINES += LINUX_BUILD
}

# Output directories
DESTDIR = $$PWD/bin
MOC_DIR = $$PWD/moc
OBJECTS_DIR = $$PWD/obj
RCC_DIR = $$PWD/rcc

# Install the target in the correct directories based on platform
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}

macx {
    target.path = /Applications
    INSTALLS += target
}

win32 {
    target.path = $$[QT_INSTALL_BINS]
    INSTALLS += target
}
