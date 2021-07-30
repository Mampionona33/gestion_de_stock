#ifndef POPUPMODIFIERPRODUIT_H
#define POPUPMODIFIERPRODUIT_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QObject>
#include <QGridLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QCompleter>
#include <QSpinBox>

#include "comboboxunite.h"

class popUpModifierProduit : public QDialog
{
    Q_OBJECT
public:
    popUpModifierProduit();


    QLineEdit *m_lineEditnomProdpopModif;
    QLineEdit *m_lineEditcatProdpopModif;
    QSpinBox *m_lineEditstkMinProdpopModif;
    QFormLayout *m_formLayoutPopUpModif;
    QLabel *m_labelCodeProdPopModif;
    comboBoxUnite *m_comboBoxUnitProdPopModif;
    QPushButton *m_pushButtonValiderPopModifProd;
    QPushButton *m_pushButtonAnnulerPopModifProd;


private:
    QHBoxLayout *m_hboxLayoutPopUpModifierProd;
    QGridLayout *m_gridLayoutPopUpModifProd;

public slots:
    void completerLabelNomProd();
    void completerLabelCatProd();
};

#endif // POPUPMODIFIERPRODUIT_H
