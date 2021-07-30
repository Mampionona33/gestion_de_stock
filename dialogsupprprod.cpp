#include "dialogsupprprod.h"

/*
 * Permet de prevenir l'utilisateur avant la suppression
 * d'un produit selectionner dans le tableview de l'onglet
 * produit. connecter avec le slot du contexMenu du gridlayoutproduit
 */

dialogsupprProd::dialogsupprProd()
{
    // Varriables ---------------------------------------------------------------
    m_labelInfoSup = new QLabel;
    m_labelCodeProd = new QLabel;
    m_labelNomProd = new QLabel;
    m_pushButtonAnnulerSup = new QPushButton(tr("Annuler"));
    m_pushButtonValiderSup = new QPushButton(tr("Valider"));
    m_hboxLayout = new QHBoxLayout;
    m_gridlayout = new QGridLayout;
    //------------------------------------------------------------------------------
    m_hboxLayout->addWidget(m_pushButtonValiderSup);
    m_hboxLayout->addWidget(m_pushButtonAnnulerSup);

    m_gridlayout->addWidget(m_labelInfoSup,0,0,1,3);
    m_gridlayout->addWidget(m_labelCodeProd,0,3,1,1);
    m_gridlayout->addWidget(m_labelNomProd,0,4,1,1);
    m_gridlayout->addLayout(m_hboxLayout,1,2,1,1);
    this->setLayout(m_gridlayout);

    // SLOT----------------------------------------------------------------------
    connect(m_pushButtonAnnulerSup,SIGNAL(clicked(bool)),this,SLOT(reject()));
}
