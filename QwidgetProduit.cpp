#include "QwidgetProduit.h"
#include "qwidget_onglet_entree.h"
#include "fenprincipale.h"


    QwidgettProduit::QwidgettProduit()
    {
        /************
         * Variables*
         ************/
    //------
        m_formLayoutProduit = new QFormLayout;                          // permet de contenir les différents widgets pour le saisie du nouveau produit
        m_lineEditNomCategorie = new QLineEdit;                         // Permet de saisire la categorie du nouveau produit
        m_spinBoxStockMinProduit = new QSpinBox;                      // Permet de saisir le stock min du nouveau produit
        m_lineEditNomProduit = new QLineEdit;                           // Permet de saisir le nom du Nouveau produit
        m_tableViewProduit = new QTableView;                            // Permet d'afficher le tableau des Produits
        m_hboxLayoutProduit = new QHBoxLayout;                          // Permet de contenir les bouttons Valider et Annuler du Saisie de nouveau produit
        m_pushButtonProduitValider = new QPushButton(tr("Valider"));    // Permet de valider la saisie de nouvelle produit dans la base de donnée
        m_pushButtonProdsuitAnnuler = new QPushButton(tr("Annuler"));   // Permet d'annuler la saisie de nouvelle produit en cours et d'effaces tout les saisie effectuer sur Groupe box nouveau prod
        m_groupBoxNouveauProd = new QGroupBox;                          // Permet de regrouper tout les widgets concernat la saisie de nouvelle prodduit
        m_gridLayoutNouvProduit = new QGridLayout;                      // Permet de regrouper tout les widget et layout parent de l'onglet Produit
        m_comboBoxFiltreCategorie = new QComboBox;                      // Permet de filtrer le tableau "tableview" contenant la liste des produit suivant la categorie de produit
        m_comboBoxFiltreNomProduit = new QComboBox;                     // Permet de filtrer le tableau "tableview" contenant la liste des produit suivant le nom des produit
        m_formLayoutFiltreProduit = new QFormLayout;                    // Permet de ranger en verticale les élements de filtre du tableau sans utiliser Qlabel
        m_gridLayoutFiltreProduit = new QGridLayout;                    // Permet de ranger les widgets concernant la filtre du tableau
        m_groupBoxFiltreProduit = new QGroupBox;                        // Permet de regrouper les produit dans une delimitation visible avec entete
        m_comboBoxUniteProduit = new comboBoxUnite;                     // Permet de saisir l'unité du nouveau produit
        m_labelCodeProduit = new QLabel;                                // Permet d'afficher le code du nouveau produit qui serras saisie
        m_popUpDialogModifier = new popUpModifierProduit;               // Permet de modifier un produit selectionner dans la base de donnée apres cilck sur l'action actionModifier du contextMenu
        m_dialogSupProd = new dialogsupprProd;                          // Permet d'afficher une popUp d'avertissement avant la suppression d'un produit dans la base
        m_tableViewProduitSup = new QTableView;                         // Permet d'afficher la liste des produits supprimer
        m_groupBoxProduitSup = new QGroupBox;                           // Permet de regrouper les widgets pour l'affichage des produit supprimer
        m_gridlayoutProdSup = new QGridLayout;                          // Permet de regrouper les widgets du liste des prod supprimer
        m_groupBoxProduit = new QGroupBox;                              // Permet de regrouper tous les widgets du Produit en cours
        m_gridlayoutProd = new QGridLayout;                             // Permet de regrouper les widgets des produit non supprimer
        m_gridlayoutPrincipalProd = new QGridLayout;                    // Permet de contenir tout les widgets sur l'onglet Produit
        m_toolbarProduit = new QToolBar;
        m_menuFichier = new QMenu;
        m_menuBarProduit = new QMenuBar;
        m_menuVider = new QMenu;

        // Mise en forme du groupe produit ------------------------------------------------

        m_formLayoutProduit->addRow(tr("Code :"),m_labelCodeProduit);
        m_formLayoutProduit->addRow(tr("Nom Produit :"),m_lineEditNomProduit);
        m_formLayoutProduit->addRow(tr("Famille d'article :"),m_lineEditNomCategorie);
        m_formLayoutProduit->addRow(tr("Stock Mini :"),m_spinBoxStockMinProduit);
        m_formLayoutProduit->addRow(tr("Unité :"),m_comboBoxUniteProduit);

        /*
         * Permet de definir automatiquement la longeure des widgets
         * dans le m_formLayoutProduit suivant la longeure des textes
         * contenus dans ces dernier
         */
        m_formLayoutProduit->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

        m_hboxLayoutProduit->addWidget(m_pushButtonProduitValider);
        m_hboxLayoutProduit->addWidget(m_pushButtonProdsuitAnnuler);


        m_gridLayoutNouvProduit->addLayout(m_formLayoutProduit,0,0,4,2);
        m_gridLayoutNouvProduit->addLayout(m_hboxLayoutProduit,5,1,1,1);
        m_groupBoxNouveauProd->setTitle(tr("Nouveau Produit"));
        m_groupBoxNouveauProd->setLayout(m_gridLayoutNouvProduit);

        m_spinBoxStockMinProduit->setMinimumWidth(50);

        // Mise en forme du filtre ------------------------------------------------------
        m_formLayoutFiltreProduit->addRow(tr("Nom Produit: "),m_comboBoxFiltreNomProduit);
        m_formLayoutFiltreProduit->addRow(tr("Famille d'article : "),m_comboBoxFiltreCategorie);

        m_comboBoxFiltreCategorie->setMinimumWidth(100);
        m_comboBoxFiltreNomProduit->setMinimumWidth(100);

        /*
         * Permet de definir automatiquement la longeure des widgets
         * dans le m_formLayoutProduit suivant la longeure des textes
         * contenus dans ces dernier
         */
        m_formLayoutFiltreProduit->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);


        m_gridLayoutFiltreProduit->addLayout(m_formLayoutFiltreProduit,0,0);
        m_groupBoxFiltreProduit->setLayout(m_gridLayoutFiltreProduit);
        m_groupBoxFiltreProduit->setTitle(tr("Filtre"));

        // Mise en forme du groupe produit supprimer -------------------------------------
        m_groupBoxProduitSup->setLayout(m_gridlayoutProdSup);
        m_groupBoxProduitSup->setTitle(tr("Liste des produits supprimer"));
        m_gridlayoutProdSup->addWidget(m_tableViewProduitSup,0,0);

        // Mise en forme du groupe Tbeau liste des produit ----------------------------------
        m_groupBoxProduit->setLayout(m_gridlayoutProd);
        m_gridlayoutProd->addWidget(m_tableViewProduit);
        m_groupBoxProduit->setTitle("Liste des produits");
        m_tableViewProduit->setSelectionBehavior(QAbstractItemView::SelectRows); // Permet de selectionner toute la ligne du tableview au lieu d'une seule cellule

        // --------------------------------------------------------------------------------

        // Mise en forme toolbar -----------------------------------------------------------
        QAction *actionEnregistrer = new QAction(tr("Enregistrer sous  \"ctrl+s\""),this);
        QAction *actionImprimer = new QAction(tr("Imprimer"));

        m_menuFichier->setTitle(tr("Fichier"));
        m_menuFichier->addAction(actionEnregistrer);
        m_menuFichier->addAction(actionImprimer);

        m_menuVider->setTitle(tr("Vider le tableau "));
        QAction *actionViderTableauProd = new QAction(tr("Produit"),this);
        QAction *actionViderTableauProdSupprimer = new QAction(tr("Produit supprimer"));
        m_menuVider->addAction(actionViderTableauProd);
        m_menuVider->addAction(actionViderTableauProdSupprimer);

        m_menuBarProduit->addMenu(m_menuFichier);
        m_menuBarProduit->addMenu(m_menuVider);

        //---------------------------------------------------------------------------------


        this->setLayout(m_gridlayoutPrincipalProd);
        m_gridlayoutPrincipalProd->addWidget(m_menuBarProduit,0,0,1,7);
        m_gridlayoutPrincipalProd->addWidget(m_groupBoxNouveauProd,1,0,7,1);
        m_gridlayoutPrincipalProd->addWidget(m_groupBoxFiltreProduit,8,0,3,1);
        m_gridlayoutPrincipalProd->addWidget(m_groupBoxProduit,1,1,18,4);
        m_gridlayoutPrincipalProd->addWidget(m_groupBoxProduitSup,1,5,18,2);

        // Fonctions --------------------------------------------------------------
        loadTableView(m_tableViewProduit,"Table_Produit");                                                                       // Permet de remplir et formater le tabeau
        loadTableView(m_tableViewProduitSup,"Table_Produit_Supprimer");
