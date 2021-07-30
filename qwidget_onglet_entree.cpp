#include "qwidget_onglet_entree.h"
#include "fenprincipale.h"

qwidget_onglet_entree::qwidget_onglet_entree()
{

    // Varialble ----------------------------------
    m_gridlayout_pp = new QGridLayout;
    m_label_date = new QLabel;
    m_dateEdit_date_entree = new QDateEdit;
    m_label_ref_entre = new QLabel;
    m_label_ref_entre_from_db = new QLabel;
    m_label_depot = new QLabel;
    m_lineEdit_depot = new QLineEdit;
    m_label_rayon = new QLabel;
    m_lineEdit_rayon = new QLineEdit;
    m_hboxlayout_date = new QHBoxLayout;
    m_hboxlayout_ref = new QHBoxLayout;
    m_hboxlayout_depot = new QHBoxLayout;
    m_hboxlayout_rayon = new QHBoxLayout;
    m_hboxlayout_etager = new QHBoxLayout;
    m_lineEdit_etagere = new QLineEdit;
    m_label_etagere = new QLabel;
    m_hboxlayout_commentaire = new QHBoxLayout;
    m_lineEdit_commentaire = new QLineEdit;
    m_label_commentaire = new QLabel;
    m_lineEdit_ref_article = new QLineEdit;
    m_lineEdit_designation = new QLineEdit;
    m_lineEdit_prix_unitaire = new QLineEdit;
    m_lineEdit_quantite = new QLineEdit;
    m_lineEdit_unite = new QLineEdit;
    m_hboxlayout_quantite_unite_prix = new QHBoxLayout;
    m_lineEdit_famille = new QLineEdit;

    m_dialog_selection_produit = new dialogbox_selection_produit_entree;
    m_dialogbox_modifier_entree = new dialogbox_modifier_entree;
    //----------------------------------------------
    m_label_date->setText(tr("Date"));
    m_dateEdit_date_entree->setDate(QDate::currentDate());
    m_dateEdit_date_entree->setCalendarPopup(true);

    m_label_ref_entre->setText(tr("Reference"));
    m_label_ref_entre_from_db->setText(tr("ref"));

    m_label_depot->setText(tr("Dépôt"));

    m_label_rayon->setText(tr("Rayon"));

    m_hboxlayout_date->addWidget(m_label_date);
    m_hboxlayout_date->addWidget(m_dateEdit_date_entree);

    // Hbox_ref ------------------------------------------
    m_hboxlayout_ref->addWidget(m_label_ref_entre);
    m_hboxlayout_ref->addWidget(m_label_ref_entre_from_db);    

    // Hbox_Depot ----------------------------------
    m_hboxlayout_depot->addWidget(m_label_depot);
    m_hboxlayout_depot->addWidget(m_lineEdit_depot);
    completer_lineEdit(m_lineEdit_depot,"Table_Depot","nom_depot");

    // Hbox_Rayon -----------------------------------
    m_hboxlayout_rayon->addWidget(m_label_rayon);
    m_hboxlayout_rayon->addWidget(m_lineEdit_rayon);
    completer_lineEdit(m_lineEdit_rayon,"Table_Rayon","Ref_Rayon");

    // Hbox_Etagere ---------------------------------
    m_hboxlayout_etager->addWidget(m_label_etagere);
    m_label_etagere->setText(tr("Etagère"));
    m_hboxlayout_etager->addWidget(m_lineEdit_etagere);
    completer_lineEdit(m_lineEdit_etagere,"Table_Etagere","nom_etagere");

    m_hboxlayout_commentaire->addWidget(m_label_commentaire);
    m_label_commentaire->setText(tr("Commentaire"));
    m_hboxlayout_commentaire->addWidget(m_lineEdit_commentaire);
    m_lineEdit_ref_article->setPlaceholderText(tr("Réfference article"));
    completer_lineEdit(m_lineEdit_ref_article,"Table_Produit","CodeProduit");

    m_lineEdit_designation->setPlaceholderText(tr("Designation"));

    // Hbox_Fournisseur -----------------------------------------
    m_lineEdit_fournisseur = new QLineEdit;
    m_label_fournisseur = new QLabel;

    m_label_fournisseur->setText(tr("Fournisseur"));
    m_lineEdit_fournisseur->setPlaceholderText(tr("Nom fournisseur"));

    // Quantité unité Prix fournisseur  ---------------------------------------
    m_lineEdit_quantite->setPlaceholderText(tr("Quantité"));

    // Permet la saisie de chiffre uniquement/ de 1 a 999 digit
    QRegExp rx("-?\\d{1,999}");
    QValidator * validator = new QRegExpValidator(rx,this);
    m_lineEdit_quantite->setValidator(validator);

    m_lineEdit_unite->setPlaceholderText(tr("Unité"));
    completer_lineEdit(m_lineEdit_unite,"Table_Unite","Unites");

    m_lineEdit_prix_unitaire->setPlaceholderText(tr("P.U"));
    m_lineEdit_prix_unitaire->setValidator(validator);


    m_hboxlayout_quantite_unite_prix->addWidget(m_lineEdit_quantite);

    m_hboxlayout_quantite_unite_prix->addWidget(m_lineEdit_unite);
//    QRegExp regUnit("[^a-zA-Z]\\d\\s");
//    QValidator * validator_unit = new QRegExpValidator(regUnit,this);
//    m_lineEdit_unite->setValidator(validator_unit);

    m_hboxlayout_quantite_unite_prix->addWidget(m_lineEdit_prix_unitaire);
    m_hboxlayout_quantite_unite_prix->addWidget(m_lineEdit_fournisseur);
    completer_lineEdit(m_lineEdit_fournisseur,"Table_Fournisseur","Raison_sociale");

    // PushButton ---------------------------------------------
    m_pushbutton_enregistrer = new QPushButton(tr("Enregistrer"));
    m_pushbutton_modifier = new QPushButton(tr("Modifier"));
    m_pushbutton_supprimer = new QPushButton(tr("Supprimer"));
    m_pushbutton_annuler = new QPushButton(tr("Annuler"));
    m_hboxlayout_puhsbutton = new QHBoxLayout;

    m_hboxlayout_puhsbutton->addWidget(m_pushbutton_enregistrer);
//    m_hboxlayout_puhsbutton->addWidget(m_pushbutton_modifier);
//    m_hboxlayout_puhsbutton->addWidget(m_pushbutton_annuler);
//    m_hboxlayout_puhsbutton->addWidget(m_pushbutton_supprimer);

    // ---------------------------------------------------
    // setPlaceholderText permet de créer le text gris à l'interieur du lineEdit
    m_lineEdit_famille->setPlaceholderText(tr("Famille d'article"));

    // TableView_entree-----------------------------------
    m_tableview_entree = new QTableView;    
    load_table_Entree();
    // permet de selectionner la ligne entière
    m_tableview_entree->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Groupebox filtre -------------------------------------------
    m_groupbox_filtre = new QGroupBox;
    m_gridlayout_filtre = new QGridLayout;
    m_hboxlayout_filtre_date = new QHBoxLayout;
    m_dateEdit_date_initial_filtre = new QDateEdit;
    m_dateEdit_date_finale_filtre = new QDateEdit;
    m_label_filtre_date_de = new QLabel;
    m_label_filtre_date_a = new QLabel;
    m_hboxlayout_filtre_famille_designation = new QHBoxLayout;
    m_lineEdit_filtre_Famille = new QLineEdit;
    m_lineEdit_filtre_designation = new QLineEdit;
    m_hboxlayout_filtre_boutton = new QHBoxLayout;
    m_pushbutton_filtre_valider = new QPushButton(tr("Valider"));
    m_pushbutton_filtre_effacer = new QPushButton(tr("Effacer"));


    m_groupbox_filtre->setLayout(m_gridlayout_filtre);
    m_groupbox_filtre->setTitle(tr("Filtre"));
    m_gridlayout_filtre->addLayout(m_hboxlayout_filtre_date,0,0);
    m_hboxlayout_filtre_date->addWidget(m_label_filtre_date_de);
    m_label_filtre_date_de->setText(tr("De "));
    m_hboxlayout_filtre_date->addWidget(m_dateEdit_date_initial_filtre);
    m_dateEdit_date_initial_filtre->setCalendarPopup(true);
    m_dateEdit_date_initial_filtre->setDate(QDate::currentDate());
    m_hboxlayout_filtre_date->addWidget(m_label_filtre_date_a);
    m_label_filtre_date_a->setText(tr(" à "));
    m_hboxlayout_filtre_date->addWidget(m_dateEdit_date_finale_filtre);
    m_dateEdit_date_finale_filtre->setCalendarPopup(true);
    m_dateEdit_date_finale_filtre->setDate(QDate::currentDate());

    m_gridlayout_filtre->addLayout(m_hboxlayout_filtre_famille_designation,0,1);
    m_lineEdit_filtre_Famille->setPlaceholderText(tr("Famille"));
    completer_lineEdit(m_lineEdit_famille,"Table_Produit","Categorie");

    m_hboxlayout_filtre_famille_designation->addWidget(m_lineEdit_filtre_Famille);
    m_hboxlayout_filtre_famille_designation->addWidget(m_lineEdit_filtre_designation);
    m_lineEdit_filtre_designation->setPlaceholderText(tr("Désigantion"));
    completer_lineEdit(m_lineEdit_designation,"Table_Produit","NomProduit");

    m_gridlayout_filtre->addLayout(m_hboxlayout_filtre_boutton,0,4,1,1);
    m_hboxlayout_filtre_boutton->addWidget(m_pushbutton_filtre_valider);
    m_hboxlayout_filtre_boutton->addWidget(m_pushbutton_filtre_effacer);

    /*
     * Definir le contextMenu du tableview
     */
    m_tableview_entree->setContextMenuPolicy(Qt::CustomContextMenu);


    //---------------------------------------------
    m_gridlayout_pp->addLayout(m_hboxlayout_date,1,0,1,2);
    m_gridlayout_pp->addLayout(m_hboxlayout_ref,2,0,1,2);
    m_gridlayout_pp->addLayout(m_hboxlayout_depot,1,2,1,8,Qt::AlignLeft);
    m_gridlayout_pp->addLayout(m_hboxlayout_rayon,2,2,1,8);
    m_gridlayout_pp->addLayout(m_hboxlayout_etager,1,10,1,6,Qt::AlignLeft);
    m_gridlayout_pp->addLayout(m_hboxlayout_commentaire,2,10,1,6);
    m_gridlayout_pp->addWidget(m_lineEdit_ref_article,3,0,1,2);
    m_gridlayout_pp->addWidget(m_lineEdit_famille,3,2,1,2);
    m_gridlayout_pp->addWidget(m_lineEdit_designation,3,4,1,7);
    m_gridlayout_pp->addLayout(m_hboxlayout_quantite_unite_prix,3,11,1,5);
    m_gridlayout_pp->addLayout(m_hboxlayout_puhsbutton,4,15,1,1);
    m_gridlayout_pp->addWidget(m_groupbox_filtre,0,0,1,16);
    m_gridlayout_pp->addWidget(m_tableview_entree,5,0,13,16);

    this->setLayout(m_gridlayout_pp);



    // -----------  SLOT CONNECTION -----------------
    connect(m_lineEdit_ref_article,SIGNAL(textChanged(QString)),this,SLOT(on_text_change_lineEdit_Ref()));
    connect(m_lineEdit_designation,SIGNAL(textChanged(QString)),this,SLOT(on_text_change_lineEdit_Designation()));
    connect(m_pushbutton_enregistrer,SIGNAL(clicked(bool)),this,SLOT(on_click_bt_valider()));
    connect(m_tableview_entree,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(contextMenu(QPoint)));
}

