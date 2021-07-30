#ifndef DIALOGBOX_DETAIL_TABLEVIEW_H
#define DIALOGBOX_DETAIL_TABLEVIEW_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>


class dialogbox_detail_tableView : public QDialog
{
public:
    dialogbox_detail_tableView(QDialog * parent = 0);

    QTextEdit * m_textEdit_dialogBox_detail;
    QPushButton * m_pushButton_dialogBox_detail;
private:
    QGridLayout * m_gridlayout_dialogBox_Detail;
};

#endif // DIALOGBOX_DETAIL_TABLEVIEW_H
