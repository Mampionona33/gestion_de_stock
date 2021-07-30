QT += widgets sql core quick printsupport gui
CONFIG += c++11
QML_IMPORT_

SOURCES += \
    main.cpp \
    fenprincipale.cpp \
    database.cpp \
    popupmodifierproduit.cpp \
    dialogsupprprod.cpp \
    QwidgetProduit.cpp \
    qwidgesfournisseurclient.cpp \
    dialogbox_modifier_tiers.cpp \
    dialogbox_detail_tableview.cpp \
    dialogbox_suppr_ligne_tableview_tiers.cpp \
    qwidget_onglet_parametre.cpp \
    qwidget_onglet_entree.cpp \
    dialogbox_selection_produit_entree.cpp \
    dialogbox_modifier_entree.cpp

HEADERS += \
    fenprincipale.h \
    database.h \
    comboboxunite.h \
    popupmodifierproduit.h \
    dialogsupprprod.h \
    QwidgetProduit.h \
    qwidgesfournisseurclient.h \
    tabwidget.h \
    dialogbox_modifier_tiers.h \
    dialogbox_detail_tableview.h \
    dialogbox_suppr_ligne_tableview_tiers.h \
    qwidget_onglet_parametre.h \
    qwidget_onglet_entree.h \
    dialogbox_selection_produit_entree.h \
    dialogbox_modifier_entree.h