void qwidget_onglet_entree::load_table_Entree()
{

    /*
     * Permet de remplir le tableView avec la Table_Entrée de la base de donnée.
     */
    QSqlQuery qry;
    qry.prepare("SELECT Ref_entree, Famille, Designation, Quantite, Unite,Prix_unitaire, Montant, Depot,Etagere , Rayon, Commentaire FROM Table_entree");
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    m_tableview_entree->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("Réfferences"),Qt::DisplayRole);
    model->setHeaderData(1,Qt::Horizontal,tr("Familles"),Qt::DisplayRole);
    model->setHeaderData(2,Qt::Horizontal,tr("Designations"),Qt::DisplayRole);
    model->setHeaderData(3,Qt::Horizontal,tr("Quantité"),Qt::DisplayRole);
    model->setHeaderData(4,Qt::Horizontal,tr("Unité"),Qt::DisplayRole);
    model->setHeaderData(5,Qt::Horizontal,tr("Prix Unitaire"),Qt::DisplayRole);
    model->setHeaderData(6,Qt::Horizontal,tr("Montant"),Qt::DisplayRole);
    model->setHeaderData(7,Qt::Horizontal,tr("Dépôt"),Qt::DisplayRole);
    model->setHeaderData(8,Qt::Horizontal,tr("Etagère"),Qt::DisplayRole);
    model->setHeaderData(9,Qt::Horizontal,tr("Rayon"),Qt::DisplayRole);
    model->setHeaderData(10,Qt::Horizontal,tr("Commentaire"),Qt::DisplayRole);

    m_tableview_entree->setStyleSheet("QHeaderView::section {background-color:#D2691E ; color: white;  }");

    m_tableview_entree->setColumnWidth(0,160);
    m_tableview_entree->setColumnWidth(1,165);
    m_tableview_entree->setColumnWidth(2,500);

    m_tableview_entree->verticalHeader()->hide();
}

