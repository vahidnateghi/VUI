#ifndef VLED_H
#define VLED_H

#include <QWidget>
#include <QMovie>

enum Enum_LEDState
{
    Led_Gray0,
    Led_Gray1,
    Led_Green0,
    Led_Green1,
    Led_Red0,
    Led_Red1,
    Led_Yellow0,
    Led_Yellow1,
    Led_ToggleGreen1,
    Led_ToggleRed1,
    Led_ToggleYellow1
};

namespace Ui {
class vLed;
}

class vLed : public QWidget
{
    Q_OBJECT

public:
    explicit vLed(QWidget *parent = nullptr);

    void setLedState(Enum_LEDState State);

    ~vLed();

    int AnimationPercentSpeed() const;
    void setAnimationPercentSpeed(int AnimationPercentSpeed);

private:
    Ui::vLed *ui;

    QString m_AddrLedGray0;
    QString m_AddrLedGray1;
    QString m_AddrLedGreen0;
    QString m_AddrLedGreen1;
    QString m_AddrLedRed0;
    QString m_AddrLedRed1;
    QString m_AddrLedYellow0;
    QString m_AddrLedYellow1;
    QString m_AddrLedToggleGreen1;
    QString m_AddrLedToggleYellow1;
    QString m_AddrLedToggleRed1;
    QString m_AddrLedSelected;

    Enum_LEDState m_State;
    int m_AnimationPercentSpeed;
    QMovie *m_Movie;

protected:
    void paintEvent(QPaintEvent*e);
};

#endif // VLED_H
