#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QStyleOptionTab>
#include <QStylePainter>
#include <QTabWidget>
#include <QTabBar>
#include <QWidget>

class TabBar : public QTabBar
{
    /*
     * Permet de colorer chaque tab par des couleurs différents
     */
public:
    TabBar(const QHash<QString, QColor> &colors, QWidget *parent =0 ):QTabBar(parent){
        mColors = colors;
    }
protected:
    void paintEvent(QPaintEvent */*event*/){
        QStylePainter painter(this);
        QStyleOptionTab opt;

        for(int i = 0; i< count() ; ++i){
            initStyleOption(&opt , i);
            if (mColors.contains(opt.text)){
                opt.palette.setColor(QPalette::Button, mColors[opt.text]);
            }
            painter.drawControl(QStyle::CE_TabBarTabShape,opt);
            painter.drawControl(QStyle::CE_TabBarTabLabel,opt);
        }
    }

private:
    QHash<QString, QColor> mColors;
};

class TabWidet : public QTabWidget
{
public:
    TabWidet(QWidget * parent = 0 ):QTabWidget(parent){
        QHash <QString, QColor> dict;

        dict["Article"] = QColor("#4169E1");
        dict["Mouvement d'Entrée"]  = QColor("#D2691E");
        dict["Mouvement de Vente"] = QColor("#B8860B");
        dict["Déplacement du stock"] = QColor("#20B2AA");
        dict["Annuaire"] = QColor("#A52A2A");
        dict["Dépense"] = QColor("#808000");
        dict["Stock"] = QColor("#483D8B");
        dict["Déplacement du stock"] = QColor("#696969");
        dict["Mouvement de transfert"] = QColor("#3CB371");
        dict["Devis"] = QColor("#CD853F");
        dict["Dépôts de stockage"] = QColor("#00BFFF");
        dict["paramètre"] = QColor("#4B0082");

        setTabBar(new TabBar(dict));
    }
};

#endif // TABWIDGET_H