void qwidget_onglet_entree::load_label_ref_entree(QLabel *label, const char *nom_table, const char *id, const char *prefix)
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

void qwidget_onglet_entree::completer_lineEdit(QLineEdit * line_edit, const char * table_bd , const char * nom_colonne)
{
    /*
     * Permet de créer des proposition sur les lineEdit suivant le carcactere saisie
     * dans le lineEdit.
     * line_edit = nom du lineEdit dans l'application
     * table_bd = nom de la table dans la base de donnée
     * nom_colonne = nom du colonne de la table dans la base de donnée
     */
    QSqlQuery qry;
    QString nom_table = QString(table_bd);
    QString nom_colonne_to_string = QString(nom_colonne);    
    qry.prepare("SELECT "+nom_colonne_to_string+" FROM "+nom_table+" ");
    qry.exec();
    if (!qry.exec()){
        qDebug()<<tr("Erreur execution qry fonction completer_lineEdit")<<qry.lastError();
    }else {
        QStringList list_value;
        while (qry.next()) {
            QString value = qry.value(0).toString();
            list_value.append(value);
            list_value.removeDuplicates();
        }
        QCompleter * completer = new QCompleter(list_value);
        line_edit->setCompleter(completer);
        completer->setCompletionMode(QCompleter::PopupCompletion);
        completer->setModelSorting(QCompleter::UnsortedModel);
        completer->setFilterMode(Qt::MatchStartsWith);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
    }

}

