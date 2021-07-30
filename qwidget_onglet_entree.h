#ifndef QWIDGET_ONGLET_ENTREE_H
#define QWIDGET_ONGLET_ENTREE_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QDateEdit>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QCompleter>
#include <QVector>
#include <QApplication>
#include <QDoubleValidator>
#include <QRegExpValidator>
#include <QRegExp>
#include <QValidator>
#include <QMessageBox>
#include <QKeyEvent>
#include <QPoint>

#include "database.h"
#include "dialogbox_selection_produit_entree.h"
#include "dialogbox_modifier_entree.h"



class qwidget_onglet_entree : public QWidget
{
    Q_OBJECT
public:

    qwidget_onglet_entree();

    QLabel * m_label_date;
    QDateEdit * m_dateEdit_date_entree;
    QLabel * m_label_ref_entre_from_db;
    QLineEdit * m_lineEdit_depot;
    QLineEdit * m_lineEdit_rayon;
    QLineEdit * m_lineEdit_etagere;
    QLineEdit * m_lineEdit_commentaire;
    QLineEdit * m_lineEdit_ref_article;
    QLineEdit * m_lineEdit_designation;
    QLineEdit * m_lineEdit_quantite;
    QLineEdit * m_lineEdit_prix;
    QLineEdit * m_lineEdit_unite;
    QPushButton * m_pushbutton_enregistrer;
    QPushButton * m_pushbutton_modifier;
    QPushButton * m_pushbutton_supprimer;
    QPushButton * m_pushbutton_annuler;
    QTableView * m_tableview_entree;
    QLineEdit * m_lineEdit_famille;
    QLineEdit *m_lineEdit_prix_unitaire;
    QDateEdit * m_dateEdit_date_initial_filtre;
    QDateEdit * m_dateEdit_date_finale_filtre;
    QLineEdit * m_lineEdit_filtre_Famille;
    QLineEdit * m_lineEdit_filtre_designation;
    QPushButton * m_pushbutton_filtre_valider;
    QPushButton * m_pushbutton_filtre_effacer;
    QLineEdit * m_lineEdit_fournisseur;
    QLabel * m_label_ref_entre;

    dialogbox_selection_produit_entree * m_dialog_selection_produit;
    dialogbox_modifier_entree * m_dialogbox_modifier_entree;

    // Fonction ----------------------------
    void load_table_Entree();
    void load_label_ref_entree(QLabel *label, const char * nom_table, const char * id ,const char *prefix);
    void completer_lineEdit(QLineEdit *line_edit, const char *table_bd, const char *nom_colonne);
    void auto_complete_by_ref();
    void auto_complete_by_Designation();
    void execut_validation();
    void reinitialiser_saisie_entree();
    void value_required(const char *txt);

private:
    QGridLayout * m_gridlayout_pp;    
    QLabel * m_label_depot;
    QLabel * m_label_rayon;
    QLabel * m_label_etagere;
    QLabel * m_label_commentaire;
    QHBoxLayout * m_hboxlayout_commentaire;
    QHBoxLayout *m_hboxlayout_date;
    QHBoxLayout * m_hboxlayout_ref;
    QHBoxLayout *  m_hboxlayout_depot;
    QHBoxLayout * m_hboxlayout_rayon;
    QHBoxLayout * m_hboxlayout_etager;
    QHBoxLayout * m_hboxlayout_quantite_unite_prix;
    QHBoxLayout * m_hboxlayout_puhsbutton;
    QLabel * m_label_filtre_date_de;
    QLabel * m_label_filtre_date_a;

    QLabel * m_label_fournisseur;

    QGroupBox * m_groupbox_filtre;
    QGridLayout * m_gridlayout_filtre;
    QHBoxLayout * m_hboxlayout_filtre_date;
    QHBoxLayout *m_hboxlayout_filtre_famille_designation;
    QHBoxLayout * m_hboxlayout_filtre_boutton;

    QGroupBox * m_groupbox_info;
    QGridLayout *m_gridlayout_info;

    void keyPressEvent(QKeyEvent * event);

public slots:
    void on_text_change_lineEdit_Ref();
    void on_text_change_lineEdit_Designation();
    void on_click_bt_valider();
    void contextMenu(QPoint point);
    void on_click_action_modifier();
};

#endif // QWIDGET_ONGLET_ENTREE_H
