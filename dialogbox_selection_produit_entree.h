#ifndef DIALOGBOX_SELECTION_PRODUIT_ENTREE_H
#define DIALOGBOX_SELECTION_PRODUIT_ENTREE_H

#include <QDialog>
#include <QGridLayout>
#include <QTableView>
#include <QString>
#include <QSqlQuery>
#include <QModelIndex>
#include <QItemSelectionModel>
#include <QVector>

#include "database.h"

class dialogbox_selection_produit_entree : public QDialog
{
    Q_OBJECT
public:
    dialogbox_selection_produit_entree();
//    QString * m_mots_clef;
    QTableView * m_tableview_article;
    QString * m_ref;
    QString * m_famille;

    void select_row(QString &ref, QString &famille);

private:
    QGridLayout * m_gridlayout_pp;
public slots:
    void on_double_click_line_tablview();

};

#endif // DIALOGBOX_SELECTION_PRODUIT_ENTREE_H