void qwidget_onglet_entree::auto_complete_by_ref()
{
    /*
     * Permet de remplir automatiquement la categorie et le designation suivant
     * la refference choisit
     */
    QString code = m_lineEdit_ref_article->text();
    QVector<QString> cat_designation ;
    QSqlQuery qry;
    qry.prepare("SELECT NomProduit , Categorie FROM Table_Produit WHERE CodeProduit = '"+code+"' ");
    qry.exec();
    if (!qry.exec()){
        qDebug()<<tr("Erreur execution qry auto_complete_by_ref")<<qry.lastError();
    }else {
        while (qry.next()) {
            QString value_0 = qry.value(0).toString();
            cat_designation.append(value_0);
            QString value_1 = qry.value(1).toString();
            cat_designation.append(value_1);
        }
        if (cat_designation.size() !=0 ){
            m_lineEdit_famille->setText(cat_designation[1]);
            m_lineEdit_designation->setText(cat_designation[0]);
        }
    }
    if (m_lineEdit_ref_article->text().isEmpty()){
        m_lineEdit_famille->clear();
        m_lineEdit_designation->clear();
    }
}

void qwidget_onglet_entree::auto_complete_by_Designation()
{

    /*
     * Permet de remplir automatiquement la reference et le designation
     * suivant la designation saisie
     */
    QString NomProduit = m_lineEdit_designation->text();
    QVector<QString> ref_famille;

    QSqlQuery * qry_designation = new QSqlQuery;
    qry_designation->prepare("SELECT CodeProduit , Categorie FROM Table_Produit WHERE NomProduit = '"+NomProduit+"' ");
    qry_designation->exec();
    if (!qry_designation->exec()){
        qDebug()<<tr("Erreur execution qry fonction auto_complete_by_Designation")<<qry_designation->lastError();
    }else {
        QString value_codeProduit;
        QString value_Categorie;
        while (qry_designation->next()) {

            value_codeProduit = qry_designation->value(0).toString();
            ref_famille.append(value_codeProduit);
            value_Categorie = qry_designation->value(1).toString();
            ref_famille.append(value_Categorie);
        }
        if (ref_famille.size() == 2){
            m_lineEdit_famille->setText(ref_famille[1]);
            m_lineEdit_ref_article->setText(ref_famille[0]);

        }else if (ref_famille.size() > 2) {
            QStringList list_famille_filtrer;
            for (int i = 0 ; i < ref_famille.size() ; ++i){
                i = i+1;
                list_famille_filtrer.append(ref_famille[i]);
            }
            QCompleter * cat_completer = new QCompleter(list_famille_filtrer);
            m_lineEdit_famille->setCompleter(cat_completer);
            cat_completer->setCompletionMode(QCompleter::PopupCompletion);
            cat_completer->setModelSorting(QCompleter::UnsortedModel);
            cat_completer->setFilterMode(Qt::MatchStartsWith);
            cat_completer->setCaseSensitivity(Qt::CaseInsensitive);
        }
        if (m_lineEdit_designation->text().isEmpty()){
            m_lineEdit_ref_article->clear();
            m_lineEdit_designation->clear();
        }
    }
}

