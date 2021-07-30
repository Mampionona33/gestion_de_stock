#include "qwidgesfournisseurclient.h"

QwidgesFournisseurClient::QwidgesFournisseurClient(QWidget *parent) : QWidget(parent)
{
    // Varriable --------------------------------------------------------------------
    m_gridLayoutPp = new QGridLayout;           // Grille Pricipale de l'onglet
    m_menuBarAnnuaire = new QMenuBar;           // Barre de menu Annuaire
    m_menuFichier = new QMenu;                  // Menu Fichier du barre de menu
    m_menuViderListe = new QMenu;               // Menu Vider la liste des tableau Fournisseur et/ou client

    m_groupBoxNouveau = new QGroupBox;          // regrouper tous les widgets de nouveau saisie
    m_comboBoxCat = new QComboBox;              // Categorie de l'entrée "Fournisseur" ou "Client"
    m_gridLayoutNouv = new QGridLayout;         // Grille principale du groupBoxNouveau
    m_formLayoutNouv = new QFormLayout;         // permet d'aligner tous les widgets du groupBoxNouveau
    m_labelCodeCat = new QLabel;                // permet d'afficher le code du FOurnisseur ou client qui vas etre saisie
    m_comboBoxType = new QComboBox;             // permet de choisir le type de scociété
    m_lineEditeRaisonSoc = new QLineEdit;       // permet de saisir le nom de la sociéte
    m_lineEditeSiteInternet = new QLineEdit;    // permet de saisir le site internet de la société
    m_textEditObservation = new QTextEdit;      // permet de saisir des observation sur la sociéta saisie
    m_groupBoxContact = new QGroupBox;          // permet de regrouper les widgets concernant le contact
    m_formLayoutContact = new QFormLayout;       // permet de regroupper les infos sur la personne à contacter
    m_comboBoxCivilite = new QComboBox;
    m_lineEditeNomContact = new QLineEdit;
    m_lineEditePrenomContact = new QLineEdit;
    m_lineEditeAdresseContact = new QLineEdit;
    m_lineEditeTel1Contact = new QLineEdit;
    m_lineEditeTel2Contact = new QLineEdit;
    m_lineEditeAdresseEmailContact = new QLineEdit;
    m_hboxLayoutBoutton = new QHBoxLayout;
    m_pushButtonAnnuler = new QPushButton(tr("Annuler"));
    m_pushButtonValider = new QPushButton(tr("Valider"));

    m_groupBoxFiltre = new QGroupBox;
    m_gridLayoutFiltre = new QGridLayout;
    m_hboxLayoutFilterBt = new QHBoxLayout;
    m_pushButtonRechercher = new QPushButton(tr("Rechercher"));
    m_pushButtonEffacer = new QPushButton(tr("Effacer"));
    m_hboxLayoutFilterCB = new QHBoxLayout;
    m_comboBoxFilter = new QComboBox;
    m_lineEditeFiltre = new QLineEdit;
    m_comboBoxFilterCat = new QComboBox;


    m_groupBoxListFou = new QGroupBox;          // regroupe les élements de la listes des fournisseurs
    m_tableViewFournisseur = new QTableView;    // permet d'afficher la liste des fournisseur
    m_gridLayoutFou = new QGridLayout;          // grille permet de placer le table pour la liste des fournisseurs

    m_groupBoxListClient = new QGroupBox;       // permet regrouper les widget concernant la liste des Clients
    m_gridLayoutClient = new QGridLayout;       // grille permet de placer le tableau "liste des client"
    m_tableViewClient = new QTableView;         // permet d'afficher  la liste des clients

    m_dialogboxModifierTiers = new dialogbox_modifier_tiers;
    m_dialogboxDetail = new dialogbox_detail_tableView;
    m_dialogBox_Avertissement_suppr = new dialogBox_suppr_ligne_tableView_tiers;
    //-------------------------------------------------------------------------------

    // ToolBar ----------------------------------------------------------------------
    QAction *actionViderListeFour = new QAction(tr("Fournisseurs"));
    QAction *actionViderListeClient = new QAction(tr("Clients"));

    m_menuViderListe->setTitle(tr("Vider la liste"));
    m_menuViderListe->addAction(actionViderListeFour);
    m_menuViderListe->addAction(actionViderListeClient);

//    QAction * actionEnregistrerFournisseurSous = new QAction(tr("Enregistrer lisf fournisseurs sous"));
//    QAction * actionEnregistrerClientSous = new QAction(tr("Enregistrer lisf client sous"));
//    m_menuFichier->setTitle(tr("Fichier"));
//    m_menuFichier->addAction(actionEnregistrerFournisseurSous);
//    m_menuFichier->addAction(actionEnregistrerClientSous);

//    m_menuBarAnnuaire->addMenu(m_menuFichier);
    m_menuBarAnnuaire->addMenu(m_menuViderListe);

    // GroupBox Nouveau ------------------------------------------------------------
    m_groupBoxNouveau->setTitle(tr("Nouveau"));
    m_groupBoxNouveau->setLayout(m_gridLayoutNouv);

    m_formLayoutNouv->addRow(tr("Catégorie"),m_comboBoxCat);

    QStringList listCat;
    listCat << "" << tr("Fournisseur") << tr("Client");
    m_comboBoxCat->addItems(listCat);                           // peupler le combobox avec la liste des cat
    m_formLayoutNouv->addRow(tr("Code"),m_labelCodeCat);
    m_formLayoutNouv->addRow(tr("Type de société"),m_comboBoxType);
    QStringList typeSociete;
    typeSociete << "" << tr("SARL") << tr("EURL") << tr("SELARL") << tr("SA") << tr("SAS")<<tr("SASU") <<tr("SNC") << tr("SCP") << tr("SCOP ") << tr("SCIC") << tr("Entreprie Individuelle");
    m_comboBoxType->addItems(typeSociete);
    m_formLayoutNouv->addRow(tr("Raison sociale"),m_lineEditeRaisonSoc);
    m_formLayoutNouv->addRow(tr("Site internet"),m_lineEditeSiteInternet);
    m_formLayoutNouv->addRow(tr("Observation"),m_textEditObservation);
    m_textEditObservation->setFixedHeight(50);

    m_formLayoutNouv->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);      // Definir la taille du combobox en fonction de la largeur du text le plus long dans la liste du combobox
    // GroupBox Contact ------------------------------------------------------------
    m_groupBoxContact->setTitle(tr("Contact"));
    m_groupBoxContact->setLayout(m_formLayoutContact);

    m_formLayoutContact->addRow(tr("Civilité"),m_comboBoxCivilite);
    m_formLayoutContact->addRow(tr("Nom"),m_lineEditeNomContact);
    m_formLayoutContact->addRow(tr("Prénoms"),m_lineEditePrenomContact);
    m_formLayoutContact->addRow(tr("Adresse"),m_lineEditeAdresseContact);
    m_formLayoutContact->addRow(tr("Tél 1"),m_lineEditeTel1Contact);
    m_formLayoutContact->addRow(tr("Tél 2"),m_lineEditeTel2Contact);
    m_formLayoutContact->addRow(tr("Adresse E-mail"),m_lineEditeAdresseEmailContact);
    m_formLayoutContact->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    m_hboxLayoutBoutton->addWidget(m_pushButtonValider);
    m_hboxLayoutBoutton->addWidget(m_pushButtonAnnuler);

    m_gridLayoutNouv->addLayout(m_formLayoutNouv,0,0,4,2);
    m_gridLayoutNouv->addWidget(m_groupBoxContact,5,0,3,2);
    m_gridLayoutNouv->addLayout(m_hboxLayoutBoutton,13,1,1,1);

    // GroupBox List Fournisseur ----------------------------------------------------
    m_groupBoxListFou->setTitle(tr("Fournisseur"));
    m_groupBoxListFou->setLayout(m_gridLayoutFou);
    m_gridLayoutFou->addWidget(m_tableViewFournisseur);
    load_list_TableView(m_tableViewFournisseur,"Table_Fournisseur");
    m_tableViewFournisseur->setSizeAdjustPolicy(QTableView::AdjustToContents);

    m_tableViewFournisseur->setContextMenuPolicy(Qt::CustomContextMenu);

    // Selectionner toute la ligne au lieu d'une seule cellule
    m_tableViewFournisseur->setSelectionBehavior(QAbstractItemView::SelectRows);

    // GroupBox list Clients --------------------------------------------------------
    m_groupBoxListClient->setTitle(tr("Client"));
    m_groupBoxListClient->setLayout(m_gridLayoutClient);
    m_gridLayoutClient->addWidget(m_tableViewClient);
    m_tableViewClient->setSizeAdjustPolicy(QTableView::AdjustToContents);
    load_list_TableView(m_tableViewClient,"Table_Client");
    m_tableViewClient->setContextMenuPolicy(Qt::CustomContextMenu);

    // Selectionner toute la ligne au lieu d'une seule cellule
    m_tableViewClient->setSelectionBehavior(QAbstractItemView::SelectRows);

    // GroupBox filtre --------------------------------------------------------------
    m_groupBoxFiltre->setLayout(m_gridLayoutFiltre);
    m_groupBoxFiltre->setTitle(tr("Filtre"));

    QStringList listFiltre;
    listFiltre <<""<< tr("Raison sociale") << tr("Nom Contact") << tr("Prénoms Contact");
    m_comboBoxFilter->addItems(listFiltre);
    m_comboBoxFilter->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    QStringList list_cat_Filter;
    list_cat_Filter << "" << tr("Fournisseurs") << tr("Client");
    m_comboBoxFilterCat->addItems(list_cat_Filter);
    m_comboBoxFilterCat->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    m_hboxLayoutFilterCB->addWidget(m_comboBoxFilterCat);
    m_hboxLayoutFilterCB->addWidget(m_comboBoxFilter);

    m_hboxLayoutFilterBt->addWidget(m_pushButtonRechercher);
    m_hboxLayoutFilterBt->addWidget(m_pushButtonEffacer);

    m_gridLayoutFiltre->addLayout(m_hboxLayoutFilterCB,0,0);
    m_gridLayoutFiltre->addWidget(m_lineEditeFiltre,1,0,1,1);
    m_gridLayoutFiltre->addLayout(m_hboxLayoutFilterBt,2,0,1,1);

    // Mise en forme generale -------------------------------------------------------
    m_gridLayoutPp->addWidget(m_menuBarAnnuaire,0,0,1,2,Qt::Alignment(Qt::AlignLeft));
    m_gridLayoutPp->addWidget(m_groupBoxNouveau,1,0,10,1,Qt::Alignment(Qt::AlignLeft));
    m_gridLayoutPp->addWidget(m_groupBoxListFou,0,3,20,3,Qt::Alignment(Qt::AlignLeft));
    m_gridLayoutPp->addWidget(m_groupBoxListClient,0,7,20,3,Qt::Alignment(Qt::AlignLeft));
    m_gridLayoutPp->addWidget(m_groupBoxFiltre,11,0,5,1);
    m_gridLayoutPp->setSpacing(3);
    this->setLayout(m_gridLayoutPp);


    //  FONCTIONS -------------------------------------------------------------------
    load_list_civilite();
    reinitialiser_filtre_cat();

    //  CONNECTION ------------------------------------------------------------------
    connect(m_comboBoxCat,SIGNAL(currentIndexChanged(int)),this,SLOT(catChange()));
    connect(m_pushButtonValider,SIGNAL(clicked(bool)),this,SLOT(click_bt_valider()));
    connect(actionViderListeFour,SIGNAL(triggered(bool)),this,SLOT(vider_list_Four()));
    connect(actionViderListeClient,SIGNAL(triggered(bool)),this,SLOT(vider_list_Client()));
    connect(m_pushButtonAnnuler,SIGNAL(clicked(bool)),this,SLOT(click_bt_annuler()));
    connect(m_comboBoxFilterCat,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_Filter_Cat_Index_Change()));
    connect(m_comboBoxFilter,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_Filter_Index_Change()));
    connect(m_pushButtonEffacer,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_effacer_filtre()));
    connect(m_pushButtonRechercher,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_rechercher_filtre()));
    connect(m_tableViewFournisseur,SIGNAL(customContextMenuRequested(QPoint)),SLOT(contextMenuFournisseur(QPoint)));  //permet d'ouvrir le menu contextuel par click droit sur une céllule
    connect(m_tableViewClient,SIGNAL(customContextMenuRequested(QPoint)),SLOT(contextMenuClient(QPoint)));
    connect(m_dialogboxModifierTiers->m_pushButton_dialogBox_Modif_Valider,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_valider_dialogBoxModif_Fournisseur()));
    connect(m_dialogBox_Avertissement_suppr->m_pushbutton_Ok,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_valider_dialogBoxSupp_Fournisseur()));
    connect(m_dialogBox_Avertissement_suppr->m_pushbutton_Ok,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_valider_dialogBoxSupp_Client()));
}


