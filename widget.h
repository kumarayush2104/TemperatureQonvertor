#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel *fahrenheitTemperature;
    QLineEdit *temperatureInput;

public slots:
    void calculate();

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
