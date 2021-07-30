#include "qwidget_onglet_parametre.h"

qwidget_onglet_parametre::qwidget_onglet_parametre()
{
    // Variables -------------------------------
    m_gridlayout_pp = new QGridLayout;
    m_groupbox_Mon_entreprise = new QGroupBox;
    m_lineEdit_raison_sociale = new QLineEdit;
    m_lineEdit_activite = new QLineEdit ;
    m_lineEdit_adresse = new QLineEdit;
    m_lineEdit_complement = new QLineEdit;
    m_lineEdit_ville = new QLineEdit;
    m_lineEdit_pays = new QLineEdit;
    m_lineEdit_commentaire = new QLineEdit;
    m_lineEdit_statistique = new QLineEdit;
    m_lineEdit_nif = new QLineEdit;
    m_lineEdit_num_identifiant = new QLineEdit;
    m_gridlayout_mon_entreprise = new QGridLayout;
    m_groupbox_telecom = new QGroupBox;
    m_gridlayout_telecom = new QGridLayout;
    m_lineEdit_telephone = new QLineEdit;
    m_lineEdit_e_mail = new QLineEdit;
    m_lineEdit_site = new QLineEdit;
    m_lineEdit_telecopie = new QLineEdit;

    m_groupbox_gestion_unite = new QGroupBox;
    m_vboxlayout_gestion_unite = new QVBoxLayout;
    m_pushbutton_u_grandeur = new QPushButton(tr("Unité de grandeur"));
    m_pushbutton_u_monaitair = new QPushButton(tr("Unité monaitaire"));

    m_groupbox_gestion_emplacement = new QGroupBox;
    m_vboxlayout_gestion_emplacement = new QVBoxLayout;
    m_pushbutton_depot = new QPushButton(tr("Dépôts"));
    m_pushbutton_rayon = new QPushButton(tr("Rayons"));
    m_pushbutton_etagere = new QPushButton(tr("Etagères"));
    //-------------------------------------------

    // GroupBox mon entreprise -----------------------
    m_groupbox_Mon_entreprise->setTitle(tr("Mon entreprise "));
    m_groupbox_Mon_entreprise->setLayout(m_gridlayout_mon_entreprise);
    QVector<QString> titre;
    titre << tr("Raison sociale") << tr("Activité") << tr("Adresse") << tr("Complément");
    titre << tr("CP/Ville") << tr("Région/Pays") << tr("Commentaire") << tr("STATISTIQUE") << tr("N° d'identification");


    for (int i=0 ; i< titre.size() ; ++i){
        QString titre_to_string = titre[i];
        QString nom_lable = titre_to_string;
        QLabel * label = new QLabel;
        label->setText(nom_lable);
        m_gridlayout_mon_entreprise->addWidget(label,i,0,1,1);
    }
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_raison_sociale,0,1,1,4);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_activite,1,1,1,4);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_adresse,2,1,1,4);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_complement,3,1,1,4);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_ville,4,1,1,4);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_pays,5,1,1,4);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_commentaire,6,1,1,4);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_statistique,7,1,1,1);
    QLabel * nif = new QLabel;
    nif->setText("NIF");
    m_gridlayout_mon_entreprise->addWidget(nif,7,2,1,1);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_nif,7,4,1,1);
    m_gridlayout_mon_entreprise->addWidget(m_lineEdit_num_identifiant,8,1,1,4);


    // Groupbox telecomm ---------------------------------------------
    m_groupbox_telecom->setLayout(m_gridlayout_telecom);
    m_groupbox_telecom->setTitle(tr("Télécommunication"));
    QVector<QString> telecomm_titre;
    telecomm_titre << tr("Téléphone") << tr("E-mail") << tr("Site");
    for (int i=0 ; i<telecomm_titre.size() ; ++i){
        QString telecomm_titre_to_string = telecomm_titre[i];
        QLabel * label_comm = new QLabel;
        label_comm->setText(telecomm_titre_to_string);
        m_gridlayout_telecom->addWidget(label_comm,i,0,1,1);
    }
    m_gridlayout_telecom->addWidget(m_lineEdit_telephone,0,1,1,1);
    QLabel * Telecopie = new QLabel;
    Telecopie->setText("Télécopie");
    m_gridlayout_telecom->addWidget(Telecopie,0,2,1,1);
    m_gridlayout_telecom->addWidget(m_lineEdit_telecopie,0,4,1,1);
    m_gridlayout_telecom->addWidget(m_lineEdit_e_mail,1,1,1,4);
    m_gridlayout_telecom->addWidget(m_lineEdit_site,2,1,1,4);

    // GroupBox Gestion d'unité -----------------------------------------
    m_groupbox_gestion_unite->setLayout(m_vboxlayout_gestion_unite);
    m_groupbox_gestion_unite->setTitle(tr("Géstion des unités"));
    m_vboxlayout_gestion_unite->addWidget(m_pushbutton_u_grandeur);
    m_vboxlayout_gestion_unite->addWidget(m_pushbutton_u_monaitair);

    // groupbox gestion des emplacement ----------------------------------
    m_groupbox_gestion_emplacement->setTitle(tr("Géstion des emplacement"));
    m_groupbox_gestion_emplacement->setLayout(m_vboxlayout_gestion_emplacement);
    m_vboxlayout_gestion_emplacement->addWidget(m_pushbutton_depot);
    m_vboxlayout_gestion_emplacement->addWidget(m_pushbutton_etagere);
    m_vboxlayout_gestion_emplacement->addWidget(m_pushbutton_rayon);

    //------------------------------------------------
    m_gridlayout_pp->addWidget(m_groupbox_Mon_entreprise,0,0,4,5);
    m_gridlayout_pp->addWidget(m_groupbox_telecom,5,0,2,5);
    m_gridlayout_pp->addWidget(m_groupbox_gestion_unite,0,6,2,1);
    m_gridlayout_pp->addWidget(m_groupbox_gestion_emplacement,0,7,3,1);

    this->setLayout(m_gridlayout_pp);
}
