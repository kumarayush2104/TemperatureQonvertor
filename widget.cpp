#include "widget.h"
#include <QDoubleValidator>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

const QString FAHRENHEIT_DISPLAY_MESSAGE = "Degree Fahrenheit: ";

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDoubleValidator *temperatureInputValidator = new QDoubleValidator();
    temperatureInputValidator -> setBottom(0.0);
    temperatureInputValidator -> setDecimals(2);

    this -> temperatureInput = new QLineEdit(this);
    temperatureInput -> setPlaceholderText("Enter temperature in Degree Celsius");
    temperatureInput -> setValidator(temperatureInputValidator);

    QPushButton *calculateButton = new QPushButton(this);
    calculateButton -> setText("Calculate");
    connect(calculateButton, SIGNAL(clicked(bool)), this, SLOT(calculate()));
    connect(temperatureInput, SIGNAL(returnPressed()), this, SLOT(calculate()));

    QHBoxLayout *inputContainer = new QHBoxLayout();
    inputContainer -> addWidget(temperatureInput);
    inputContainer -> addWidget(calculateButton);

    fahrenheitTemperature = new QLabel(this);
    fahrenheitTemperature -> setText(FAHRENHEIT_DISPLAY_MESSAGE);

    QVBoxLayout *mainWindow = new QVBoxLayout(this);
    mainWindow -> addLayout(inputContainer);
    mainWindow -> addWidget(fahrenheitTemperature);

    this-> setMaximumSize(this -> width(), this -> height());
}

void Widget::calculate() {
    if(temperatureInput -> hasAcceptableInput()) {
        float floatValueOfCelsius = this -> temperatureInput -> text().toFloat();
        float floatValueofFahrenheit = (floatValueOfCelsius * 9 / 5) + 32;
        this -> fahrenheitTemperature -> setText(FAHRENHEIT_DISPLAY_MESSAGE + QString::number(floatValueofFahrenheit));
    } else
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid Celsius temperature value.");
}

Widget::~Widget() {
    delete this -> temperatureInput;
    delete this -> fahrenheitTemperature;
}
