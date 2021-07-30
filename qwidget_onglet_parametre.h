#ifndef QWIDGET_ONGLET_PARAMETRE_H
#define QWIDGET_ONGLET_PARAMETRE_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QStringList>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>


class qwidget_onglet_parametre : public QWidget
{
    Q_OBJECT
public:
    qwidget_onglet_parametre();

private:
    QGridLayout * m_gridlayout_pp;
    QGroupBox * m_groupbox_Mon_entreprise;
    QLineEdit * m_lineEdit_raison_sociale;
    QLineEdit * m_lineEdit_activite;
    QLineEdit * m_lineEdit_adresse;
    QLineEdit * m_lineEdit_complement;
    QLineEdit * m_lineEdit_ville;
    QLineEdit * m_lineEdit_pays;
    QLineEdit * m_lineEdit_commentaire;
    QLineEdit * m_lineEdit_statistique;
    QLineEdit * m_lineEdit_nif;
    QLineEdit * m_lineEdit_num_identifiant;

    QGridLayout * m_gridlayout_mon_entreprise;
    QGroupBox * m_groupbox_telecom;
    QGridLayout * m_gridlayout_telecom;
    QLineEdit * m_lineEdit_telephone;
    QLineEdit * m_lineEdit_e_mail;
    QLineEdit * m_lineEdit_site;
    QLineEdit * m_lineEdit_telecopie;

    QGroupBox * m_groupbox_gestion_unite;
    QVBoxLayout * m_vboxlayout_gestion_unite;
    QPushButton * m_pushbutton_u_grandeur;
    QPushButton * m_pushbutton_u_monaitair;

    QGroupBox * m_groupbox_gestion_emplacement;
    QVBoxLayout * m_vboxlayout_gestion_emplacement;
    QPushButton * m_pushbutton_depot;
    QPushButton * m_pushbutton_rayon;
    QPushButton * m_pushbutton_etagere;

};

#endif // QWIDGET_ONGLET_PARAMETRE_H