//  FONCTION ------------------------------------------------------------------------
void QwidgesFournisseurClient::load_list_TableView(QTableView * TableView , const char * nomTable)
{
    /*
     * Permet d'afficher la liste des fournisseurs et client dans un tableview
     * TableView : affiche la liste dans nomTable qui se trouve dans la base de donéée
     */
    QSqlQuery qry;
    QString nom_table = QString(nomTable);
    QSqlQueryModel *model =  new QSqlQueryModel;

    qry.prepare("SELECT Code,Raison_sociale,civilite_contact,Nom_contact,Prenoms_contact,tel_1,Adresse_email FROM '"+nom_table+"' ");
    if (!qry.exec()){
        qDebug()<<tr("Erreur exection du qry dans la fonction load_list_Fournisseur");
    }else {

        model->setQuery(qry);
        TableView->setModel(model);
        TableView->verticalHeader()->hide();    // Permet de cacher le verticalHeader du tableView, ne pas oblier d'inclure la bibliotheque QHeaderView

    }

    // Renomer tout les en têtes du tableau
    model->setHeaderData(0,Qt::Horizontal,tr("Code"),Qt::DisplayRole);
    model->setHeaderData(1,Qt::Horizontal,tr("Raison sociale"),Qt::DisplayRole);
    model->setHeaderData(2,Qt::Horizontal,tr("Civilité Contact"),Qt::DisplayRole);
    model->setHeaderData(3,Qt::Horizontal,tr("Nom Contact"),Qt::DisplayRole);
    model->setHeaderData(4,Qt::Horizontal,tr("Prenoms Contact"),Qt::DisplayRole);
    model->setHeaderData(5,Qt::Horizontal,tr("Tel I"),Qt::DisplayRole);
    model->setHeaderData(6,Qt::Horizontal,tr("Adresse Email"),Qt::DisplayRole);

    // Permet de cacher les colonnes dans le tableView
//    TableView->hideColumn(0);
//    TableView->hideColumn(2);
//    TableView->hideColumn(4);
//    TableView->hideColumn(5);
//    TableView->hideColumn(6);
//    TableView->hideColumn(9);
//    TableView->hideColumn(11);

    /*
     * Permet de faire le formatage du header de la tableview
     * Remarque: le setStyleSheet utilise le language css pour
     * faire le formatage de la selection
     */
    TableView->setStyleSheet("QHeaderView::section {background-color:#A52A2A ; color: white;  }");
}