void qwidget_onglet_entree::execut_validation()
{
    /*
     * Permet de colecter les donnée saisies et de les envoyer dans la basse de donnée
     */
    QString Depot = m_lineEdit_depot->text();
    QString Etagere = m_lineEdit_etagere->text();
    QString Rayon = m_lineEdit_rayon->text();
    QString Commentaire = m_lineEdit_commentaire->text();
    QString Ref_entree = m_label_ref_entre_from_db->text();
    QString Ref_article = m_lineEdit_ref_article->text();
    QString Famille = m_lineEdit_famille->text();
    QString Designation = m_lineEdit_designation->text();
    QString Quantite = m_lineEdit_quantite->text();
    QString Unite = m_lineEdit_unite->text();
    QString Prix_unitaire = m_lineEdit_prix_unitaire->text();
    QString fournisseur = m_lineEdit_fournisseur->text();
    QString date_entree = m_dateEdit_date_entree->date().toString("dd/mm/yyyy");

    int montant_int = m_lineEdit_quantite->text().toInt() * m_lineEdit_prix_unitaire->text().toInt();
    QString Montant = QString::number(montant_int);

    qDebug()<<Montant;

    QSqlQuery qry;
    qry.prepare("INSERT INTO Table_Entree (Ref_entree , Famille, Ref_article , Designation , Quantite , Unite, Prix_unitaire , Montant , date_entree, Depot , Etagere , Rayon , fournisseur , Commentaire ) VALUES ( :Ref_entree , :Famille, :Ref_article , :Designation , :Quantite , :Unite, :Prix_unitaire , :Montant , :date_entree, :Depot , :Etagere , :Rayon , :fournisseur , :Commentaire)");
    qry.exec();
    qry.bindValue(":Ref_entree",Ref_entree);
    qry.bindValue(":Famille",Famille);
    qry.bindValue(":Ref_article",Ref_article);
    qry.bindValue(":Designation",Designation);
    qry.bindValue(":Quantite",Quantite);
    qry.bindValue(":Unite",Unite);
    qry.bindValue(":Prix_unitaire",Prix_unitaire);
    qry.bindValue(":Montant",Montant);
    qry.bindValue(":date_entree",date_entree);
    qry.bindValue(":Depot",Depot);
    qry.bindValue(":Etagere",Etagere);
    qry.bindValue(":Rayon",Rayon);
    qry.bindValue(":fournisseur",fournisseur);
    qry.bindValue(":Commentaire",Commentaire);


    if (!qry.exec()){
        qDebug()<<tr("Erreur ")<<qry.lastError();
    }

    load_table_Entree();
    reinitialiser_saisie_entree();
    load_label_ref_entree(m_label_ref_entre_from_db,"Table_Entree","id_ref","EN");

}

