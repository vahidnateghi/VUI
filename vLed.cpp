#include "vLed.h"
#include "ui_vLed.h"
#include <QPainter>
#include <QPixmap>

vLed::vLed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vLed)
{
    ui->setupUi(this);

    m_AddrLedGray0 = ":/VUI/Led0/LedGray0";
    m_AddrLedGray1 = ":/VUI/Led1/LedGray1";
    m_AddrLedGreen0 = ":/VUI/Led0/LedGreen0";
    m_AddrLedGreen1 = ":/VUI/Led1/LedGreen1";
    m_AddrLedRed0 = ":/VUI/Led0/LedRed0";
    m_AddrLedRed1 = ":/VUI/Led1/LedRed1";
    m_AddrLedYellow0 = ":/VUI/Led0/LedYellow0";
    m_AddrLedYellow1 = ":/VUI/Led1/LedYellow1";
    m_AddrLedToggleGreen1 = ":/VUI/LedToggle1/LedToggleGreen1";
    m_AddrLedToggleRed1 = ":/VUI/LedToggle1/LedToggleRed1";
    m_AddrLedToggleYellow1 = ":/VUI/LedToggle1/LedToggleYellow1";
    m_AddrLedSelected = "";

    m_AnimationPercentSpeed = 100;

    m_Movie = NULL;
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
    case Led_ToggleGreen1:
        m_AddrLedSelected = m_AddrLedToggleGreen1;
        if( m_Movie != NULL )
        {
            delete m_Movie ;
            m_Movie = NULL;
        }
        break;
    case Led_ToggleYellow1:
        m_AddrLedSelected = m_AddrLedToggleYellow1;
        if( m_Movie != NULL )
        {
            delete m_Movie ;
            m_Movie = NULL;
        }
        break;
    case Led_ToggleRed1:
        m_AddrLedSelected = m_AddrLedToggleRed1;
        if( m_Movie != NULL )
        {
            delete m_Movie ;
            m_Movie = NULL;
        }
        break;
    }

    m_State = State;

    update();
}

vLed::~vLed()
{
    delete ui;
}

int vLed::AnimationPercentSpeed() const
{
    return m_AnimationPercentSpeed;
}

void vLed::setAnimationPercentSpeed(int AnimationPercentSpeed)
{
    m_AnimationPercentSpeed = AnimationPercentSpeed;
}

void vLed::paintEvent(QPaintEvent *e)
{
    if( m_AddrLedSelected == "" )
        return;

    switch (m_State) {
    case Led_ToggleGreen1:
    case Led_ToggleRed1:
    case Led_ToggleYellow1:
        if( m_Movie == NULL )
        {
            m_Movie = new QMovie(m_AddrLedSelected);
            QSize tsize = m_Movie->scaledSize();
            tsize.scale(size(), Qt::KeepAspectRatio);

            m_Movie->setSpeed( m_AnimationPercentSpeed );
            m_Movie->setScaledSize( tsize );
            this->ui->lblGif->setMovie( m_Movie );
            m_Movie->start();
        }
        break;
    case Led_Gray0:
    case Led_Gray1:
    case Led_Green0:
    case Led_Green1:
    case Led_Red0:
    case Led_Red1:
    case Led_Yellow0:
    case Led_Yellow1:
        QPainter painter(this);
        painter.setRenderHints( QPainter::HighQualityAntialiasing, true );
        QPixmap ledPic = QPixmap( m_AddrLedSelected ).scaled(size(), Qt::KeepAspectRatio );

        painter.drawPixmap( ( size().width() - ledPic.width() ) / 2.0 ,
                            -( size().height() - ledPic.height() ) / 2.0,
                            ledPic );

        break;
    }

    QWidget::paintEvent(e);

}