void QwidgesFournisseurClient::creeCode(const char *Nom_Table)
{
    /*
     * Permet de créer le code Fournisseur ou Client en fonction du choix
     * sur le combobox catégorie. le parametre Nom_Table permet de recuperer
     * la table corréspondant dans la base de donée.
     */
    QSqlQuery qry;
    QString NomTable = QString(Nom_Table);
    qry.prepare("SELECT count(*) FROM '"+NomTable+"' ");    // Compter le nombre de ligne dans la Table de la base de donnée
    if (!qry.exec()){
        qDebug()<<tr("Erreur execution qry dans la fonction creeCode");
    }else{
        while (qry.next()) {
            if (qry.value(0).toInt() == 0){                 // si la table est vide
                if (m_comboBoxCat->currentIndex() == 0){
                    m_labelCodeCat->setText("");            // on affect la valeur "" au code cat
                }else if (m_comboBoxCat->currentIndex() == 1) {
                    m_labelCodeCat->setText("FO_01");       // si non, on affect la valeur "FO_01" si le catégorie est fournisseur
                }else {
                    m_labelCodeCat->setText("CL_01");       // si non, on affect la valeur "CL_01" si le catégorie est Client
                }
            }else {
                QSqlQuery qrycount;
                int numNouveau;
                qrycount.prepare("SELECT MAX (id) FROM '"+NomTable+"' ");   // On se place à la dernière ligne de la colonne id de la table pour recupérer le numeros de l'id
                if (!qrycount.exec()){
                    qDebug()<<"Erreur qryCount"<<qrycount.lastError();
                }else {

                    QString CodeFournisseur = "FO";
                    QString codeClient = "CL";

                    while (qrycount.next()) {
                        numNouveau = qrycount.value(0).toInt() +1;          // On ajoute 1 pour créer le code de la nouvelle entrée
                    }
                    if(m_comboBoxCat->currentIndex() == 0){

                    }else if (m_comboBoxCat->currentIndex() == 1) {
                        if (numNouveau > 1 && numNouveau < 10){                                 // si le numeros de l'id est entre 1 et 10
                            CodeFournisseur.append("_0").append(QString::number(numNouveau));   // on ajoute "0"
                        }else {
                            CodeFournisseur.append("_").append(QString::number(numNouveau));    // si non on ajoute directement "_" au prefix puis on ajoute le numeros de l'id+1
                        }m_labelCodeCat->setText(CodeFournisseur);                              // on affiche le resultat sur le lable

                    }else {
                        if (numNouveau > 1 && numNouveau <10 ){
                            codeClient.append("_0").append(QString::number(numNouveau));
                        }else {
                            codeClient.append("_").append(QString::number(numNouveau));
                        }
                        m_labelCodeCat->setText(codeClient);
                    }
                }
            }
        }
    }
}

void QwidgesFournisseurClient::load_list_civilite()
{
    /*
     * Permet de lire la liste des civilité dans la base de donnée et
     * de l'insérer dans le combobox m_comboBoxCivilite
     */
    QSqlQuery qry;
    QString civilite;
    QStringList listCivilite;
    qry.prepare("SELECT Designation FROM Table_Civilite");
    if (!qry.exec()){
        qDebug()<<tr("Erreur executin du qry dans la fonction load_list_civilite");
    }else {
        while (qry.next()) {
            civilite = qry.value(0).toString();
            listCivilite.append(civilite);
            listCivilite.removeDuplicates();
        }
        m_comboBoxCivilite->addItem("");
        m_comboBoxCivilite->addItems(listCivilite);
    }
}

void QwidgesFournisseurClient::reinitialiser_saisie()
{
    /*
     * Permet de reinitialiser tout les élement du formulaire de saisie
     * de nouvelle entrée
     */
    m_comboBoxCat->setCurrentIndex(0);
    m_comboBoxType->setCurrentIndex(0);
    m_lineEditeRaisonSoc->clear();
    m_lineEditeSiteInternet->clear();
    m_textEditObservation->clear();
    m_comboBoxCivilite->setCurrentIndex(0);
    m_lineEditeNomContact->clear();
    m_lineEditePrenomContact->clear();
    m_lineEditeAdresseContact->clear();
    m_lineEditeTel1Contact->clear();
    m_lineEditeTel2Contact->clear();
    m_lineEditeAdresseEmailContact->clear();
}

void QwidgesFournisseurClient::vider_Table(QTableView *table_view, const char *NomTable)
{
    /*
     * permet de vider la table dans la base de donnée ainsi que la table qui la represent
     * dans l'application
     */

    // au click sur l'action supprimer, on crée une boite de dialog pour avertir
    // l'utilisateur qu'il est en train de vider la table
    QMessageBox *avertissement = new QMessageBox;
    avertissement->setIcon(QMessageBox::Warning);
    if (table_view == m_tableViewFournisseur){
        // crée le msg en fonction du table choisit
        avertissement->setText(tr("Attention, vos étés sur le point de vider la liste des Fournisseurs"));
    }else if (table_view == m_tableViewClient) {
        avertissement->setText(tr("Attention, vos étés sur le point de vider la liste des Clients"));
    }
    avertissement->setStandardButtons(QMessageBox::Ok);     // on crée les boutons pour valider ou
    avertissement->addButton(QMessageBox::No);              // annuler l'action
    if (avertissement->exec() == QMessageBox::Ok){          // si l'utilisateur valide l'action
        QSqlQuery qryDelete;
        QSqlQuery qryUpdtade;
        QString Nom_Table = QString(NomTable);
        qryDelete.prepare("DELETE FROM '"+Nom_Table+"' ");  // on supprime tous les donnée dans la table
        qryDelete.exec();
        qryUpdtade.prepare("UPDATE SQLITE_SEQUENCE SET SEQ=0 WHERE NAME= '"+Nom_Table+"' ");    // et on reinitialise l'auto incrémentation
        qryUpdtade.exec();
        load_list_TableView(table_view,NomTable);          // Puis, on rafraichis la table
        creeCode(NomTable);
    }else {
        avertissement->close();                             // si l'utilisateur decide d'annuler l'action, en clicant sur le boutton annuler, la boite de dialogue se ferm
    }
}