void qwidget_onglet_entree::reinitialiser_saisie_entree()
{
    /*
     * effacer tout les données qui vient d'etre saisie
     */
    m_lineEdit_depot->clear();
    m_lineEdit_rayon->clear();
    m_lineEdit_etagere->clear();
    m_lineEdit_commentaire->clear();
    m_lineEdit_ref_article->clear();
    m_lineEdit_famille->clear();
    m_lineEdit_designation->clear();
    m_lineEdit_prix_unitaire->clear();
    m_lineEdit_unite->clear();
    m_lineEdit_fournisseur->clear();
    m_lineEdit_quantite->clear();
}

void qwidget_onglet_entree::value_required(const char * txt)
{
    QMessageBox msg;
    QString msg_txt = QString(txt);
    msg.setText(msg_txt);
    msg.setIcon(QMessageBox::Information);
    msg.setDefaultButton(QMessageBox::Ok);
    msg.exec();
}

void qwidget_onglet_entree::keyPressEvent(QKeyEvent *event)
{
    /*
     * Permet d'executer une fonction par l'appuis sur une boutton du clavier
     */

    // Permet d'executer la validation par l'appuis sur le boutton Entree ou Return du clavier
    if( event->key() == Qt::Key_Enter  || event->key() == Qt::Key_Return){
        if (m_lineEdit_depot->text().isEmpty() || m_lineEdit_etagere->text().isEmpty() ||
                m_lineEdit_rayon->text().isEmpty() || m_lineEdit_ref_article->text().isEmpty() ||
                m_lineEdit_famille->text().isEmpty() || m_lineEdit_designation->text().isEmpty() ||
                m_lineEdit_quantite->text().isEmpty() || m_lineEdit_unite->text().isEmpty() ||
                m_lineEdit_prix_unitaire->text().isEmpty() || m_lineEdit_fournisseur->text().isEmpty()){
            value_required("Une ou plusieurs valeur obligatoire manquante");
        }else {
            execut_validation();
        }
    }
}


