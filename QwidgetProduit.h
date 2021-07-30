#ifndef GRIDLAYOUTPRODUIT_H
#define GRIDLAYOUTPRODUIT_H

#include <QGridLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QComboBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QTableView>
#include <QPushButton>
#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QStringList>
#include <QLabel>
#include <QHeaderView>
#include <QCompleter>
#include <QMenu>
#include <QAbstractItemView>
#include <QModelIndex>
#include <QAction>
#include <QMessageBox>
#include <QClipboard>
#include <QApplication>
#include <QSpinBox>
#include <QKeyEvent>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QVector>
#include <QProcess>
#include <QShortcut>
#include <QPrinter>
#include <QTextDocument>
#include <QToolBar>
#include <QMenuBar>
#include <QDateTime>
#include <QItemSelectionModel>
#include <QModelIndexList>

#include "database.h"
#include "comboboxunite.h"
#include "popupmodifierproduit.h"
#include "dialogsupprprod.h"
#include "qwidget_onglet_entree.h"

using namespace  std;

/*
 * Classe permettant de créer un Qgridlayout
 * pour l'onglet Produit
 */

class QwidgettProduit : public QWidget
{
 Q_OBJECT
public:
    QwidgettProduit();
    void loadTableView(QTableView * tableView, const char *Table_Nom);
    void createProductCode();
    void remplirComboBoxNomProduit(QComboBox * combox);
    void remplirComboBoxCategorie(QComboBox * combox);
    void rafraichirComboboxNomProduit(QComboBox * combobox);
    void rafraichirComboboxCategorie(QComboBox * combobox);
    void reinitialiserNouveauProd();
    void effacerListCombobox(QComboBox * combobox);
    bool doublonProdExist(QLineEdit * lineEditNom);
    void validerNouvProd();
    void pressEnterKey();

    popUpModifierProduit *m_popUpDialogModifier;
    QLabel *m_labelCodeProduit;

private:
    QLineEdit *m_lineEditNomProduit;
    QToolBar *m_toolbarProduit;
    QLineEdit *m_lineEditNomCategorie;
    QFormLayout *m_formLayoutProduit;
    QSpinBox *m_spinBoxStockMinProduit;
    QTableView *m_tableViewProduit;
    QHBoxLayout *m_hboxLayoutProduit;
    QPushButton *m_pushButtonProduitValider;
    QPushButton *m_pushButtonProdsuitAnnuler;
    QGroupBox *m_groupBoxNouveauProd;
    QGridLayout *m_gridLayoutNouvProduit;
    QComboBox *m_comboBoxFiltreCategorie;
    QComboBox *m_comboBoxFiltreNomProduit;
    QFormLayout *m_formLayoutFiltreProduit;
    QGroupBox *m_groupBoxFiltreProduit;
    QGridLayout *m_gridLayoutFiltreProduit;
    comboBoxUnite *m_comboBoxUniteProduit;        
    dialogsupprProd *m_dialogSupProd;
    QTableView * m_tableViewProduitSup;
    QGroupBox * m_groupBoxProduitSup;
    QGridLayout *m_gridlayoutProdSup;
    QGroupBox * m_groupBoxProduit;
    QGridLayout * m_gridlayoutProd;
    QGridLayout *m_gridlayoutPrincipalProd;

    QMenuBar *m_menuBarProduit;
    QMenu *m_menuFichier;
    QMenu *m_menuVider;

    void keyPressEvent(QKeyEvent *event);


public slots:
    void click_bt_valider();
    void sortLineEditNomProduit();
    void sortLineEditCategorieProduit();
    void contexMenu(QPoint position);
    void ouvrir_popup_modifier_produit();
    void on_click_bt_valider_popup_modif();
    void annulerNouvProd();
    void filtreNomProd();
    void filtreCat();
    void ouvrirPopUpSuppressionProd();
    void validerSupprProd();
    void copy_selected_row();
    void enregistrer_sous();
    void click_action_Supp_ProdSupp();
    void click_Bt_Supp_Prod();
    void saisieNouvProd();

};

#endif // GRIDLAYOUTPRODUIT_H