void QwidgesFournisseurClient::valider_entree()
{
    /*
     * Permet d'enregistrer les valeure saisie vers la base de donnée
     * des message box apparaissent si une valeurs obligatoire n'est pas remplit
     * Apres validation, les donnée dans les listes sont actualiser automatiquement
     */
    QString Code, type , Raison_sociale , site_internet, Observation, civilite_contact, Nom_contact, Prenoms_contact, Adress_contact, tel_1, tel_2, Adresse_email;

    type = m_comboBoxType->currentText();
    Raison_sociale = m_lineEditeRaisonSoc->text();
    site_internet = m_lineEditeSiteInternet->text();
    Observation = m_textEditObservation->toPlainText();
    civilite_contact = m_comboBoxCivilite->currentText();
    Nom_contact = m_lineEditeNomContact->text();
    Prenoms_contact = m_lineEditePrenomContact->text();
    Adress_contact = m_lineEditeAdresseContact->text();
    tel_1 = m_lineEditeTel1Contact->text();
    tel_2 = m_lineEditeTel2Contact->text();
    Adresse_email = m_lineEditeAdresseEmailContact->text();

    if(m_comboBoxCat->currentIndex() == 0 && m_comboBoxType->currentIndex() == 0) {
        // ouverture du messagebox si la catégorie est vide
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Information);
        msgbox.setText(tr("Veuillez choisir une catégorie"));
        msgbox.exec();
    }else if (m_comboBoxType->currentIndex() == 0) {
        // ouverture du messagebox si la type est vide
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Information);
        msgbox.setText(tr("Veuillez choisir une type"));
        msgbox.exec();
    }else if (m_lineEditeRaisonSoc->text() == 0) {
        // ouverture du messagebox si raison sociale est vide
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Information);
        msgbox.setText(tr("Veuillez choisir une raison sociale"));
        msgbox.exec();
    }else if (m_comboBoxCivilite->currentIndex() == 0) {
        // ouverture du messagebox si civilité est vide
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Information);
        msgbox.setText(tr("Veuillez choisir une civilité"));
        msgbox.exec();
    }else if (m_lineEditeNomContact->text() == 0) {
        // ouverture du messagebox si Nom de contact est vide
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Information);
        msgbox.setText(tr("Veuillez choisir une Nom de contact"));
        msgbox.exec();
    }else {

        if(m_comboBoxCat->currentIndex() == 1){
            /*
             * si tous le valeur obligatoires sont remplit et le catégorie est Fournisseur;
             * alors on INSERT les données dans la Table_Fournisseur
             */

            QSqlQuery qry;
            Code = m_labelCodeCat->text();

            qry.prepare("INSERT INTO Table_Fournisseur (  Code, type , Raison_sociale , site_internet, Observation, civilite_contact, Nom_contact, Prenoms_contact, Adress_contact, tel_1, tel_2, Adresse_email ) VALUES ( :Code, :type , :Raison_sociale , :site_internet, :Observation, :civilite_contact, :Nom_contact, :Prenoms_contact, :Adress_contact, :tel_1, :tel_2, :Adresse_email)");
            qry.exec();

            qry.bindValue(":Code",Code);
            qry.bindValue(":type",type);
            qry.bindValue(":Raison_sociale",Raison_sociale);
            qry.bindValue(":site_internet",site_internet);
            qry.bindValue(":Observation",Observation);
            qry.bindValue(":civilite_contact",civilite_contact);
            qry.bindValue(":Nom_contact",Nom_contact);
            qry.bindValue(":Prenoms_contact",Prenoms_contact);
            qry.bindValue(":Adress_contact",Adress_contact);
            qry.bindValue(":tel_1",tel_1);
            qry.bindValue(":tel_2",tel_2);
            qry.bindValue(":Adresse_email",Adresse_email);

            if (!qry.exec()){
                qDebug()<<tr("Erreur execution qry valider insert fournisseur")<<qry.lastError();
            }else {
                /*
                 * Apres insertion des valeurs dans la base de donnée; on actualise
                 * la m_tableViewFournisseur avec les nouvelles donnée dans Table_Fournisseur.
                 * et on efface tout les valeurs dans la groupeBox Nouveau
                 */
                load_list_TableView(m_tableViewFournisseur,"Table_Fournisseur");
                reinitialiser_saisie();
            }

        }else {

            QSqlQuery qry;
            Code = m_labelCodeCat->text();
            qDebug()<<m_labelCodeCat->text();

            /*
             * Apres insertion des valeurs dans la base de donnée; on actualise
             * la m_tableViewClient avec les nouvelles donnée dans Table_Client.
             * et on efface tout les valeurs dans la groupeBox Nouveau
             */

            qry.prepare("INSERT INTO Table_Client (Code, type , Raison_sociale , site_internet, Observation, civilite_contact, Nom_contact, Prenoms_contact, Adress_contact, tel_1, tel_2, Adresse_email ) VALUES ( :Code, :type , :Raison_sociale , :site_internet, :Observation, :civilite_contact, :Nom_contact, :Prenoms_contact, :Adress_contact, :tel_1, :tel_2, :Adresse_email)");
            qry.exec();

            qry.bindValue(":Code",Code);
            qry.bindValue(":type",type);
            qry.bindValue(":Raison_sociale",Raison_sociale);
            qry.bindValue(":site_internet",site_internet);
            qry.bindValue(":Observation",Observation);
            qry.bindValue(":civilite_contact",civilite_contact);
            qry.bindValue(":Nom_contact",Nom_contact);
            qry.bindValue(":Prenoms_contact",Prenoms_contact);
            qry.bindValue(":Adress_contact",Adress_contact);
            qry.bindValue(":tel_1",tel_1);
            qry.bindValue(":tel_2",tel_2);
            qry.bindValue(":Adresse_email",Adresse_email);


            if (!qry.exec()){
                qDebug()<<tr("Erreur execution qry valider insert client")<<qry.lastError();
            }else {
                load_list_TableView(m_tableViewClient,"Table_Client");
                reinitialiser_saisie();
            }
        }

    }
}

void QwidgesFournisseurClient::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        valider_entree();
    }
}

void QwidgesFournisseurClient::reinitialiser_filtre_cat()
{
    /*
     * Permet de choisir que categorie on veut filtrer "Fournisseur" ou "Client"
     * si auccun categorie n'est choisit, le m_comboBoxFilter reste verouiller
     * ainsi que m_lineEditeFiltre
     */

    if (m_comboBoxFilterCat->currentIndex() == 0){
        m_comboBoxFilter->setCurrentIndex(0);
        m_comboBoxFilter->setDisabled(true);
        m_lineEditeFiltre->clear();
        m_lineEditeFiltre->setEnabled(false);

    }else if (m_comboBoxFilterCat->currentIndex() == 1) {
        m_comboBoxFilter->setEnabled(true);
        m_comboBoxFilter->setCurrentIndex(0);
        m_lineEditeFiltre->clear();
        qDebug()<<"Filtre Fournisseur";

    }else if (m_comboBoxFilterCat->currentIndex() == 2) {
        m_comboBoxFilter->setEnabled(true);
        m_comboBoxFilter->setCurrentIndex(0);
        m_lineEditeFiltre->clear();
        qDebug()<<"Filtre Client";
    }
}

