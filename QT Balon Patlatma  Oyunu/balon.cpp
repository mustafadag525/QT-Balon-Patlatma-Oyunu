#include "balon.h"
#include <QRandomGenerator>
#include <QDebug>
balon::balon(QWidget *parent, QLabel *k_label, int *k_sayisi, QLabel *v_label, int *v_sayisi) : QPushButton(parent)
{
    kacan_label = k_label;
    kacan_sayisi = k_sayisi;
    x = QRandomGenerator::global()->bounded(15, 1330);
    y = 90;
    setFlat(true);
    setGeometry(x, y, 65, 65);
    setIcon(QIcon(":/resimler/resimler/"+QString::number(QRandomGenerator::global()->bounded(7))+".jpg"));
    setIconSize(QSize(65, 65));
    timer = new QTimer();
    timer->callOnTimeout(this, &balon::ilerle);
    connect(this, &balon::clicked, [this, v_label, v_sayisi](){
       vuruldu(v_label, v_sayisi);
    });
    show();
    ilerle();
}

void balon::ilerle(){
    if (y >= 725){
        kacan_label->setNum(++*(kacan_sayisi));
        delete this;
    } else {
        y += 2;
        setGeometry(x, y, 65, 65);
        timer->start(10);
    }
}

void balon::vuruldu(QLabel *vurulan_label, int *vurulan_sayisi){
    vurulan_label->setNum(++*(vurulan_sayisi));
    setIcon(QIcon(":/resimler/resimler/patlama.jpg"));
    setIconSize(QSize(65, 65));
    timer->callOnTimeout(this, &balon::deleteLater);
    timer->start(1000);
}
