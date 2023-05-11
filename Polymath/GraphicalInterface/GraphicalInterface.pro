QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Polynomial/monom.cpp \
    ../Polynomial/poly.cpp \
    main.cpp \
    mainwindow.cpp \
    tablewindow.cpp

HEADERS += \
    ../Polynomial/Postfix.hpp \
    ../Polynomial/monom.hpp \
    ../Polynomial/poly.hpp \
    ../Tables/AVLTreeTable.h \
    ../Tables/ChainMethod.hpp \
    ../Tables/LinearTableOnAnArray.h \
    ../Tables/MyExcepions.hpp \
    ../Tables/OpenHashTable.hpp \
    ../Tables/OrderedArray.hpp \
    ../Tables/TableInterface.hpp \
    ../Tables/linearListTable.hpp \
    mainwindow.h \
    tablewindow.h

FORMS += \
    mainwindow.ui \
    tablewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