void QwidgesFournisseurClient::completer_filter(const char *NomTable , const char *NomColonne)
{
    /*
     * Permet de filtrer la liste dans le m_lineEditeFiltre en fonction du categorie et
     * nom de colonne dans les tables fournisseurs et client de la base de donnée
     */

    QStringList listCompleter;
    QSqlQuery qry;
    QString Nom_table = QString(NomTable);
    QString Nom_Colonne = QString(NomColonne);
    qry.prepare("SELECT "+Nom_Colonne+" FROM '"+Nom_table+"' ");
    if (!qry.exec()){
        qDebug()<<tr("Erreur execution qry fonction completer_filter")<<qry.lastError();
    }else{
        while (qry.next()) {
            QString completerText = qry.value(0).toString();
            qDebug()<< qry.value(0).toString() << "qry value";
            listCompleter.append(completerText);
            listCompleter.removeDuplicates();
        }
    }

    /*
     *  permet de filtrer la liste des nom de produit dans m_lineEditeFiltre
     *  en fonction des caractères saisie dans ce dernier
     */
    QCompleter *mycompleter = new QCompleter(listCompleter);
    m_lineEditeFiltre->setCompleter(mycompleter);
    m_lineEditeFiltre->setFocus();
    mycompleter->setCompletionMode(QCompleter::PopupCompletion);
    mycompleter->setModelSorting(QCompleter::UnsortedModel);
    mycompleter->setFilterMode(Qt::MatchStartsWith);
    mycompleter->setCaseSensitivity(Qt::CaseInsensitive);
}

