#include <QApplication>
#include <QStyleFactory>
#include <QShortcut>
#include <QQuickItem>

#include "fenprincipale.h"
/*
 * Programme principale
 */
int main(int argc, char * argv[1]){
    QApplication application(argc,argv);
    QApplication::setStyle(QStyleFactory::create("fusion")); // Permet de donnée une style generale à l'application
    fenPrincipale fen;
    fen.show();
    return application.exec();

}

