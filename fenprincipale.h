#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

/*
 * Ceci est la fenetre principale
 */

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QTabWidget>
#include <QStyle>
#include <QShortcut>
#include <QPalette>

#include "QwidgetProduit.h"
#include "qwidgesfournisseurclient.h"
#include "tabwidget.h"
#include "qwidget_onglet_parametre.h"
#include "qwidget_onglet_entree.h"

class fenPrincipale:public QMainWindow
{
    Q_OBJECT
public:
    fenPrincipale();
     QwidgettProduit *m_widgettProduit;
     qwidget_onglet_entree * m_widget_entre;

     void reload_tab_entre_produit();
     void reload_tab_entre_fournisseur();

     void creat_ref_for_label(QLabel * label, const char * nom_table, const char *id, const char * prefix );

private:
    QWidget *m_centralWidget;
    QGridLayout *m_gridLayoutPple;  // Gridlayout Principale
    TabWidet *m_tabwidgetPple;    // Tabwidget contenant toute les onglet   
    QwidgesFournisseurClient *m_widgetFournisseurClient;
    qwidget_onglet_parametre * m_widget_parametre;

public slots:
    void on_click_valider_modif_prod();
    void on_click_valider_modif_fournisseur();
    void on_click_bt_valider_entree();
};

#endif // FENPRINCIPALE_H
