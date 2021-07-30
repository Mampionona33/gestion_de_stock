#include "database.h"


/*
 * A inclure dans le projet pour eviter erreur
 * undefinied reference to dataBase::dataBase()
 */

// constructeur
dataBase::dataBase()
{

}


// Fonction membre :
void dataBase::connClose()
{
    QSqlDatabase db;
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}
bool dataBase::connOpen()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Mampionona1/Traitement/Utilitaire/Nouveau dossier/Tp qt/gestion_de_stock/base_de_donnee .sqlite");
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        return false;
    }
    else {
       // qDebug()<<"data base connected";
        return true;
    }
}

