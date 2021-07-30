#include "dialogbox_modifier_entree.h"

dialogbox_modifier_entree::dialogbox_modifier_entree(QDialog * parent):QDialog(parent)
{
    m_gridlayout_ppl = new QGridLayout;
    this->setLayout(m_gridlayout_ppl);
}
