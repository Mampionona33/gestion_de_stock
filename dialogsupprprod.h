#ifndef DIALOGSUPPRPROD_H
#define DIALOGSUPPRPROD_H

/*
 * Permet de prevenir l'utilisateur avant la suppression
 * d'un produit selectionner dans le tableview de l'onglet
 * produit.
 */
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

class dialogsupprProd : public QDialog
{
    Q_OBJECT
public:
    dialogsupprProd();

    QLabel * m_labelInfoSup;
    QLabel * m_labelCodeProd;
    QLabel * m_labelNomProd;
    QPushButton *m_pushButtonValiderSup;
    QPushButton *m_pushButtonAnnulerSup;
private:
    QHBoxLayout *m_hboxLayout;
    QGridLayout *m_gridlayout;
};

#endif // DIALOGSUPPRPROD_H
