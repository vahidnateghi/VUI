#include "vLed.h"
#include "ui_vLed.h"
#include <QPainter>

vLed::vLed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vLed)
{
    m_AddrLedGray0 = ":/VUI/Led0/LedGray0";
    m_AddrLedGray1 = ":/VUI/Led1/LedGray1";
    m_AddrLedGreen0 = ":/VUI/Led0/LedGreen0";
    m_AddrLedGreen1 = ":/VUI/Led1/LedGreen1";
    m_AddrLedRed0 = ":/VUI/Led0/LedRed0";
    m_AddrLedRed1 = ":/VUI/Led1/LedRed1";
    m_AddrLedYellow0 = ":/VUI/Led0/LedYellow0";
    m_AddrLedYellow1 = ":/VUI/Led1/LedYellow1";
    m_AddrLedSelected = "";

    ui->setupUi(this);
}

void vLed::setLedState(Enum_LEDState State)
{
    switch (State) {
    case Led_Gray0: m_AddrLedSelected = m_AddrLedGray0; break;
    case Led_Gray1: m_AddrLedSelected = m_AddrLedGray1; break;
    case Led_Green0: m_AddrLedSelected = m_AddrLedGreen0; break;
    case Led_Green1: m_AddrLedSelected = m_AddrLedGreen1; break;
    case Led_Red0: m_AddrLedSelected = m_AddrLedRed0; break;
    case Led_Red1: m_AddrLedSelected = m_AddrLedRed1; break;
    case Led_Yellow0: m_AddrLedSelected = m_AddrLedYellow0; break;
    case Led_Yellow1: m_AddrLedSelected = m_AddrLedYellow1; break;
    }

    update();
}

vLed::~vLed()
{
    delete ui;
}

void vLed::paintEvent(QPaintEvent *e)
{
    if( m_AddrLedSelected == "" )
        return;

    QPainter painter(this);
    painter.setRenderHints( QPainter::HighQualityAntialiasing, true );
    QPixmap ledPic = QPixmap( m_AddrLedSelected).scaled(size(), Qt::KeepAspectRatio );

    painter.drawPixmap( ( size().width() - ledPic.width() ) / 2.0 ,
                        -( size().height() - ledPic.height() ) / 2.0,
                        ledPic );

    QWidget::paintEvent(e);
}
