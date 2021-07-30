#include "popupmodifierproduit.h"

popUpModifierProduit::popUpModifierProduit()
{
    /*
     * PopUp pour modifier les produits selectionner
     */
    //-----------VARIABLES-----------------------------------------
    m_hboxLayoutPopUpModifierProd = new QHBoxLayout;
    m_pushButtonAnnulerPopModifProd = new QPushButton(tr("Annuler"));
    m_pushButtonValiderPopModifProd = new QPushButton(tr("Valider"));
    m_gridLayoutPopUpModifProd = new QGridLayout;
    m_lineEditcatProdpopModif = new QLineEdit;
    m_lineEditnomProdpopModif = new QLineEdit;
    m_lineEditstkMinProdpopModif = new QSpinBox;
    m_formLayoutPopUpModif = new QFormLayout;
    m_labelCodeProdPopModif = new QLabel;
    m_comboBoxUnitProdPopModif = new comboBoxUnite;
    //---------------------------------------------------------

    //---------MISE EN FORME -------------------------------------------------------------------
    this->setWindowTitle(tr("Modifier Produit"));
    m_hboxLayoutPopUpModifierProd->addWidget(m_pushButtonValiderPopModifProd);
    m_hboxLayoutPopUpModifierProd->addWidget(m_pushButtonAnnulerPopModifProd);
    m_pushButtonValiderPopModifProd->setDefault(true);


    m_formLayoutPopUpModif->addRow(tr("Code :"), m_labelCodeProdPopModif);
    m_formLayoutPopUpModif->addRow(tr("Nom :"), m_lineEditnomProdpopModif);
    m_formLayoutPopUpModif->addRow(tr("Categorie :"), m_lineEditcatProdpopModif);
    m_formLayoutPopUpModif->addRow(tr("Stock Mini :"), m_lineEditstkMinProdpopModif);
    m_formLayoutPopUpModif->addRow(tr("Unité :"), m_comboBoxUnitProdPopModif);

    m_formLayoutPopUpModif->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    m_gridLayoutPopUpModifProd->addLayout(m_formLayoutPopUpModif,0,0);
    m_gridLayoutPopUpModifProd->addLayout(m_hboxLayoutPopUpModifierProd,1,0);

    this->setLayout(m_gridLayoutPopUpModifProd);

    //----------------SLOT ----------------------------------------------------------------------
    connect(m_pushButtonValiderPopModifProd,SIGNAL(clicked(bool)),this,SLOT(accept()));
    connect(m_pushButtonAnnulerPopModifProd,SIGNAL(clicked(bool)),this,SLOT(reject()));
    connect(m_lineEditnomProdpopModif,SIGNAL(textChanged(QString)),this,SLOT(completerLabelNomProd()));
    connect(m_lineEditcatProdpopModif,SIGNAL(textChanged(QString)),this,SLOT(completerLabelCatProd()));
}

void popUpModifierProduit::completerLabelNomProd()
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
            m_lineEditnomProdpopModif->setCompleter(mycompleter);
            mycompleter->setCompletionMode(QCompleter::PopupCompletion);
            mycompleter->setModelSorting(QCompleter::UnsortedModel);
            mycompleter->setFilterMode(Qt::MatchStartsWith);
            mycompleter->setCaseSensitivity(Qt::CaseInsensitive);
                }
}

void popUpModifierProduit::completerLabelCatProd()
{
    /*
     * Permet de donnée des propotitions durants la saisie
     * dans le QlineEdit NomProduit
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

            /*
             * permet de filtrer la liste des nom de produit dans le
             * lineEdit en fonction des caractères saisie dans ce dernier
             */
            QCompleter *mycompleter = new QCompleter(listNomProduit);
            m_lineEditcatProdpopModif->setCompleter(mycompleter);
            mycompleter->setCompletionMode(QCompleter::PopupCompletion);
            mycompleter->setModelSorting(QCompleter::UnsortedModel);
            mycompleter->setFilterMode(Qt::MatchStartsWith);
            mycompleter->setCaseSensitivity(Qt::CaseInsensitive);
        }
}

