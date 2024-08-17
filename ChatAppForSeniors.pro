QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# Build output directories
DESTDIR = $$PWD/bin
MOC_DIR = $$PWD/moc
OBJECTS_DIR = $$PWD/obj
RCC_DIR = $$PWD/rcc

# Enable compiler warnings and define your own compiler flags if needed
QMAKE_CXXFLAGS += -Wall -Wextra

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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
# Add resources here if needed

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Platform-specific configurations

# Windows-specific settings
win32 {
    CONFIG += release
    QMAKE_CXXFLAGS_RELEASE += -O2
    QMAKE_LFLAGS += /SUBSYSTEM:WINDOWS
    DEFINES += WINDOWS_BUILD

    # Windows deployment - you can use windeployqt to package
    win32:CONFIG(release, debug|release): \
        QMAKE_POST_LINK += $$quote(windeployqt $$shell_quote($$DESTDIR/$${TARGET}.exe))
}

# macOS-specific settings
macx {
    CONFIG += release app_bundle
    QMAKE_CXXFLAGS_RELEASE += -O2 -Wall
    DEFINES += MACOS_BUILD

    # macOS deployment - use macdeployqt to create .app
    macx:CONFIG(release, debug|release): \
        QMAKE_POST_LINK += $$quote(macdeployqt $$shell_quote($$DESTDIR/$${TARGET}.app))
}

# Linux-specific settings
unix:!macx {
    CONFIG += release
    QMAKE_CXXFLAGS_RELEASE += -O2 -Wall
    DEFINES += LINUX_BUILD

    # Linux deployment - you can use linuxdeployqt or create AppImage
    unix:!macx:CONFIG(release, debug|release): \
        QMAKE_POST_LINK += $$quote(linuxdeployqt $$shell_quote($$DESTDIR/$${TARGET}) -appimage)
}

# Embedded systems (e.g., Raspberry Pi)
embedded {
    # Specific flags and libraries for cross-compilation
    # Set up your toolchain and specific paths here
    DEFINES += EMBEDDED_BUILD
    target.path = /opt/$${TARGET}/bin

    # Ensure that all dependencies are included for deployment on embedded systems
    QMAKE_POST_LINK += $$quote(rsync -avz $$DESTDIR/$${TARGET} root@yourdevice:/opt/$${TARGET}/bin)
}

# Install rules for Unix-based systems
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}

# Optional Subdirectories for modularization
SUBDIRS += \
    build.pro
