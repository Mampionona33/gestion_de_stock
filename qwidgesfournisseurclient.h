#ifndef QWIDGESFOURNISSEURCLIENT_H
#define QWIDGESFOURNISSEURCLIENT_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QToolBar>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QGroupBox>
#include <QComboBox>
#include <QFormLayout>
#include <QStringList>
#include <QTableView>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QCompleter>
#include <QPoint>
#include <QModelIndexList>
#include <QApplication>
#include <QClipboard>
#include <QVector>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QFile>
#include <QProcess>
#include <QDate>
#include <QPrinter>
#include <QSignalMapper>

#include "database.h"
#include "dialogbox_modifier_tiers.h"
#include "dialogbox_detail_tableview.h"
#include "dialogbox_suppr_ligne_tableview_tiers.h"

/*
 * Claasse a pour but de remplir l'onglet Fournisseur/Client
 * l'onglet permet :
 * @ la saisie de nouvelle Fournisseur/client
 * @ la modification et suppression
 * @ l'affichage des liste de chaque catégorie
 * @ l'exportatiion de chaque lite sous le format csv et pdf
 */
class QwidgesFournisseurClient : public QWidget
{
    Q_OBJECT
public:
    explicit QwidgesFournisseurClient(QWidget *parent = nullptr);
    QGridLayout *m_gridLayoutPp;
    QMenuBar *m_menuBarAnnuaire;
    QMenu *m_menuFichier;
    QMenu *m_menuViderListe;

    QGroupBox *m_groupBoxNouveau;
    QComboBox *m_comboBoxCat;
    QGridLayout *m_gridLayoutNouv;
    QFormLayout *m_formLayoutNouv;
    QLabel *m_labelCodeCat;
    QComboBox *m_comboBoxType;
    QLineEdit *m_lineEditeRaisonSoc;
    QLineEdit *m_lineEditeSiteInternet;
    QTextEdit *m_textEditObservation;
    QGroupBox *m_groupBoxContact;
    QFormLayout *m_formLayoutContact;
    QComboBox *m_comboBoxCivilite;
    QLineEdit *m_lineEditeNomContact;
    QLineEdit *m_lineEditePrenomContact;
    QLineEdit *m_lineEditeAdresseContact;
    QLineEdit *m_lineEditeTel1Contact;
    QLineEdit *m_lineEditeTel2Contact;
    QLineEdit *m_lineEditeAdresseEmailContact;
    QHBoxLayout *m_hboxLayoutBoutton;
    QPushButton *m_pushButtonValider;
    QPushButton *m_pushButtonAnnuler;

    QGroupBox *m_groupBoxListFou;
    QTableView *m_tableViewFournisseur;
    QGridLayout *m_gridLayoutFou;

    QGroupBox *m_groupBoxListClient;
    QTableView *m_tableViewClient;
    QGridLayout *m_gridLayoutClient;

    QGroupBox *m_groupBoxFiltre;
    QGridLayout *m_gridLayoutFiltre;
    QFormLayout *m_formLayoutFiltre;
    QLineEdit * m_lineEditeFiltre;
    QHBoxLayout *m_hboxLayoutFilterBt;
    QPushButton *m_pushButtonRechercher;
    QPushButton * m_pushButtonEffacer;
    QHBoxLayout * m_hboxLayoutFilterCB;
    QComboBox * m_comboBoxFilter;
    QComboBox *m_comboBoxFilterCat;

    dialogbox_modifier_tiers * m_dialogboxModifierTiers;
    dialogbox_detail_tableView * m_dialogboxDetail;
    dialogBox_suppr_ligne_tableView_tiers * m_dialogBox_Avertissement_suppr;


private:
    void load_list_TableView(QTableView * Table, const char *nomTable);
    void creeCode(const char * Nom_Table);
    void load_list_civilite();
    void reinitialiser_saisie();
    void vider_Table(QTableView * table_view, const char * NomTable);
    void valider_entree();
    void keyPressEvent(QKeyEvent * event);
    void reinitialiser_filtre_cat();
    void completer_filter(const char * NomTable, const char * NomColonne);
    void contextMenu_TableView(const char *Type_de_tiers, QTableView * Nom_tableView, const char *nom_table_bd, QPoint position);
    void copy_selected_row_tableview(QTableView * tableView);
    void valider_Modif_dialogBox_ModifTiers(QTableView *nom_table, const char *nomTable);
    void supprimer_ligne_tableView(QTableView * Nom_tableView, const char * nomTableBd);
    void enregistrer_tableau_sous(QTableView *Nom_tableview);

signals:

public slots:
    void catChange();
    void click_bt_valider();
    void vider_list_Four();
    void vider_list_Client();
    void click_bt_annuler();
    void on_comboBox_Filter_Cat_Index_Change();
    void on_comboBox_Filter_Index_Change();
    void on_click_bt_effacer_filtre();
    void on_click_bt_rechercher_filtre();
    void contextMenuFournisseur(QPoint Position);
    void contextMenuClient(QPoint Position);
    void copy_selectedRow_tableview_Fournisseur();
    void ouvrir_dialogBox_Modifier_Tiers();
    void on_click_bt_valider_dialogBoxModif_Fournisseur();    
    void on_click_action_afficher_detail();
    void on_click_action_supprimer();
    void on_click_bt_valider_dialogBoxSupp_Fournisseur();
    void on_click_bt_valider_dialogBoxSupp_Client();
    void on_click_action_enregistrerSous();

};

#endif // QWIDGESFOURNISSEURCLIENT_H
