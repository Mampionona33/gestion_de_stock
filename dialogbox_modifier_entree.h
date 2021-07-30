#ifndef DIALOGBOX_MODIFIER_ENTREE_H
#define DIALOGBOX_MODIFIER_ENTREE_H

#include <QDialog>
#include <QGridLayout>
#include <QFormLayout>
#include <QDateEdit>


class dialogbox_modifier_entree : public QDialog
{
public:
    dialogbox_modifier_entree(QDialog * parent = nullptr);

    QGridLayout * m_gridlayout_ppl;

};

#endif // DIALOGBOX_MODIFIER_ENTREE_H
