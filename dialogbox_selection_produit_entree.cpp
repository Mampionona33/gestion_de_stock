#include "dialogbox_selection_produit_entree.h"

dialogbox_selection_produit_entree::dialogbox_selection_produit_entree()
{
//    dataBase conn;
//    if(!conn.connOpen()){
//        qDebug()<<tr("Erreur ouverture base de donnée dialogbox_selection_produit_entree");
//    }
    m_gridlayout_pp = new QGridLayout;
    this->setLayout(m_gridlayout_pp);

//    m_mots_clef = new QString;
    m_ref = new QString;
    m_famille = new QString;

    m_tableview_article = new QTableView;
    m_tableview_article->setSelectionBehavior(QAbstractItemView::SelectRows);

    m_gridlayout_pp->addWidget(m_tableview_article);

    // CONNECTION -----------------------------------------
    connect(m_tableview_article,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_double_click_line_tablview()));

}

void dialogbox_selection_produit_entree::select_row(QString  &ref, QString &famille)
{
    QItemSelectionModel * selection = m_tableview_article->selectionModel();
    QList<QString> text ;
    QList<QString> value_text;
    QString value_ref,value_famille;
    if (m_tableview_article->focusWidget()){
        for (int i = 0 ; i <= m_tableview_article->model()->columnCount() - 1; ++ i){
            text.append(selection->selectedRows(i).value(0).data().toString());
        }
        QSqlQuery qry;
        qry.prepare("SELECT CodeProduit , Categorie FROM Table_Produit WHERE CodeProduit = '"+text[0]+"' ");
        if (!qry.exec()){
            qDebug()<<"Erreur execution qry"<<qry.lastError();
        }else {
            while (qry.next()) {
                value_ref = qry.value(0).toString();
                value_text.append(value_ref);
                value_famille = qry.value(1).toString();
                ref = value_ref;
                famille = value_famille;
            }            
        }
    }
    if (m_tableview_article->DoubleClicked){
        this->accept();
    }
}

// --------------- SLOT ---------------------------------------------

void dialogbox_selection_produit_entree::on_double_click_line_tablview()
{
    select_row(*m_ref, *m_famille);
}