// --------------SLOTS -----------------------------------
void qwidget_onglet_entree::on_text_change_lineEdit_Ref()
{
    /*
     * Remplir automatiquement la famille et le designation du produit suivant
     * la reference saisie
     */
    auto_complete_by_ref();
}

void qwidget_onglet_entree::on_text_change_lineEdit_Designation()
{
    /*
     * Remplir automatiquement la refférence et la famille de l'article suivant la designation
     * saisie
     */
    auto_complete_by_Designation();
}

void qwidget_onglet_entree::on_click_bt_valider()
{
    /*
     * click sur le bouton Enregistrer.
     * -Veriffier s'il y a des valeur manquante. s'il y à des valeurs manquante
     * alor executer la fonction value_required, qui ouvre le dialog box
     * si non, executer la fonction execut_validation
     */
    if (m_lineEdit_depot->text().isEmpty() || m_lineEdit_etagere->text().isEmpty() ||
            m_lineEdit_rayon->text().isEmpty() || m_lineEdit_ref_article->text().isEmpty() ||
            m_lineEdit_famille->text().isEmpty() || m_lineEdit_designation->text().isEmpty() ||
            m_lineEdit_quantite->text().isEmpty() || m_lineEdit_unite->text().isEmpty() ||
            m_lineEdit_prix_unitaire->text().isEmpty() || m_lineEdit_fournisseur->text().isEmpty()){
        value_required("Une ou plusieurs valeur obligatoire manquante");
    }else {
        execut_validation();
    }
}

void qwidget_onglet_entree::contextMenu(QPoint point)
{
    /*
     * Menu contextuel, qui contient les modification; suppréssion des entrée
     */
    QModelIndex index = m_tableview_entree->indexAt(point); // Permet de recupérer la potision selectionner
    QVector<QString> selected_line_data;

    // Création du contextMenu
    QMenu *menu = new QMenu(m_tableview_entree);
    QAction *actionModif = new QAction(tr("Modifier"),m_tableview_entree);
    QAction *actionSupprimer = new QAction(tr("Supprimer"),m_tableview_entree);
    QAction *actionCopy = new QAction(tr("Copier"),m_tableview_entree);
    menu->addAction(actionCopy);
    menu->addAction(actionModif);
    menu->addAction(actionSupprimer);

    // Déffinition du position d'affichage du contextMenu
    menu->popup(m_tableview_entree->viewport()->mapToGlobal(point));

    // Se deplacer sur la première ligne du ligne selectionner
    QString ref_selected_row = m_tableview_entree->model()->index(index.row(),0).data().toString();

    // Recupérer la ligne selectionner dans la basse de donnéer pour le modification ou suppréssion
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Table_Entree WHERE Ref_entree = '"+ref_selected_row+"' ");
    qry.exec();
    if(!qry.exec()){
        qDebug()<<tr("Erreur execution qry dans la fonction contextMenu ")<<qry.lastError();
    }else {
        qDebug()<<ref_selected_row;
        while (qry.next()) {
            for(int i=1 ; i<15 ; ++i){ // 15 = nombre de colone dans la Table_Entree
                QString value = qry.value(i).toString();
                selected_line_data.append(value);
            }
        }
    }
    // Test si la valeur du vecteur n'est pas vide
    if (!selected_line_data.isEmpty()){
        qDebug()<<selected_line_data;
    }

    // Connection slot avec les actions du contextMenu
    connect(actionModif,SIGNAL(triggered(bool)),this,SLOT(on_click_action_modifier()));
}

void qwidget_onglet_entree::on_click_action_modifier()
{
    /*
     * Permet d'ouvrir la boite de dialogue pour de modification des entrées
     * ne pas oublier d'inclure le fichier dialogbox_modifier_entree.h dans
     * le fichier qwidget_onglet_entree.h et de créer une instance m_dialogbox_modifier_entree
     * le dialog box s'ouvre par le click sur l'action Modifier du contextMenu
     */
    m_dialogbox_modifier_entree->exec();
}
