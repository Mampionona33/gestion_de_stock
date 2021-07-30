#ifndef COMBOBOXUNITE_H
#define COMBOBOXUNITE_H

#include <QSqlQuery>
#include <QDebug>
#include "database.h"
#include <QComboBox>
#include <QString>
#include <QStringList>

class comboBoxUnite : public QComboBox
{
public:
    comboBoxUnite()
    {
        listeUnite();
    }

    void listeUnite(){
        dataBase conn;
        if ( !conn.connOpen()){
            qDebug()<< "Erreur connection à la base de donnée";
        }else {
            QSqlQuery qry;
            qry.prepare("SELECT Unites FROM Table_Unite");
            if (!qry.exec()){
                qDebug()<<"Erreur execution qry listeUnite class comboBoxUnite" <<qry.lastError();
            }else {
                QStringList liste_Unite;
                while (qry.next()) {
                    QString unite = qry.value(0).toString();
                    liste_Unite.append(unite);
                    liste_Unite.removeDuplicates();
                }
                this->addItem("");
                this->addItems(liste_Unite);                
            }
        }
    }
};

#endif // COMBOBOXUNITE_H
