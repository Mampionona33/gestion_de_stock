#include "dialogbox_detail_tableview.h"

dialogbox_detail_tableView::dialogbox_detail_tableView(QDialog * parent):QDialog (parent)
{
    /*
     * dialogbox permetant d'afficher les details sur la ligne selectionner
     * dans le tableView dans l'onglet Annuaire du fournisseur/Client
     */
    // Variable -------------------------------------------
    m_gridlayout_dialogBox_Detail = new QGridLayout;
    m_textEdit_dialogBox_detail = new QTextEdit;
    m_pushButton_dialogBox_detail = new QPushButton(tr("Fermer"));
    // -----------------------------------------------------
    m_textEdit_dialogBox_detail->setReadOnly(true);
    m_textEdit_dialogBox_detail->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);


    m_gridlayout_dialogBox_Detail->addWidget(m_textEdit_dialogBox_detail,0,0,10,3);
    m_gridlayout_dialogBox_Detail->addWidget(m_pushButton_dialogBox_detail,11,1,1,1);
    this->setLayout(m_gridlayout_dialogBox_Detail);

    connect(m_pushButton_dialogBox_detail,SIGNAL(clicked(bool)),this,SLOT(close()));
}
