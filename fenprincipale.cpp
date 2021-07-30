#include "fenprincipale.h"

fenPrincipale::fenPrincipale()
{   
//    ------------ INITIALISATION VARIABLES ----------------
    m_gridLayoutPple = new QGridLayout;
    m_tabwidgetPple = new TabWidet;
    m_centralWidget = new QWidget;
    m_widgettProduit = new QwidgettProduit;
    m_widgetFournisseurClient = new QwidgesFournisseurClient;
    m_widget_parametre = new qwidget_onglet_parametre;
    m_widget_entre = new qwidget_onglet_entree;
//    --------------------------------------------------------

    /* *******************************
     * Mise en forme de l'application*
     *********************************/
//----                              -----------------------

    // Definition du grid principale de la fenetre
    this->setWindowTitle("Mampi Stock");
    this->setCentralWidget(m_centralWidget);
    this->setContentsMargins(-2,0,-5,0);
    m_centralWidget->setLayout(m_gridLayoutPple);
    m_gridLayoutPple->addWidget(m_tabwidgetPple,0,0);

    // Remplissage du m_tabwidgetPple
    QWidget *sortie = new QWidget;
    QWidget * deplacement = new QWidget;
    QWidget * transfert = new QWidget;
    QWidget *stock = new QWidget;
    QWidget *depense = new QWidget;
    QWidget * Devis = new QWidget;
    QWidget * depot = new QWidget;

    m_tabwidgetPple->addTab(m_widgettProduit,tr("Article"));
    m_tabwidgetPple->addTab(m_widgetFournisseurClient,tr("Annuaire"));
    m_tabwidgetPple->addTab(m_widget_parametre,tr("paramètre"));
    m_tabwidgetPple->addTab(m_widget_entre,tr("Mouvement d'Entrée"));
    m_tabwidgetPple->addTab(sortie,tr("Mouvement de Vente"));
    m_tabwidgetPple->addTab(deplacement,tr("Déplacement du stock"));
    m_tabwidgetPple->addTab(transfert,tr("Mouvement de transfert"));
    m_tabwidgetPple->addTab(depot,tr("Dépôts de stockage"));
    m_tabwidgetPple->addTab(stock,tr("Stock"));
    m_tabwidgetPple->addTab(Devis,tr("Devis"));    
    m_tabwidgetPple->addTab(depense,tr("Dépense"));


    m_tabwidgetPple->setDocumentMode(true);
    m_tabwidgetPple->setMovable(true);

    m_tabwidgetPple->tabBar()->setStyleSheet("QTabBar{color:white ; font-size: 15px}");

    this->showMaximized();

    // FONCTIONS POUR CREE LES REF DES NOUVELLE SAISIE DE CHAQUE ONGLET
    creat_ref_for_label(m_widget_entre->m_label_ref_entre_from_db,"Table_Entree","id_ref","EN");
    creat_ref_for_label(m_widgettProduit->m_labelCodeProduit,"Table_Produit","idProd","PR");

    // SLOT -------------------------------------
    connect(m_widgettProduit->m_popUpDialogModifier->m_pushButtonValiderPopModifProd,SIGNAL(clicked(bool)),this,SLOT(on_click_valider_modif_prod()));
    connect(m_widgetFournisseurClient->m_dialogboxModifierTiers->m_pushButton_dialogBox_Modif_Valider,SIGNAL(clicked(bool)),this,SLOT(on_click_valider_modif_fournisseur()));
    connect(m_widget_entre->m_pushbutton_filtre_valider,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_valider_entree()));
}


// FONCTION ------------------------------------------------------------
void fenPrincipale::reload_tab_entre_produit()
{
    // Actualiser donnée dans l'ongle Entrée
    m_widget_entre->auto_complete_by_Designation();
    m_widget_entre->auto_complete_by_ref();
    m_widget_entre->completer_lineEdit(m_widget_entre->m_lineEdit_designation,"Table_Produit","NomProduit");
    m_widget_entre->completer_lineEdit(m_widget_entre->m_lineEdit_famille,"Table_Produit","Categorie");
    m_widget_entre->completer_lineEdit(m_widget_entre->m_lineEdit_ref_article,"Table_Produit","CodeProduit");
}

void fenPrincipale::reload_tab_entre_fournisseur()
{
    m_widget_entre->completer_lineEdit(m_widget_entre->m_lineEdit_fournisseur,"Table_Fournisseur","Raison_sociale");
    m_widget_entre->m_lineEdit_fournisseur->clear();
}

void fenPrincipale::creat_ref_for_label(QLabel *label, const char * nom_table, const char * id ,const char *prefix)
{
    /*
     * Permet d'afficher la refférence de ce qui va etre enregistrer dans la base de donnée
     * label  = nom du label qui va afficher la ref
     * nom_table = nom du table dans la base de donnée
     * id = nom du colonne de l'id dans la base de donnée
     * prefix = Prefix qui deffinit l'entitée saisie ex: PR pour produit
     */
    QSqlQuery qry;
    QString Nom_table_bd = QString(nom_table);
    QString prefix_string = QString(prefix);
    QString id_tostring = QString(id);

    qry.prepare("SELECT COUNT(*) FROM "+Nom_table_bd+" ");
    qry.exec();
    while (qry.next()) {
        if (qry.value(0).toString() == 0){
            label->setText(prefix_string.append("_1"));
        }else {
            QSqlQuery qry_count;
            int num_Nouveau;
            qry_count.prepare("SELECT MAX ("+id_tostring+") FROM "+Nom_table_bd+"");
            qry_count.exec();
            while (qry_count.next()) {
                num_Nouveau = qry_count.value(0).toInt() + 1 ;
            }
            QString ref = prefix_string.append("_").append(QString::number(num_Nouveau));
            label->setText(ref);
        }
    }
}


// SLOT -----------------------------------------------------------------
void fenPrincipale::on_click_valider_modif_prod()
{
    /*
     * Permet d'actualiser tout les donnée l' onglet mouvement d'entrée apres une modif
     * dans l'onglet article
     */
    reload_tab_entre_produit();
}

void fenPrincipale::on_click_valider_modif_fournisseur()
{
    /*
     * Permet d'actualiser tout les donnée l' onglet mouvement d'entrée apres une modif
     * dans l'onglet Annuaire "fournisseur"
     */
    reload_tab_entre_fournisseur();
}

void fenPrincipale::on_click_bt_valider_entree()
{
    creat_ref_for_label(m_widget_entre->m_label_ref_entre,"Table_Entree","id_ref","EN");
}

