#ifndef DIALOGBOX_MODIFIER_TIERS_H
#define DIALOGBOX_MODIFIER_TIERS_H

#include <QObject>
#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QStringList>

#include "database.h"

class dialogbox_modifier_tiers : public QDialog
{
    Q_OBJECT
public:
    dialogbox_modifier_tiers(QDialog *parent = 0);


    QLabel *m_label_dialogBox_Modif_Categorie;
    QLabel * m_label_dialogBox_Modif_Code;
    QComboBox *m_comboBox_dialogBox_Modif_Type_societe;
    QLineEdit *m_lineEdit_dialogBox_Modif_RaisonSociale;
    QLineEdit *m_lineEdit_dialogBox_Modif_siteWeb;
    QTextEdit *m_textEdit_dialogBox_Modif_Obs;
    QComboBox *m_comboBox_dialogBox_Civilite;
    QLineEdit *m_lineEdit_dialogBox_Modif_NomContact;
    QLineEdit *m_lineEdit_dialogBox_Modif_PrenomsContact;
    QLineEdit *m_lineEdit_dialogBox_Modif_Adresses;
    QLineEdit *m_lineEdit_dialogBox_Modif_Tel1;
    QLineEdit *m_lineEdit_dialogBox_Modif_Tel2;
    QLineEdit *m_lineEdit_dialogBox_Modif_AdresseMail;

    QPushButton * m_pushButton_dialogBox_Modif_Valider;
    QPushButton * m_pushButton_dialogBox_Modif_Annuler;

private:
    QGridLayout *m_gridlayout_dialogBox_Modif;
    QGroupBox * m_groupBox_dialogBox_Modif_Societe;
    QGroupBox * m_groupBox_dialogBox_Modif_contact;
    QFormLayout * m_formLayout_dialogBox_Modif_societe;
    QFormLayout * m_formLayout_dialogBox_Modif_contact;
    QHBoxLayout * m_hBoxLayout_dialogBox_Modif_pushbutton;
};

#endif // DIALOGBOX_MODIFIER_TIERS_H
