#ifndef DIALOGBOX_SUPPR_LIGNE_TABLEVIEW_TIERS_H
#define DIALOGBOX_SUPPR_LIGNE_TABLEVIEW_TIERS_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

class dialogBox_suppr_ligne_tableView_tiers : public QDialog
{
    Q_OBJECT
public:
    dialogBox_suppr_ligne_tableView_tiers();

    QPushButton * m_pushbutton_Ok;
    QPushButton * m_pushbutton_No;
    QLabel *m_lablel_message;    

private:
    QGridLayout * m_gridlayout;
    QHBoxLayout * m_hboxLayout;
};

#endif // DIALOGBOX_SUPPR_LIGNE_TABLEVIEW_TIERS_H
