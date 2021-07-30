#include "dialogbox_modifier_tiers.h"

dialogbox_modifier_tiers::dialogbox_modifier_tiers(QDialog *parent):QDialog(parent)
{
    /*
     * dialoBox qui permet de modifier une ligne dans le tabeView des liste de Fournisseur
     * ou Client. ce dialogBox s'ouvre par la suite d'une click sur l'action du
     * contextMenu du tableView fournisseur ou client.
     */
    // Varriables -----------------------------------------
    m_gridlayout_dialogBox_Modif = new QGridLayout;

    m_groupBox_dialogBox_Modif_Societe = new QGroupBox;
    m_formLayout_dialogBox_Modif_societe = new QFormLayout;
    m_label_dialogBox_Modif_Categorie = new QLabel;
    m_label_dialogBox_Modif_Code = new QLabel;
    m_comboBox_dialogBox_Modif_Type_societe = new QComboBox;
    m_lineEdit_dialogBox_Modif_RaisonSociale = new QLineEdit;
    m_lineEdit_dialogBox_Modif_siteWeb = new QLineEdit;
    m_textEdit_dialogBox_Modif_Obs = new QTextEdit;


    m_formLayout_dialogBox_Modif_contact = new QFormLayout;
    m_groupBox_dialogBox_Modif_contact = new QGroupBox;
    m_comboBox_dialogBox_Civilite = new QComboBox;
    m_lineEdit_dialogBox_Modif_NomContact = new QLineEdit;
    m_lineEdit_dialogBox_Modif_PrenomsContact = new QLineEdit;
    m_lineEdit_dialogBox_Modif_Adresses = new QLineEdit;
    m_lineEdit_dialogBox_Modif_Tel1 = new QLineEdit;
    m_lineEdit_dialogBox_Modif_Tel2 = new QLineEdit;
    m_lineEdit_dialogBox_Modif_AdresseMail = new QLineEdit;

    m_pushButton_dialogBox_Modif_Annuler = new QPushButton(tr("Annuler"));
    m_pushButton_dialogBox_Modif_Valider = new QPushButton(tr("Valider"));
    m_hBoxLayout_dialogBox_Modif_pushbutton = new QHBoxLayout;
   //-----------------------------------------------------

    // GroupeBox Société ----------------------------------
    m_groupBox_dialogBox_Modif_Societe->setTitle(tr("Société"));
    m_groupBox_dialogBox_Modif_Societe->setLayout(m_formLayout_dialogBox_Modif_societe);
    QStringList typeSociete;
    typeSociete << "" << tr("SARL") << tr("EURL") << tr("SELARL") << tr("SA") << tr("SAS")<<tr("SASU") <<tr("SNC") << tr("SCP") << tr("SCOP ") << tr("SCIC") << tr("Entreprie Individuelle");
    m_comboBox_dialogBox_Modif_Type_societe->addItems(typeSociete);
    m_formLayout_dialogBox_Modif_societe->addRow(tr("Catégorie"),m_label_dialogBox_Modif_Categorie);
    m_formLayout_dialogBox_Modif_societe->addRow(tr("Code"),m_label_dialogBox_Modif_Code);
    m_formLayout_dialogBox_Modif_societe->addRow(tr("Type"),m_comboBox_dialogBox_Modif_Type_societe);
    m_formLayout_dialogBox_Modif_societe->addRow(tr("Raison sociale"),m_lineEdit_dialogBox_Modif_RaisonSociale);
    m_formLayout_dialogBox_Modif_societe->addRow(tr("Site web"),m_lineEdit_dialogBox_Modif_siteWeb);
    m_formLayout_dialogBox_Modif_societe->addRow(tr("Observation"),m_textEdit_dialogBox_Modif_Obs);
    m_textEdit_dialogBox_Modif_Obs->setMaximumWidth(200);
    m_formLayout_dialogBox_Modif_societe->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    // GroupBox Contact -----------------------------------------------------------------------
    m_groupBox_dialogBox_Modif_contact->setTitle(tr("Contact"));
    m_groupBox_dialogBox_Modif_contact->setLayout(m_formLayout_dialogBox_Modif_contact);

    m_formLayout_dialogBox_Modif_contact->addRow(tr("Civilité"),m_comboBox_dialogBox_Civilite);
    m_formLayout_dialogBox_Modif_contact->addRow(tr("Nom"),m_lineEdit_dialogBox_Modif_NomContact);
    m_formLayout_dialogBox_Modif_contact->addRow(tr("Prénoms"),m_lineEdit_dialogBox_Modif_PrenomsContact);
    m_formLayout_dialogBox_Modif_contact->addRow(tr("Adresse"),m_lineEdit_dialogBox_Modif_Adresses);
    m_formLayout_dialogBox_Modif_contact->addRow(tr("Telephone I"),m_lineEdit_dialogBox_Modif_Tel1);
    m_formLayout_dialogBox_Modif_contact->addRow(tr("Télephone II"),m_lineEdit_dialogBox_Modif_Tel2);
    m_formLayout_dialogBox_Modif_contact->addRow(tr("Adresse E-mail"),m_lineEdit_dialogBox_Modif_AdresseMail);
    m_formLayout_dialogBox_Modif_contact->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    // Remplir comboBox civilité
    QSqlQuery qry;
    qry.prepare("SELECT Designation FROM Table_Civilite");
    qry.exec();
    QStringList list_civilite;
    while (qry.next()) {
        list_civilite.append(qry.value(0).toString());
    }
    m_comboBox_dialogBox_Civilite->addItem("");
    m_comboBox_dialogBox_Civilite->addItems(list_civilite);

    // HboxLayout PushButton -----------------------------------------------------------------
    m_hBoxLayout_dialogBox_Modif_pushbutton->addWidget(m_pushButton_dialogBox_Modif_Valider);
    m_hBoxLayout_dialogBox_Modif_pushbutton->addWidget(m_pushButton_dialogBox_Modif_Annuler);
    //----------------------------------------------------------------------------------------
    m_gridlayout_dialogBox_Modif->addWidget(m_groupBox_dialogBox_Modif_Societe,0,0,7,3);
    m_gridlayout_dialogBox_Modif->addWidget(m_groupBox_dialogBox_Modif_contact,8,0,8,3);
    m_gridlayout_dialogBox_Modif->addLayout(m_hBoxLayout_dialogBox_Modif_pushbutton,19,1,1,1,Qt::AlignCenter);
    this->setLayout(m_gridlayout_dialogBox_Modif);


    // CONNECTION SLOT ---------------------------------------------------------------------
    connect(m_pushButton_dialogBox_Modif_Valider,SIGNAL(clicked(bool)),this,SLOT(accept()));
    connect(m_pushButton_dialogBox_Modif_Annuler,SIGNAL(clicked(bool)),this,SLOT(reject()));
}
