#include "dialogbox_suppr_ligne_tableview_tiers.h"

dialogBox_suppr_ligne_tableView_tiers::dialogBox_suppr_ligne_tableView_tiers()
{
    m_gridlayout = new QGridLayout;
    m_pushbutton_No = new QPushButton(tr("Annuler"));
    m_pushbutton_Ok = new QPushButton(tr("Valider"));
    m_hboxLayout = new QHBoxLayout;
    m_lablel_message = new QLabel;

    m_gridlayout->addWidget(m_lablel_message,0,0,Qt::AlignCenter);
    m_hboxLayout->addWidget(m_pushbutton_Ok);
    m_hboxLayout->addWidget(m_pushbutton_No);
    m_gridlayout->addLayout(m_hboxLayout,1,0,Qt::AlignCenter);

    this->setLayout(m_gridlayout);

    connect(m_pushbutton_No,SIGNAL(clicked(bool)),this,SLOT(reject()));
    connect(m_pushbutton_Ok,SIGNAL(clicked(bool)),this,SLOT(accept()));
}
