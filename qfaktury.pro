# #####################################################################
# Automatically generated by qmake (2.01a) Tue Mar 17 19:44:38 2009
# #####################################################################
TEMPLATE = app
TARGET = qfaktury
DEPENDPATH += .
INCLUDEPATH += .
QT += gui \
    xml
CONFIG += release

# Input
HEADERS += TowaryBruttoLista.h \
    Rachunek.h \
    FakturaBrutto.h \
    Duplikat.h \
    ConvertAmount.h \
    config.h \
    Faktura.h \
    InvoiceData.h \
    Kontrahenci.h \
    KontrahenciLista.h \
    Korekta.h \
    MainWindow.h \
    ProductData.h \
    Settings.h \
    Towary.h \
    TowaryLista.h \
    Ustawienia.h \
    Uzytkownik.h \
    ZmienIlosc.h
FORMS += Faktura.ui \
    Kontrahenci.ui \
    KontrahenciLista.ui \
    MainWindow.ui \
    Towary.ui \
    TowaryLista.ui \
    Ustawienia.ui \
    Uzytkownik.ui \
    ZmienIlosc.ui
SOURCES += TowaryBruttoLista.cpp \
    Rachunek.cpp \
    FakturaBrutto.cpp \
    Duplikat.cpp \
    ConvertAmount.cpp \
    Faktura.cpp \
    Kontrahenci.cpp \
    KontrahenciLista.cpp \
    Korekta.cpp \
    main.cpp \
    MainWindow.cpp \
    Towary.cpp \
    TowaryLista.cpp \
    Ustawienia.cpp \
    Uzytkownik.cpp \
    ZmienIlosc.cpp
RESOURCES += qfaktury.qrc
TRANSLATIONS += qfaktury_de.ts \
    qfaktury_en.ts \
    qfaktury_pl.ts
pixmaps.path = /usr/local/share/qfaktury/icons
pixmaps.files = icons/*.png
css.path = /usr/local/share/qfaktury/templates
css.files = templates/*.css
languages.path = /usr/local/share/qfaktury
languages.files = *.qm
target.path = /usr/local/bin
INSTALLS += target \
    pixmaps \
    css \
    languages