//        createProductCode();                                                                                                       // Permet d'afficher le code du produit en cours d'ajout à la base de donnée
        remplirComboBoxNomProduit(m_comboBoxFiltreNomProduit);                                                                      // Permet de remplir le combobox de tout les noms de produit dispo dans la base
        remplirComboBoxCategorie(m_comboBoxFiltreCategorie);                                                                        // Permet de remplir le combobox de tout les categorie de produit dispo dans la base
        m_tableViewProduit->setToolTip(tr("Faire un click droit sur un produit pour faire des modifications et/ou suppression"));


        /*
         * Ne pas oublier de definir le menu contextuel en CustomContextMenu
         * pour que le slot contexMenu(QPoint position)marche et ouvre le menu contextuel
         */
        m_tableViewProduit->setContextMenuPolicy(Qt::CustomContextMenu);

        // SLOT --------------------------------------------------------------------
        connect(m_pushButtonProduitValider,SIGNAL(clicked(bool)),this,SLOT(click_bt_valider()));
        connect(m_lineEditNomProduit,SIGNAL(textChanged(QString)),this,SLOT(sortLineEditNomProduit()));
        connect(m_lineEditNomCategorie,SIGNAL(textChanged(QString)),this,SLOT(sortLineEditCategorieProduit()));
        connect(m_tableViewProduit,SIGNAL(customContextMenuRequested(QPoint)),SLOT(contexMenu(QPoint)));  //permet d'ouvrir le menu contextuel par click droit sur une céllule
        connect(m_popUpDialogModifier->m_pushButtonValiderPopModifProd,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_valider_popup_modif()));
        connect(m_pushButtonProdsuitAnnuler,SIGNAL(clicked(bool)),this,SLOT(annulerNouvProd()));
        connect(m_comboBoxFiltreNomProduit,SIGNAL(currentTextChanged(QString)),this,SLOT(filtreNomProd()));
        connect(m_comboBoxFiltreCategorie,SIGNAL(currentTextChanged(QString)),this,SLOT(filtreCat()));
        connect(m_dialogSupProd->m_pushButtonValiderSup,SIGNAL(clicked(bool)),this,SLOT(validerSupprProd()));
        connect(actionEnregistrer,SIGNAL(triggered(bool)),this,SLOT(enregistrer_sous()));
        connect(actionViderTableauProd,SIGNAL(triggered(bool)),this,SLOT(click_Bt_Supp_Prod()));
        connect(actionViderTableauProdSupprimer,SIGNAL(triggered(bool)),this,SLOT(click_action_Supp_ProdSupp()));

        // SHORTCUT -----------------------------------------------------------------
        m_lineEditNomProduit->setToolTip(tr("appuyez sur les touches \"ctrl+n\" pour faire une nouvelle saisie "));
        new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N),this,SLOT(saisieNouvProd())); // Permet de se placer directement le curseur sur m_lineEditNomProduit apres la combinaison de ctrl+n

        new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S),this,SLOT(enregistrer_sous())); // Permet d'enregistre la table en format csv apres la combinaison de ctrl+n
    }



    //-------------------------------FONCTIONS ----------------------------------------
    void QwidgettProduit::loadTableView(QTableView *tableView, const char *Table_Nom)
    {
        /*
         * Fonction permet de remplir le tableview avec les données
         * venant de la base de donnée, d'autre part permet aussi
         * le formatage du tableview.
         * tableView : Nom de la QTableView
         * Table_Nom : Nom de la table dans la base de donnée
         */
            QString nom_Table(Table_Nom);
            QSqlQuery qry;
            qry.prepare("SELECT * FROM '"+nom_Table+"' ");
            if (!qry.exec()){
                qDebug()<< tr("Erreur execution du qry dans la methode ")<<nom_Table<<qry.lastError();
            }else {

                // Remplir le tableview avec le donnée recuperer par le qry dans la base de donnée
                QSqlQueryModel *model = new QSqlQueryModel;
                model->setQuery(qry);
                tableView->setModel(model);

                // Renomer tout les en têtes du tableau
                model->setHeaderData(0,Qt::Horizontal,tr("Code"),Qt::DisplayRole);
                model->setHeaderData(1,Qt::Horizontal,tr("Nom"),Qt::DisplayRole);
                model->setHeaderData(2,Qt::Horizontal,tr("Stock Mini"),Qt::DisplayRole);
                model->setHeaderData(3,Qt::Horizontal,tr("Catégorie"),Qt::DisplayRole);
                model->setHeaderData(4,Qt::Horizontal,tr("Quantité en Stock"),Qt::DisplayRole);
                model->setHeaderData(5,Qt::Horizontal,tr("Unités"),Qt::DisplayRole);

                /*
                 * Permet de cacher les en tête vertical du tablview
                 * Ne pas oublier d'inclure QHeaderView dans le fichier header "gridlayoutprodui.h"
                 */
                tableView->verticalHeader()->hide();
                tableView->hideColumn(6);

                /*
                 * Permet de faire le formatage du header de la tableview
                 * Remarque: le setStyleSheet utilise le language css pour
                 * faire le formatage de la selection
                 */
                tableView->setStyleSheet("QHeaderView::section {background-color:#4169E1; color:white; font-size : 13px}");

                }
    }

    void QwidgettProduit::createProductCode()
    {
        /*
         * Permet de créer des code de produit pour chaque nouveau produit.
         * 1 - Veriffier si la table est vide. si c'est le cas : on initialise
         * la le comptage avec le code "PR_1".
         * 2 - si par contre, la table n'est pas vide; on reccupère l'idProd
         * du dernier produit puis on l'incremante 1 est on affiche la nouvelle CodeProduit
         * dans le Qlable
         */


            QSqlQuery qryTest;
            QString prefixCode = "PR";

            qryTest.prepare("SELECT count(*) FROM Table_Produit ");            // Permet de compter le nombre de ligne dans la table
            if (!qryTest.exec()){
                qDebug()<<"Erreur test"<<qryTest.lastError();
            }else {
                while (qryTest.next()) {
                    if ( qryTest.value(0).toInt() == 0){                       // si la table est vide
                        m_labelCodeProduit->setText("PR_1");
                    }else {
                        QSqlQuery qryCount;
                        int numNouvProd;
                        qryCount.prepare("SELECT MAX (idProd) FROM table_Produit"); // se placer à la derniere ligne du colonne idProd pour recuperer l'id
                        if (!qryCount.exec()){
                            qDebug()<<"Erreur qryCount"<<qryCount.lastError();
                        }else {
                            while (qryCount.next()) {
                                numNouvProd = qryCount.value(0).toInt() + 1;
                            }
                            QString codeProduit = prefixCode.append("_").append(QString::number(numNouvProd));
                            m_labelCodeProduit->setText(codeProduit);
                        }

                    }
                }

           }

    }

    void QwidgettProduit::remplirComboBoxNomProduit(QComboBox *combox)
    {
        /*
         * Permet de remplir le Combobox "Nom De Produit" avec la liste
         * des produit disponible dans la base de donnée
         */
        combox->setEditable(true);
        QStringList listNomProd;
        QSqlQuery qry;
        qry.prepare("SELECT NomProduit FROM Table_Produit");
        if (!qry.exec()){
            qDebug()<<tr("Erreur execution qry fonction remplirComboBoxNomProduit")<<qry.lastError();
        }else{
            while (qry.next()) {
                QString nomProd = qry.value(0).toString();
                listNomProd.append(nomProd);
                listNomProd.removeDuplicates();
            }
            combox->addItem("");
            combox->addItems(listNomProd);
            combox->setCurrentIndex(0);
        }

        /*
         *  permet de filtrer la liste des nom de produit dans le
         * combobox en fonction des caractères saisie dans ce dernier
         */
        QCompleter *mycompleter = new QCompleter(listNomProd);
        combox->setCompleter(mycompleter);
        mycompleter->setCompletionMode(QCompleter::PopupCompletion);
        mycompleter->setModelSorting(QCompleter::UnsortedModel);
        mycompleter->setFilterMode(Qt::MatchStartsWith);
        mycompleter->setCaseSensitivity(Qt::CaseInsensitive);
    }

    void QwidgettProduit::remplirComboBoxCategorie(QComboBox *combox)
    {
        /*
         * Permet de remplir le Combobox "Nom De Produit" avec la liste
         * des produit disponible dans la base de donnée
         */
        combox->setEditable(true);
        QStringList listNomProd;
        QSqlQuery qry;
        qry.prepare("SELECT Categorie FROM Table_Produit");
        if (!qry.exec()){
            qDebug()<<tr("Erreur execution qry fonction remplirComboBoxNomProduit")<<qry.lastError();
        }else{
            while (qry.next()) {
                QString nomProd = qry.value(0).toString();
                listNomProd.append(nomProd);
                listNomProd.removeDuplicates();
            }
            combox->addItem("");
            combox->addItems(listNomProd);
            combox->setCurrentIndex(0);
        }

        /*
         *  permet de filtrer la liste des nom de produit dans le
         * combobox en fonction des caractères saisie dans ce dernier
         */
        QCompleter *mycompleter = new QCompleter(listNomProd);
        combox->setCompleter(mycompleter);
        mycompleter->setCompletionMode(QCompleter::PopupCompletion);
        mycompleter->setModelSorting(QCompleter::UnsortedModel);
        mycompleter->setFilterMode(Qt::MatchStartsWith);
        mycompleter->setCaseSensitivity(Qt::CaseInsensitive);
    }

    void QwidgettProduit::rafraichirComboboxNomProduit(QComboBox *combobox)
    {
        /*
         * Actualiser la liste des produits dans le fitre combobox
         * NomProduit apres modification
         */
        for (int i=0; i<= combobox->count(); ++i){
            combobox->clear();
            combobox->removeItem(i);
        }
        remplirComboBoxNomProduit(combobox);
        combobox->setCurrentIndex(0);
    }

    void QwidgettProduit::rafraichirComboboxCategorie(QComboBox *combobox)
    {
        /*
         * Actualiser la liste des produits dans le fitre combobox
         * NomProduit apres modification
         */
        for (int i=0; i<= combobox->count(); ++i){
            combobox->clear();
            combobox->removeItem(i);
        }
        remplirComboBoxCategorie(combobox);
        combobox->setCurrentIndex(0);
    }

    void QwidgettProduit::reinitialiserNouveauProd()
    {
        /*
         * Permet de reinitialiser tout les élement de saisie
         * de nouveau produit
         */
        loadTableView(m_tableViewProduit,"Table_Produit");
        m_lineEditNomCategorie->clear();
        m_lineEditNomProduit->clear();
        m_spinBoxStockMinProduit->setValue(0);
        m_comboBoxUniteProduit->setCurrentIndex(0);
    }

    void QwidgettProduit::effacerListCombobox(QComboBox *combobox)
    {
        for (int i=0; i<= combobox->count(); ++i){
            combobox->clear();
            combobox->removeItem(i);
        }
    }

    bool QwidgettProduit::doublonProdExist(QLineEdit *lineEditNom)
    {
        /*
         * Permet de vérifier si le produit existe déjà
         * si le produit, exist renvoi vraie, si non faux
         */
        QString Nom = lineEditNom->text();
        QSqlQuery qry;
        QString CodeProduit;
        qry.prepare("SELECT CodeProduit FROM Table_Produit WHERE NomProduit = '"+Nom+"'");
        qry.exec();
        while (qry.next()) {
            CodeProduit = qry.value(0).toString();
        }

        if (CodeProduit != ""){
            return true;
        }
    }

    void QwidgettProduit::validerNouvProd()
    {
        /*
         * Permet d'enregistrer les données dans la base de donnée par
         * l'appuis sur le boutton valider. Tous les donnée sur l'interface
         * de saisie sont reinitialiser.
         */

                QString CodeProduit = m_labelCodeProduit->text();
                QString NomProduit = m_lineEditNomProduit->text().toUpper();
                QString Categorie = m_lineEditNomCategorie->text().toUpper();
                QString StockMini = m_spinBoxStockMinProduit->text().toUpper();
                QString Unite = m_comboBoxUniteProduit->currentText();

                QSqlQuery qry;
                qry.prepare("INSERT into Table_Produit (CodeProduit,NomProduit,Categorie,StockMini,Unite) values ( :CodeProduit,:NomProduit,:Categorie,:StockMini,:Unite )");
                qry.exec();
                qry.bindValue(":CodeProduit",CodeProduit);
                qry.bindValue(":NomProduit",NomProduit);
                qry.bindValue(":Categorie",Categorie);
                qry.bindValue(":StockMini",StockMini);
                qry.bindValue(":Unite",Unite);
                if (!qry.exec()){
                    qDebug()<<tr("Erreur execution qry slot validerProduit") << qry.lastError();
                }else {

                    // reinitialisation de tout les élement de saisie de donnée et les filtres
                    reinitialiserNouveauProd();
                    rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
                    rafraichirComboboxCategorie(m_comboBoxFiltreCategorie);
                    createProductCode();
                }
    }

    void QwidgettProduit::pressEnterKey()
    {
        if (m_lineEditNomCategorie->text() != "" && m_lineEditNomProduit->text() != ""){
            if (!doublonProdExist(m_lineEditNomProduit)){
                if (m_spinBoxStockMinProduit->text() >0){
                    if (m_comboBoxUniteProduit->currentIndex() == 0){
                        QMessageBox msgBox;
                        msgBox.setIcon(QMessageBox::Information);
                        msgBox.setText(tr("veuillez saisir l'unité du stock min"));
                        msgBox.exec();
                    }else {
                        validerNouvProd();
                        rafraichirComboboxCategorie(m_comboBoxFiltreCategorie);
                        rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
                    }
                }else {
                    validerNouvProd();
                    rafraichirComboboxCategorie(m_comboBoxFiltreCategorie);
                    rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
                }

            }else {
                qDebug()<<"il y à un doublon";
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setText(tr("veuillez saisir un autre nom de produit"));
                msgBox.exec();
            }

        }else {
            qDebug()<<"Ouvrir popUp valeur obligatoire";
            QMessageBox msgBox;
            msgBox.setWindowTitle(tr("Valeur manquante"));
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText(tr("Une ou plusieurs valeur manquante"));
            msgBox.exec();
        }
    }

    void QwidgettProduit::keyPressEvent(QKeyEvent *event)
    {
        /*
         * Permet de valider la saisie du nouveau produit par l'appuye sur
         * la touche Entrée ou la touche returne. keyPressEvent s'utilise
         * dans un QWidget.
         */
        if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
            pressEnterKey();
        }

    }


    //----------------------- SLOTS -----------------------------------------------------
    void QwidgettProduit::click_bt_valider()
    {
        /*
         * click sur le boutton valider; executer une teste si
         * le produit existe.
         * si le produit existe => ouvrir popUp
         * si le produit n'éxiste pas => enregistrer le produit
         */
        if (m_lineEditNomCategorie->text() != "" && m_lineEditNomProduit->text() != ""){
            if (!doublonProdExist(m_lineEditNomProduit)){
                if (m_spinBoxStockMinProduit->text() >0){
                    if (m_comboBoxUniteProduit->currentIndex() == 0){
                        QMessageBox msgBox;
                        msgBox.setIcon(QMessageBox::Information);
                        msgBox.setText(tr("veuillez saisir l'unité du stock min"));
                        msgBox.exec();
                    }else {
                        validerNouvProd();
                        rafraichirComboboxCategorie(m_comboBoxFiltreCategorie);
                        rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
                    }
                }else {
                    validerNouvProd();
                    rafraichirComboboxCategorie(m_comboBoxFiltreCategorie);
                    rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
                }

            }else {
                qDebug()<<"il y à un doublon";
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setText(tr("veuillez saisir un autre nom de produit"));
                msgBox.exec();
            }

        }else {
            qDebug()<<"Ouvrir popUp valeur obligatoire";
            QMessageBox msgBox;
            msgBox.setWindowTitle(tr("Valeur manquante"));
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText(tr("Un ou pleureuse valeur manquante"));
            msgBox.exec();
        }

    }

    void QwidgettProduit::sortLineEditNomProduit()
    {
        /*
         * Permet de donnée des propotitions durants la saisie
         * dans le QlineEdit NomProduit
         */
            QSqlQuery qry;
            qry.prepare("SELECT NomProduit FROM Table_Produit");
            if (!qry.exec()){
                qDebug()<<tr("Erreur l'ors de l'execution du qry dans le slot sortinLabelWidgetdget") <<qry.lastError();
            }else {
                QStringList listNomProduit;
                while (qry.next()) {
                    QString nomProduit = qry.value(0).toString();
                    listNomProduit.append(nomProduit);
                    listNomProduit.removeDuplicates();
                }

                /*
                 * permet de filtrer la liste des nom de produit dans le
                 * lineEdit en fonction des caractères saisie dans ce dernier
                 */
                QCompleter *mycompleter = new QCompleter(listNomProduit);
                m_lineEditNomProduit->setCompleter(mycompleter);
                mycompleter->setCompletionMode(QCompleter::PopupCompletion);
                mycompleter->setModelSorting(QCompleter::UnsortedModel);
                mycompleter->setFilterMode(Qt::MatchStartsWith);
                mycompleter->setCaseSensitivity(Qt::CaseInsensitive);
            }
    }

    void QwidgettProduit::sortLineEditCategorieProduit()
    {
        /*
         * Permet de donnée des propotitions durants la saisie
         * dans le QlineEdit m_lineEditNomCategorie.
         */

            QSqlQuery qry;
            qry.prepare("SELECT Categorie FROM Table_Produit");
            if (!qry.exec()){
                qDebug()<<tr("Erreur l'ors de l'execution du qry dans le slot sortinLabelWidgetdget") <<qry.lastError();
            }else {
                QStringList listNomProduit;
                while (qry.next()) {
                    QString nomProduit = qry.value(0).toString();
                    listNomProduit.append(nomProduit);
                    listNomProduit.removeDuplicates();
                }
                QCompleter *mycompleter = new QCompleter(listNomProduit);
                m_lineEditNomCategorie->setCompleter(mycompleter);
                mycompleter->setCompletionMode(QCompleter::PopupCompletion);
                mycompleter->setModelSorting(QCompleter::UnsortedModel);
                mycompleter->setFilterMode(Qt::MatchStartsWith);
                mycompleter->setCaseSensitivity(Qt::CaseInsensitive);
            }
    }

    void QwidgettProduit::contexMenu(QPoint position)
    {
        /*
         * Permet d'ouvrir une menu contextuel au click droite sur une céllule
         * Recupperer la position du céllule cellectionner et recupérer tout
         * les données des colonnes du même ligne pour l'envoyer au modification
         */

        QModelIndex index = m_tableViewProduit->indexAt(position); // Permet de recupérer la potision selectionner
        QMenu *menu = new QMenu(m_tableViewProduit);
        QAction *actionModif = new QAction(tr("Modifier"),m_tableViewProduit);
        QAction *actionSupprimer = new QAction(tr("Supprimer"),m_tableViewProduit);
        QAction *actionCopy = new QAction(tr("Copier"),m_tableViewProduit);
        menu->addAction(actionCopy);
        menu->addAction(actionModif);
        menu->addAction(actionSupprimer);
        menu->popup(m_tableViewProduit->viewport()->mapToGlobal(position)); // Afficher le popUP sur la céllule selectionner
        connect(actionModif,SIGNAL(triggered(bool)),this,SLOT(ouvrir_popup_modifier_produit()));
        connect(actionSupprimer,SIGNAL(triggered(bool)),this,SLOT(ouvrirPopUpSuppressionProd()));
        connect(actionCopy,SIGNAL(triggered(bool)),this,SLOT(copy_selected_row()));

        int x, yCode, yNom, yStockMin, yCat, yUnite;

        x=index.row(); // Permet de selectionner la ligne du céllule selectionner

        // y permetent de se positionner sur chaque colonne
        yCode =0;
        yNom =1;
        yStockMin = 2;
        yCat =3;
        yUnite =5;

        /*
         * Creer des QModelIndex pour se placer sur chaque cellule
         * qui ont les mêmes ligne que le cellule selectionner
        */
        QModelIndex indexCode = m_tableViewProduit->model()->index(x,yCode);
        QModelIndex indexNom = m_tableViewProduit->model()->index(x,yNom);
        QModelIndex indexStockMin = m_tableViewProduit->model()->index(x,yStockMin);
        QModelIndex indexCat = m_tableViewProduit->model()->index(x,yCat);
        QModelIndex indexUnite = m_tableViewProduit->model()->index(x,yUnite);



        /*
         * Recuperer les donnée de chaque cellule de la ligne où la selection a été faite
         * puis le convertir en string pour pouvoir l'afficher dans le popUp
         */
        QString CodeProdFromTableview = indexCode.data(2).toString();
        QString NomProdFromTableview = indexNom.data(2).toString();
        QString StockMinProdFromTableview = indexStockMin.data(2).toString();
        QString CatProdFromTableview = indexCat.data(2).toString();
        QString UniteProdFromTableview = indexUnite.data(2).toString();

        /*
         * Envoyer les donnée reçue de la tableview vers le dialogBox Modifier
         */
         m_popUpDialogModifier->m_labelCodeProdPopModif->setText(CodeProdFromTableview);
         m_popUpDialogModifier->m_lineEditnomProdpopModif->setText(NomProdFromTableview);
         m_popUpDialogModifier->m_lineEditcatProdpopModif->setText(CatProdFromTableview);
         int stock_min_int = StockMinProdFromTableview.toInt();
         m_popUpDialogModifier->m_lineEditstkMinProdpopModif->setValue(stock_min_int);
         m_popUpDialogModifier->m_comboBoxUnitProdPopModif->setCurrentText(UniteProdFromTableview);

         /*
          * Envoyer les infos dans le dialogbox de suppression
          * pour créer le text d'avertissement ainsi que le titre
          * du fenetre du message box-------------------------------------------------------------
          */
         QString infoAvantSUp, codeProd, dialogTitre,nomProd;

         infoAvantSUp = tr("Vous allez supprimer déffinitivement le produit : ");
         m_dialogSupProd->m_labelInfoSup->setText(infoAvantSUp);

         codeProd = CodeProdFromTableview;
         m_dialogSupProd->m_labelCodeProd->setText(codeProd);

         nomProd = " : ";
         nomProd.append(NomProdFromTableview);
         m_dialogSupProd->m_labelNomProd->setText(nomProd);

         dialogTitre=tr("Suppression produit ");
         dialogTitre.append(codeProd);
         m_dialogSupProd->setWindowTitle(dialogTitre);

         //---------------------------------------------------------------------------------
    }

    void QwidgettProduit::ouvrir_popup_modifier_produit()
    {
        /*
         *  Ouverture du popUp de modification
         * apres click sur le context menu du m_tableViewProduit
         */
        m_popUpDialogModifier->exec();
    }

    void QwidgettProduit::on_click_bt_valider_popup_modif()
    {

        qDebug()<<m_comboBoxFiltreNomProduit->count();
        /*
         * slot permet de valider les modifications dans le popUp
         * apres click sur le boutton m_pushButtonValiderPopModifProd
         */
            QSqlQuery qry;
            QString CodeProduit = m_popUpDialogModifier->m_labelCodeProdPopModif->text();
            QString NomProduit = m_popUpDialogModifier->m_lineEditnomProdpopModif->text().toUpper();
            QString Categorie = m_popUpDialogModifier->m_lineEditcatProdpopModif->text().toUpper();
            QString StockMini = m_popUpDialogModifier->m_lineEditstkMinProdpopModif->text().toUpper();
            QString Unite = m_popUpDialogModifier->m_comboBoxUnitProdPopModif->currentText();

            qry.prepare("UPDATE Table_Produit SET   NomProduit ='"+NomProduit+"' , Categorie = '"+Categorie+"',StockMini = '"+StockMini+"',Unite = '"+Unite+"' WHERE CodeProduit = '"+CodeProduit+"' ");

            if (!qry.exec()){
                qDebug()<<tr("Erreur execution qry dans le slot validerModifProd ") <<qry.lastError();
            }else {
                loadTableView(m_tableViewProduit,"Table_Produit"); // actualiser le m_tableViewProduit
                rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
                reinitialiserNouveauProd();
                createProductCode();
                fenPrincipale fen;
                fen.m_widget_entre->auto_complete_by_Designation();
            }
    }

    void QwidgettProduit::annulerNouvProd()
    {
        /*
         * Permet d'annuler tout les saisie dans
         * le groupe Nouveau Produit
         */
        reinitialiserNouveauProd();
    }

    void QwidgettProduit::filtreNomProd()
    {
        /*
         * Permet de filtrer le tableView en fonction
         * du nom de produit choisit dans le combobox Filtre
         * nomProduit
         */
        if (m_comboBoxFiltreNomProduit->currentIndex() != 0){
            if (m_comboBoxFiltreCategorie->currentText() != 0){

                qDebug()<<"Qfficher produit suivant nom et cat";

                QSqlQuery qry;
                QString Categorie = m_comboBoxFiltreCategorie->currentText();
                QString NomProduit = m_comboBoxFiltreNomProduit->currentText();
                qry.prepare("SELECT * FROM Table_Produit WHERE NomProduit = '"+NomProduit+"' AND Categorie = '"+Categorie+"' ");
                if (!qry.exec()){
                    qDebug()<<tr("Erreur execution qry dans le slot filtreNomProd")<<qry.lastError();
                }else {
                    QSqlQueryModel *model = new QSqlQueryModel;
                    model->setQuery(qry);
                    m_tableViewProduit->setModel(model);
                }

            }else {
    //            qDebug()<<"Afficher produit suivant nom";
                QSqlQuery qry;
                QString NomProduit = m_comboBoxFiltreNomProduit->currentText();
                qry.prepare("SELECT * FROM Table_Produit WHERE NomProduit = '"+NomProduit+"' ");
                if (!qry.exec()){
                    qDebug()<<tr("Erreur execution qry dans le slot filtreNomProd")<<qry.lastError();
                }else {
                    QSqlQueryModel *model = new QSqlQueryModel;
                    model->setQuery(qry);
                    m_tableViewProduit->setModel(model);
            }

                }
        }else {
            loadTableView(m_tableViewProduit,"Table_Produit");
        }

    }

    void QwidgettProduit::filtreCat()
    {
        if (m_comboBoxFiltreCategorie->currentIndex() != 0){
            /*
             * Apres le choix de categorie il faut faire correspondre la liste des
             * nom de produit dispo dans le combobox nom de produit au liste dispo
             * dans le table view. pour ce faire: effacer la liste en cours et
             * le remplir avec les produit dispo dans le table view
             */

            // Actualisation du liste de nom dans le combobox NomProduit ----------------------
            effacerListCombobox(m_comboBoxFiltreNomProduit);
            m_comboBoxFiltreNomProduit->addItem("");
            QSqlQuery qry_litNom;
            QStringList listeNom;
            QString Categorie = m_comboBoxFiltreCategorie->currentText();
            qry_litNom.prepare("SELECT NomProduit FROM Table_Produit WHERE Categorie= '"+Categorie+"' ");
            if (!qry_litNom.exec()){
                qDebug()<<tr("Erreur execution qry_litNom dans le slot filtreCat")<<qry_litNom.lastError();
            }else {
                while (qry_litNom.next()) {
                    QString Nom = qry_litNom.value(0).toString();
                    listeNom.append(Nom);
                    listeNom.removeDuplicates();
                }
                m_comboBoxFiltreNomProduit->addItems(listeNom);
            }

            //---------------------------------------------------------------------------------

            if (m_comboBoxFiltreNomProduit->currentIndex() !=0){
                QSqlQuery qry;
                QString NomProduit = m_comboBoxFiltreNomProduit->currentText();
                qry.prepare("SELECT * FROM Table_Produit WHERE NomProduit = '"+NomProduit+"' AND Categorie = '"+Categorie+"' ");
                if (!qry.exec()){
                    qDebug()<<tr("Erreur execution qry_litNom dans le slot filtreCat")<<qry.lastError();
                }else {
                    QSqlQueryModel *model = new QSqlQueryModel;
                    model->setQuery(qry);
                    m_tableViewProduit->setModel(model);
                }
            }else {
                QSqlQuery qry;
                qry.prepare("SELECT * FROM Table_Produit WHERE Categorie = '"+Categorie+"' ");
                if (!qry.exec()){
                    qDebug()<<tr("Erreur execution qry_litNom dans le slot filtreCat")<<qry.lastError();
                }else {
                    QSqlQueryModel *model = new QSqlQueryModel;
                    model->setQuery(qry);
                    m_tableViewProduit->setModel(model);
                }
            }

        }else {
            rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
            loadTableView(m_tableViewProduit,"Table_Produit");
        }
    }

    void QwidgettProduit::ouvrirPopUpSuppressionProd()
    {
        /*
         * Permet d'ouvrir le dialog de confirmation du suppression
         * du produit.
         */
        m_dialogSupProd->exec();
    }

    void QwidgettProduit::validerSupprProd()
    {
            /*
             * Apès confirmation du suppression depuis la dialogBox
             * le produit serras supprimer de la Table_Produit pour etre envoyer
             * vers Table_Produit_Supprimer.
             */
            QSqlQuery qry;
            QSqlQuery qry_delete;
            QString CodeProduit = m_dialogSupProd->m_labelCodeProd->text();
            qry.prepare("INSERT INTO Table_Produit_Supprimer (id,CodeProd,NomProd,Categorie,QteStck,stockMini,Unite) SELECT idProd,CodeProduit,NomProduit,Categorie,QuantiteEnStock,StockMini,Unite FROM Table_Produit WHERE CodeProduit = '"+CodeProduit+"'");
            qry_delete.prepare("DELETE FROM 'Table_Produit' WHERE CodeProduit = '"+CodeProduit+"' ");
            if (!qry.exec()){
                qDebug()<<"Erreur lors de l'execution du qry dans le slot validerSupprProd"<<qry.lastError();
            }else {
                qry_delete.exec();
                loadTableView(m_tableViewProduitSup,"Table_Produit_Supprimer");
                loadTableView(m_tableViewProduit,"Table_Produit");
                rafraichirComboboxCategorie(m_comboBoxFiltreCategorie);
                rafraichirComboboxNomProduit(m_comboBoxFiltreNomProduit);
                createProductCode();
                m_dialogSupProd->close();
            }
    }

    void QwidgettProduit::copy_selected_row()
    {
        /*
         * Slot permet de copier le contenue du cellule selectionner
         * dans le presse à papier à partir du context menu
         */

        // Permet de recupperer la selection actuel
        QItemSelectionModel * selection = m_tableViewProduit->selectionModel();
        QString text_to_clipboard;

        for (int i = 0 ; i <= m_tableViewProduit->model()->columnCount() -2 ; ++i){

            // ("\t") permet d'incérer une tabulation apres chaque saisie; ce qui permet de créer un collage en tablea dans les logicieles comme excel
            text_to_clipboard.append(selection->selectedRows(i).value(0).data().toString().append("\t"));
        }

        // envoyer les valeurs dans le clipboard
        QApplication::clipboard()->setText(text_to_clipboard);
    }

    void QwidgettProduit::enregistrer_sous()
    {

        /*
         * permet d'enregistrer le tableau liste des produits sous forme de csv
         * La permière boucle for consite à créer les entétes du tableau avec le QVector !ne pas oublier le retour à la ligne
         * La deuxieme boucle for consiste à recupérer tout les valeus dans le tableau à partir
         * des index, puis en l'ajoute au Qstring textData.
         * Le QString nomDuFichier permet d'ouvrir la boite de dialogue pour
         * Le QProcess *process permet d'ouvrir le fichier que l'on viens de sauvegarder
         * dans l'application excel
         */


        // Création du fichier csv
        QString textData;
        QVector<QString> enTete;
        enTete << tr("Code") << tr("Nom") << tr("Stock Mini") << tr("Catégorie") << tr("Qté Stock") << tr("Unité");
        for (int i = 0 ; i< enTete.size(); ++i){
            textData.append(enTete[i]);
            textData.append("; ");
        }
        textData.append("\n");

        for (int i=0; i<m_tableViewProduit->model()->rowCount();++i){
            for (int j=0 ; j< m_tableViewProduit->model()->columnCount() - 1; ++j){
                QModelIndex index = m_tableViewProduit->model()->index(i,j);
                textData += index.data(2).toString();
                textData += "; ";
            }
            textData += "\n";
        }
        // Overture de la boite dialogue d'enregistrenement
        QString extension_choisit;
        QString nomDuFichier = QFileDialog::getSaveFileName(this,tr("Enregistrer sous"),QString(),"* ;;CSV(*.csv) ;; Fichiers PDF(*.pdf)",&extension_choisit);
        if (QFileDialog::Accepted){

            if(extension_choisit == "*"){

            }else if(extension_choisit == "CSV(*.csv)"){
                // Création du fichier csv au choit type de fichier csv
                QFile fichier(nomDuFichier);
                    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate)){
                        QTextStream out(&fichier);
                        out << textData;
                        fichier.close();

                        // Lancement automatique de l'application Microsoft Excel et lecture du fichier csv apres création
                        QProcess *process = new QProcess(this);
                        QString programme = "C:/Program Files (x86)/Microsoft Office/root/Office16/EXCEL.EXE";
                        QString chemin = nomDuFichier;
                        qDebug()<<nomDuFichier;
                        process->start(programme,QStringList()<<chemin);
                    }
            }else {
            if (extension_choisit == "Fichiers PDF(*.pdf)"){

                // création du fichier pdf au choix type d'extension .pdf
                // Basée sur la création d'une page html puis impression en pdf

//                qDebug()<<extension_choisit;
                QString dateExporte = QDate::currentDate().toString("dd/MM/yyyy");
                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOrientation(QPrinter::Portrait);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(nomDuFichier);
                QTextDocument doc;
                QString text("<title>Liste des Prdoduits </title>");
                text.append("<style>");
                text.append("table,th,tr{padding:8px ; }");
                text.append("td{padding:3px ;}");
                text.append("</style>");
                text.append("<body>");
                text.append("<table>");
                text.append("<caption>Tableau listes des produits : ").append(dateExporte).append("</caption>");
                text.append("<p></p>");
                if(m_comboBoxFiltreCategorie->currentIndex() != 0){
                    text.append("<p>").append("Catégorie : ").append(m_comboBoxFiltreCategorie->currentText()).append("</p>");
                    text.append("<p></p>");
                }
                text.append("<tr>");
                for (int i =0 ; i< m_tableViewProduit->model()->columnCount()-1; ++i){
                    text.append("<th style=\"background-color:#00FFFF;\">").append(m_tableViewProduit->model()->headerData(i,Qt::Horizontal).toString()).append("</th>");
                }
                text.append("</tr>");
                QModelIndex index;
                for (int i=0 ; i<m_tableViewProduit->model()->rowCount();++i){
                    text.append("<tr style=\" background-color:#DDEDF9 \" ;>");
                    for (int j=0; j<m_tableViewProduit->model()->columnCount()-1;++j){
                        text.append("<td>");
                        index = m_tableViewProduit->model()->index(i,j);
                        text.append(index.data(2).toString());
                    }
                    text.append("</tr>");
                }
                text.append("</table>");
                text.append("</body>");
                doc.setHtml(text);
                doc.setPageSize(printer.paperRect().size());
                doc.print(&printer);

            }
            }
        }
    }

    void QwidgettProduit::click_action_Supp_ProdSupp()
    {
        /*
         * Permet de vider la liste des produit dans le tableau lite des produit supprimer
         * qryDelete permet de supprimer la liste des produit dans la base de donnée Table_Produit_Supprimer
         * qryUpdtade permet de raffraichir l'auto incrementatin du Table_Produit_Supprimer apres la suppression
         * loadTableView permet de raffraichir le tableau m_tableViewProduitSups
         */
        QMessageBox *avertissement = new QMessageBox;
        avertissement->setIcon(QMessageBox::Warning);
        avertissement->setText(tr("Attention, vos étés sur le point de vider la liste des produits supprimés"));
        avertissement->setStandardButtons(QMessageBox::Ok);
        avertissement->addButton(QMessageBox::No);
        if (avertissement->exec() == QMessageBox::Ok){
            QSqlQuery qryDelete;
            QSqlQuery qryUpdtade;
            qryDelete.prepare("DELETE FROM 'Table_Produit_Supprimer' ");
            qryDelete.exec();
            qryUpdtade.prepare("UPDATE SQLITE_SEQUENCE SET SEQ=0 WHERE NAME= 'Table_Produit_Supprimer' ");
            qryUpdtade.exec();
            loadTableView(m_tableViewProduitSup,"Table_Produit_Supprimer");
        }else {
            avertissement->close();
        }
    }

    void QwidgettProduit::click_Bt_Supp_Prod()
    {
        /*
         * Permet de vider la liste des produit dans le tableau liste des produit
         * click sur le boutton m_pushButtonFichierViderListProd permet d'ouvrir une messageBox
         * click sur le boutton ok -> qryDelete permet de supprimer la liste des produit dans la base de donnée Table_Produit
         * qryUpdtade permet de raffraichir l'auto incrementatin du Table_Produit_Supprimer apres la suppression
         * loadTableView permet de raffraichir le tableau m_tableViewProduit
         */
        QMessageBox *avertissement = new QMessageBox;
        avertissement->setIcon(QMessageBox::Warning);
        avertissement->setText(tr("Attention, vos étés sur le point de vider la liste des produits"));
        avertissement->setStandardButtons(QMessageBox::Ok);
        avertissement->addButton(QMessageBox::No);

        if (avertissement->exec() == QMessageBox::Ok){
            QSqlQuery qryDelete;
            QSqlQuery qryUpdtade;
            qryDelete.prepare("DELETE FROM 'Table_Produit' ");
            qryDelete.exec();
            qryUpdtade.prepare("UPDATE SQLITE_SEQUENCE SET SEQ=0 WHERE NAME= 'Table_Produit' ");
            qryUpdtade.exec();
            loadTableView(m_tableViewProduit,"Table_Produit");
            createProductCode();
        }else {
            avertissement->close();
        }
    }

    void QwidgettProduit::saisieNouvProd()
    {
        /*
         * Permet de positionner le cursseur directement sur le m_lineEditNomProduit
         * par l'activation du raccourcie ctrl+n
         */
        m_lineEditNomProduit->setFocus();
    }
