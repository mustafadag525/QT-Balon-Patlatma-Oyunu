#ifndef BALON_H
#define BALON_H

#include <QLabel>
#include <QTimer>
#include <QPushButton>
class balon : public QPushButton
{
    Q_OBJECT
public:
    balon(QWidget *, QLabel *, int *, QLabel *, int *);
    QTimer *timer;
private:
    QLabel *kacan_label;
    int *kacan_sayisi, y, x;

public slots:
    void vuruldu(QLabel *, int*);
    void ilerle();

};

#endif // BALON_H