void QwidgesFournisseurClient::contextMenu_TableView(const char * Type_de_tiers,QTableView *Nom_tableView, const char * nom_table_bd, QPoint position)
{
    /*
     * creation du context menu d'un tableview
     */
    QModelIndex index = Nom_tableView->indexAt(position);
    QMenu * menu = new QMenu(Nom_tableView);
    QString categorie = QString(Type_de_tiers);
    QVector <QString> data_to_table;

    // Création des action dans le menux contextuel
    QAction * actionCopier = new QAction(tr("Copier"),Nom_tableView);
    QAction * actionAfficherDetail = new QAction(tr("Afficher details"),Nom_tableView);
    QAction * actionModif = new QAction(tr("Modifier"),Nom_tableView);
    QAction * actionSuppr = new QAction(tr("Supprimer"),Nom_tableView);
    QAction * actionEnregistrerSous = new QAction(tr("Enregistrer sous"),Nom_tableView);

    // Ajout des actions dans le menu
    menu->addAction(actionCopier);
    menu->addAction(actionAfficherDetail);
    menu->addAction(actionModif);
    menu->addAction(actionSuppr);
    menu->addAction(actionEnregistrerSous);

    // Afficher le menu dans le tableView sur la position du souris
    menu->popup(Nom_tableView->viewport()->mapToGlobal(position));

    // Se placer au colonne 1 du selection en cours
    QString code_selection = Nom_tableView->model()->index(index.row(),0).data().toString();
    QSqlQuery qry;
    QString Nom_table_bd = QString(nom_table_bd);

    qry.prepare("SELECT * FROM "+Nom_table_bd+" WHERE code = '"+code_selection+"' ");
    qry.exec();
    if (!qry.exec()){
        qDebug()<<tr("Erreur execution qry dans la fonction contextMenu_TableView")<<qry.lastError();
    }else {
        // Recuperer chaque element du tableau dans la base de donnée et l'envoyer dans le Qvector data

        while (qry.next()) {
            // i<13 "13 le nombre de colonne dans le Table_Fournisseur/Table_Client
            for (int i=1 ; i<13 ; ++i){
                QString value = qry.value(i).toString();
                data_to_table.append(value);
            }
        }
    }
    // Tester si le vecteur n'est pas vide
    if (data_to_table.size() != 0){
        // Remplir les infos du m_dialogboxModifierTiers avec les donnée du QVector data
        m_dialogboxModifierTiers->m_label_dialogBox_Modif_Categorie->setText(categorie);
        m_dialogboxModifierTiers->m_label_dialogBox_Modif_Code->setText(code_selection);
        m_dialogboxModifierTiers->m_comboBox_dialogBox_Modif_Type_societe->setCurrentText(data_to_table[1]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_RaisonSociale->setText(data_to_table[2]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_siteWeb->setText(data_to_table[3]);
        m_dialogboxModifierTiers->m_textEdit_dialogBox_Modif_Obs->setText(data_to_table[4]);
        m_dialogboxModifierTiers->m_comboBox_dialogBox_Civilite->setCurrentText(data_to_table[5]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_NomContact->setText(data_to_table[6]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_PrenomsContact->setText(data_to_table[7]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_Adresses->setText(data_to_table[8]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_Tel1->setText(data_to_table[9]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_Tel2->setText(data_to_table[10]);
        m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_AdresseMail->setText(data_to_table[11]);

        // Remplir le textEdit du dialogBox afficher details
        QString global_text;
        global_text.append(tr("Categorie : ")).append("\t \t").append(categorie).append("\n");
        global_text.append(tr("Code : ")).append("\t \t").append(code_selection).append("\n");
        global_text.append(tr("Type de société : ")).append("\t").append(data_to_table[1]).append("\n");
        global_text.append(tr("Raison sociale : ")).append("\t \t").append(data_to_table[2]).append("\n");
        global_text.append(tr("Site Web : ")).append("\t \t").append(data_to_table[3]).append("\n");
        global_text.append(tr("Observation : ")).append("\t \t").append(data_to_table[4]).append("\n \n");
        global_text.append(tr("Civilité du conctact : ")).append("\t").append(data_to_table[5]).append("\n");
        global_text.append(tr("Nom du contact : ")).append("\t").append(data_to_table[6]).append("\n");
        global_text.append(tr("Prenoms du contact : ")).append("\t").append(data_to_table[7]).append("\n");
        global_text.append(tr("Adresse de la société :")).append("\t").append(data_to_table[8]).append("\n");
        global_text.append(tr("Numéros telephone 1 : ")).append("\t").append(data_to_table[9]).append("\n");
        global_text.append(tr("Numéros telephone 2 : ")).append("\t").append(data_to_table[10]).append("\n");
        global_text.append(tr("Adresse E-mail : ")).append("\t").append(data_to_table[11]).append("\n");
        m_dialogboxDetail->m_textEdit_dialogBox_detail->setText(global_text);

        // Creer titre de la dialogbox_details
        m_dialogboxDetail->setWindowTitle(tr("Details").append(" ").append(categorie).append(" : ").append(code_selection));
        // Desactiver le retour à la ligne automatique du textEdit
        m_dialogboxDetail->m_textEdit_dialogBox_detail->setLineWrapMode(QTextEdit::NoWrap);
        // Mije en page des textes dans le QTextEdit
        m_dialogboxDetail->m_textEdit_dialogBox_detail->setAlignment(Qt::AlignJustify);
        // Definir le titre du dialogBox
        QString titre_dialogBox_Modifier_tiers;
        titre_dialogBox_Modifier_tiers.append("Modification ").append(categorie).append(" ").append(code_selection);
        m_dialogboxModifierTiers->setWindowTitle(titre_dialogBox_Modifier_tiers);

        // Creation du messageBox d'avertissement
        QString titre;
        titre = tr("Supprimer : ").append(code_selection);
        m_dialogBox_Avertissement_suppr->setWindowTitle(titre);
        QString text_Message = tr("Attention vous êtes sur le point de supprimer définitivement : ");
        text_Message.append(code_selection).append(" dans la liste des ").append(categorie);
        m_dialogBox_Avertissement_suppr->m_lablel_message->setText(text_Message);
    }


    // CONNECTIONS -----------------------------------------------------------------------
    connect(actionCopier,SIGNAL(triggered(bool)),this,SLOT(copy_selectedRow_tableview_Fournisseur()));
    connect(actionModif,SIGNAL(triggered(bool)),this,SLOT(ouvrir_dialogBox_Modifier_Tiers()));
    connect(actionAfficherDetail,SIGNAL(triggered(bool)),this,SLOT(on_click_action_afficher_detail()));    
    connect(actionSuppr,SIGNAL(triggered(bool)),this,SLOT(on_click_action_supprimer()));
    connect(actionEnregistrerSous,SIGNAL(triggered(bool)),this,SLOT(on_click_action_enregistrerSous()));
}

void QwidgesFournisseurClient::copy_selected_row_tableview(QTableView *tableView)
{
    QItemSelectionModel * selection = tableView->selectionModel();
    QString text_to_clipboard;

    for (int i = 0 ; i <= tableView->model()->columnCount()-2 ; ++i){

        // ("\t") permet d'incérer une tablilation apres chaque saisie; ce qui permet de créer un collage en tablea dans les logicieles comme excel
        text_to_clipboard.append(selection->selectedRows(i).value(0).data().toString().append("\t"));

//            qDebug()<<selection->selectedRows(i).value(0).data().toString();
    }

    // envoyer les valeurs dans le clipboard
    QApplication::clipboard()->setText(text_to_clipboard);
}

void QwidgesFournisseurClient::valider_Modif_dialogBox_ModifTiers(QTableView * nom_table , const char * nomTable)
{
    /*
     * Envoyer les données saisies dans le dialogBox_Modifier vers la base de donnée.
     */
    QSqlQuery qry;
    QString Code,type,Raison_sociale,site_internet,Observation,civilite_contact,Nom_contact,Prenoms_contact,Adress_contact,tel_1,tel_2,Adresse_email;
    Code = m_dialogboxModifierTiers->m_label_dialogBox_Modif_Code->text();
    type = m_dialogboxModifierTiers->m_comboBox_dialogBox_Modif_Type_societe->currentText();
    Raison_sociale = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_RaisonSociale->text();
    site_internet = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_siteWeb->text();
    Observation = m_dialogboxModifierTiers->m_textEdit_dialogBox_Modif_Obs->toPlainText();
    civilite_contact = m_dialogboxModifierTiers->m_comboBox_dialogBox_Civilite->currentText();
    Nom_contact = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_NomContact->text();
    Prenoms_contact = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_PrenomsContact->text();
    Adress_contact = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_Adresses->text();
    tel_1 = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_Tel1->text();
    tel_2 = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_Tel2->text();
    Adresse_email = m_dialogboxModifierTiers->m_lineEdit_dialogBox_Modif_AdresseMail->text();
    QString nom_table_toString = QString(nomTable);

    qry.prepare("UPDATE "+nom_table_toString+" SET  type = '"+type+"',Raison_sociale = '"+Raison_sociale+"',site_internet = '"+site_internet+"',Observation = '"+Observation+"', civilite_contact = '"+civilite_contact+"',Nom_contact = '"+Nom_contact+"', Prenoms_contact = '"+Prenoms_contact+"', Adress_contact = '"+Adress_contact+"', tel_1 = '"+tel_1+"', tel_2 = '"+tel_2+"',Adresse_email = '"+Adresse_email+"' WHERE Code = '"+Code+"' ");
    qry.exec();
    if (!qry.exec()){
        qDebug()<<tr("Erreur exection qry fonction valider_Modif_dialogBox_ModifTiers ")<<qry.lastError();
    }else {
        load_list_TableView(nom_table,nomTable);
        reinitialiser_saisie();
    }
}

void QwidgesFournisseurClient::supprimer_ligne_tableView(QTableView *Nom_tableView, const char *nomTableBd)
{
    /*
     * Supprimer le produit selectionner dans le tableView dans le base de données
     * puis actualiser la liste dans le tableView
     */
    QSqlQuery qry_delete ;
    QString nomTableBd_to_string = QString(nomTableBd);
    QString code;
    // recuperer code depuis le titre du dialogBox d'avertissement
    code = m_dialogBox_Avertissement_suppr->windowTitle().remove(0,12);

    qry_delete.prepare("DELETE FROM "+nomTableBd_to_string+" WHERE code = '"+code+"' ");
    qry_delete.exec();
    if (!qry_delete.exec()){
        qDebug()<<tr("Erreur execution qry_delete fonction supprimer_ligne_tableView")<<qry_delete.lastError();
    }else {
        load_list_TableView(Nom_tableView,nomTableBd);
        reinitialiser_saisie();
        reinitialiser_filtre_cat();
    }
}

void QwidgesFournisseurClient::enregistrer_tableau_sous(QTableView * Nom_tableview)
{
    /*
     * Permet d'enregistrer le tableau sous le format csv ou pdf
     * par le click sur l'action Enregistrer sous du contextMenu
     */

    // Création de l'entete du tableau
    QVector<QString> data_from_cells;
    data_from_cells << tr("Code") << tr("Raison sociale") << tr("Civilité contact") << tr("Nom contact")<< tr("Prènoms Contact")<< tr("Telephone I") << tr("Address_Email");
    QString text_data;

    for (int i=0 ; i<data_from_cells.size(); ++i){
        text_data.append(data_from_cells[i]);
        text_data.append(" ; ");
    }text_data.append("\n");


    // Création du contenu
    // Recupperer la taille des lignes
    for (int i=0; i< Nom_tableview->model()->rowCount(); ++i){
        // Recuperer la taille des colonnes
        for (int j=0 ; j<Nom_tableview->model()->columnCount(); ++j){
            QModelIndex index = Nom_tableview->model()->index(i,j);
            text_data += index.data(2).toString();
            text_data += " ; ";
        }text_data += "\n";
    }

    // Ouverture du dialogBox d'enregistrenement
    QString extension_choisit;
    QString nom_du_fichier = QFileDialog::getSaveFileName(this, tr("Enregistrer sous"),QString() , "tout les Fichier(*.*) ;; CSV(*.csv) ;; PDF(*.pdf)",&extension_choisit);

    // Creation du fichier csv si le choit de l'extension est csv
    if (extension_choisit == "CSV(*.csv)"){
        qDebug()<<"Enregistrer sous csv";
        QFile fichier(nom_du_fichier);
        if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate)){
            QTextStream out(&fichier);
            out << text_data;
            fichier.close();

            // Lancement automatique de l'application excel pour la lecture du fichier
            QProcess * process = new QProcess(this);
            QString programme = "C:/Program Files (x86)/Microsoft Office/root/Office16/EXCEL.EXE";
            QString file_to_open = nom_du_fichier;
            process->start(programme,QStringList()<<file_to_open);
        }

    // création du fichier pdf au choix type d'extension .pdf
    // Basée sur la création d'une page html puis impression en pdf
    }else if (extension_choisit == "PDF(*.pdf)") {
        qDebug()<<"Enregistrer sous pdf";
        QString date_export = QDate::currentDate().toString("dd/MM/yyyy");

        // Configuration de l'imprimante pour créer le fichier pdf
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOrientation(QPrinter::Portrait);
        printer.setPageSize(QPrinter::A4);
        printer.setOutputFileName(nom_du_fichier);

        // Creation du contenu du fichier pdf
        QTextDocument doc;
        QString * doc_text = new QString;

        doc_text->append("<style>");
//        doc_text->append("table{background-color : gray ; font-size: 10}");
        doc_text->append("table,th,tr{padding : 3px;}");
        doc_text->append("table,tr,td{ padding : 3px ;color:black}");
        doc_text->append("th{ background-color:#A52A2A ; color:white ; white-space: nowarp }");
        doc_text->append("</style>");

        doc_text->append("<body>");
        doc_text->append("<table>");

        // Creation du titre de la page
        if (Nom_tableview == m_tableViewFournisseur){
            doc_text->append("<caption>Liste des Fournisseurs "+date_export+" : </caption>");
        }else if (Nom_tableview == m_tableViewClient) {
            doc_text->append("<caption>Liste des Client "+date_export+" : </caption>");
        }
        doc_text->append("<p></p>");

        doc_text->append("<tr>");

        // Creation de l'en tete du tableau
        for (int i = 0 ; i < Nom_tableview->model()->columnCount() ; ++i ){
            doc_text->append("<th>");
            QString tableView_headers = Nom_tableview->model()->headerData(i,Qt::Horizontal).toString();
            doc_text->append(tableView_headers).append("</th>");
        }

        doc_text->append("</tr>");

        // Creation du contenu de chaque cellues du tableau
        QModelIndex index;
        for (int i = 0 ; i < Nom_tableview->model()->rowCount(); ++i ){
            doc_text->append("<tr style=\" background-color : #F5F5F5 ; font-size : 3 ;\" >");
            for (int j = 0 ; j < Nom_tableview->model()->columnCount() ; ++j){
                doc_text->append("<td>");
                index = Nom_tableview->model()->index(i,j);
                doc_text->append(index.data(2).toString());
            }
            doc_text->append("</tr>");
        }
        doc_text->append("</table>");
        doc_text->append("</body>");

//        qDebug()<<*doc_text;

        doc.setHtml(*doc_text);
        doc.setPageSize(printer.paperRect().size());
        doc.print(&printer);
    }
}


//  SLOT ---------------------------------------------------------------------------

void QwidgesFournisseurClient::catChange()
{
    /*
     * permet d'afficher le code en fonction du choix sur le combobox Catégorie
     * il faut inscrire le nom de la table de la base de donnée pour charger la
     * le contenue.
     */
    if (m_comboBoxCat->currentIndex() == 0){
        m_labelCodeCat->setText("");
    }else if (m_comboBoxCat->currentIndex() == 1) {
        creeCode("Table_Fournisseur");
    }else {
        creeCode("Table_Client");
    }
}

void QwidgesFournisseurClient::click_bt_valider()
{
    /*
     * permet de valider les saisie par le click sur le boutton
     * Valider
     */
    valider_entree();
}

void QwidgesFournisseurClient::vider_list_Four()
{
    /*
     * Permet de vider la table fournisseurs par le click sur l'action
     * vider la liste : Fournisseur
     */
    vider_Table(m_tableViewFournisseur,"Table_Fournisseur");
    load_list_TableView(m_tableViewFournisseur,"Table_Fournisseur");
}

void QwidgesFournisseurClient::vider_list_Client()
{
    /*
     * Permet de vider la table client par le click sur l'action
     * vider la liste : client
     */
    vider_Table(m_tableViewClient,"Table_Client");
    load_list_TableView(m_tableViewClient,"Table_Client");
}

void QwidgesFournisseurClient::click_bt_annuler()
{
    reinitialiser_saisie();
}

void QwidgesFournisseurClient::on_comboBox_Filter_Cat_Index_Change()
{
    /*
     * Permet de déverouiller le combobox filtre en choisissant l'une des valeurs
     * client ou Fournisseur dans le combobox m_comboBoxFilterCat
     */
    reinitialiser_filtre_cat();
}

void QwidgesFournisseurClient::on_comboBox_Filter_Index_Change()
{
    /*
     * Permet de devérouiller m_lineEditeFiltre,
     * à chaque changement de valeur d'index dans m_comboBoxFilter;
     * le contenue de m_lineEditeFiltre est reinitialiser
     */
    if (m_comboBoxFilter->currentIndex() == 0){

        m_lineEditeFiltre->setEnabled(false);
        m_lineEditeFiltre->clear();
        load_list_TableView(m_tableViewFournisseur,"Table_Fournisseur");
        load_list_TableView(m_tableViewClient,"Table_Client");

    }else if (m_comboBoxFilter->currentIndex() == 1) {

        m_lineEditeFiltre->setEnabled(true);
        m_lineEditeFiltre->clear();

        if (m_comboBoxFilterCat->currentIndex() == 1){

            completer_filter("Table_Fournisseur","Raison_sociale");
            m_lineEditeFiltre->clear();

        }else if (m_comboBoxFilterCat->currentIndex() == 2) {

            completer_filter("Table_Client","Raison_sociale");
            m_lineEditeFiltre->clear();
        }

    }else if (m_comboBoxFilter->currentIndex() == 2) {

        m_lineEditeFiltre->setEnabled(true);
        m_lineEditeFiltre->clear();

        if (m_comboBoxFilterCat->currentIndex() == 1){

            completer_filter("Table_Fournisseur","Nom_Contact");

        }else if (m_comboBoxFilterCat->currentIndex() == 2) {

            completer_filter("Table_Client","Nom_Contact");
        }

    }else if (m_comboBoxFilter->currentIndex() == 3) {

        m_lineEditeFiltre->setEnabled(true);
        m_lineEditeFiltre->clear();

        if (m_comboBoxFilterCat->currentIndex() == 1){

            completer_filter("Table_Fournisseur","Prenoms_Contact");

        }else if (m_comboBoxFilterCat->currentIndex() == 2) {

            completer_filter("Table_Client","Prenoms_Contact");
        }

    }
}

void QwidgesFournisseurClient::on_click_bt_effacer_filtre()
{
    /*
     * Permet de reinitialiser la filtre par click sur le boutton "Effacer"
     */
    m_comboBoxFilterCat->setCurrentIndex(0);
    m_lineEditeFiltre->clear();
    load_list_TableView(m_tableViewClient,"Table_Client");
    load_list_TableView(m_tableViewFournisseur,"Table_Fournisseur");
}

void QwidgesFournisseurClient::on_click_bt_rechercher_filtre()
{
    /*
     * Permet d'établir une filtre dans chaque tableau
     * On test la valeur de l'index du m_comboBoxFilterCat pour savoir dans quel
     * table on vas faire le trie, puis on test la valeur de l'index dans le
     * m_comboBoxFilter pour obtenir la colonne de la table concerner
     */

    int indexCat = m_comboBoxFilterCat->currentIndex();
    int indexfiltre = m_comboBoxFilter->currentIndex();

    QString valeurRechercher;
    valeurRechercher = m_lineEditeFiltre->text();
    QSqlQuery qry;
    QSqlQueryModel * model = new QSqlQueryModel;

    switch (indexCat) {
    case 0:
    {
        qDebug()<<"Ne rien faire";

    }
        break;
    case 1:
    {
        // Table_Fournisseur

        switch ( m_comboBoxFilter->currentIndex()) {
        case 0:
        {
            qDebug()<<"Table_Fournisseur / indexfiltre = 0";
        }
            break;
        case 1:
        {
            qry.prepare("SELECT Code,Raison_sociale,civilite_contact,Nom_contact,Prenoms_contact,tel_1,Adresse_email FROM Table_Fournisseur WHERE Raison_sociale = '"+valeurRechercher+"' ");
            qry.exec();
            model->setQuery(qry);
            m_tableViewFournisseur->setModel(model);
        }
            break;
        case 2:
        {
            qry.prepare("SELECT Code,Raison_sociale,civilite_contact,Nom_contact,Prenoms_contact,tel_1,Adresse_email FROM Table_Fournisseur WHERE Nom_contact = '"+valeurRechercher+"' ");
            qry.exec();
            model->setQuery(qry);
            m_tableViewFournisseur->setModel(model);
        }
            break;
        case 3:
        {
            qry.prepare("SELECT Code,Raison_sociale,civilite_contact,Nom_contact,Prenoms_contact,tel_1,Adresse_email FROM Table_Fournisseur WHERE Prenoms_contact = '"+valeurRechercher+"' ");
            qry.exec();
            model->setQuery(qry);
            m_tableViewFournisseur->setModel(model);
        }
            break;
        default:
            break;
        }
    }
        break;
    case 2:
    {
        // Table_Client
        switch (indexfiltre) {
        case 0:
        {
            qDebug()<<"Table_Fournisseur / indexfiltre = 0";
        }
            break;
        case 1:
        {
            qry.prepare("SELECT Code,Raison_sociale,civilite_contact,Nom_contact,Prenoms_contact,tel_1,Adresse_email FROM Table_Client WHERE Raison_sociale = '"+valeurRechercher+"' ");
            qry.exec();
            model->setQuery(qry);
            m_tableViewClient->setModel(model);
        }
            break;
        case 2:
        {
            qry.prepare("SELECT Code,Raison_sociale,civilite_contact,Nom_contact,Prenoms_contact,tel_1,Adresse_email FROM Table_Client WHERE Nom_contact = '"+valeurRechercher+"' ");
            qry.exec();
            model->setQuery(qry);
            m_tableViewClient->setModel(model);
        }
            break;
        case 3:
        {
            qry.prepare("SELECT Code,Raison_sociale,civilite_contact,Nom_contact,Prenoms_contact,tel_1,Adresse_email FROM Table_Client WHERE Prenoms_contact = '"+valeurRechercher+"' ");
            qry.exec();
            model->setQuery(qry);
            m_tableViewClient->setModel(model);
        }
            break;
        default:
            break;
        }
    }
    default:
        break;
    }
}

void QwidgesFournisseurClient::contextMenuFournisseur   (QPoint Position)
{
    /*
     * Ouvrir le contextMenus par la click droite sur le contextMenu_TableView
     */
    contextMenu_TableView("Fournisseur",m_tableViewFournisseur,"Table_Fournisseur", Position);
}

void QwidgesFournisseurClient::contextMenuClient(QPoint Position)
{
    contextMenu_TableView("Client",m_tableViewClient,"Table_Client", Position);
}

void QwidgesFournisseurClient::copy_selectedRow_tableview_Fournisseur()
{
    /*
     * Permet de copier les contenues de chaque célulles selection dans le presse-papier
     */
    copy_selected_row_tableview(m_tableViewFournisseur);
}

void QwidgesFournisseurClient::ouvrir_dialogBox_Modifier_Tiers()
{
    /*
     * Ouverture du dialogBox Modification par le click sur l'action Modification
     * dans le table view
     */
    m_dialogboxModifierTiers->exec();
}

void QwidgesFournisseurClient::on_click_bt_valider_dialogBoxModif_Fournisseur()
{
    /*
     * Permet de valider la modification faite dans le dialogBox_modifier
     */
    valider_Modif_dialogBox_ModifTiers(m_tableViewFournisseur,"Table_Fournisseur");
}

void QwidgesFournisseurClient::on_click_action_afficher_detail()
{
    /*
     * Ouvrir la boite de dialog pour afficher le detail de la ligne selectionner
     */
    m_dialogboxDetail->exec();
}

void QwidgesFournisseurClient::on_click_action_supprimer()
{
    /*
     * Click sur l'action supprimer du contextMenu d'une tableView
     * permet d'ouvrir le dialogBox d'avertissement avant la suppression
     */
    m_dialogBox_Avertissement_suppr->exec();
}

void QwidgesFournisseurClient::on_click_bt_valider_dialogBoxSupp_Fournisseur()
{
    /*
     * Valider la suppresion du ligne selectionner par le validation
     * du dialogBox suppr
     */
    supprimer_ligne_tableView(m_tableViewFournisseur,"Table_Fournisseur");
}

void QwidgesFournisseurClient::on_click_bt_valider_dialogBoxSupp_Client()
{
    /*
     * Valider la suppresion du ligne selectionner par le validation
     * du dialogBox suppr
     */
    supprimer_ligne_tableView(m_tableViewClient,"Table_Client");
}

void QwidgesFournisseurClient::on_click_action_enregistrerSous()
{
    /*
     * le test avec hasFocus() permet de savoir quelle tableView à ete selectionner
     */
    if(m_tableViewFournisseur->hasFocus()){
        enregistrer_tableau_sous(m_tableViewFournisseur);
    }else if (m_tableViewClient->hasFocus()) {
        enregistrer_tableau_sous(m_tableViewClient);
    }
}




