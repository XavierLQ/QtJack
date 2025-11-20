#include "BlackjackWindow.h"
#include "BlackjackViewModel.h"
#include "Strings.h"
#include "Constants.h"
#include "Styles.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

BlackjackWindow::BlackjackWindow(QWidget* parent)
    : QWidget(parent)
    , m_vm(new BlackjackViewModel(this))
{
    setWindowTitle(Strings::WINDOW_TITLE);

    auto* root = new QVBoxLayout(this);
    root->setSpacing(Styles::ROOT_SPACING);
    root->setContentsMargins(Styles::ROOT_MARGIN, Styles::ROOT_MARGIN, Styles::ROOT_MARGIN, Styles::ROOT_MARGIN);

    auto* dealerBox = new QVBoxLayout();
    auto* dealerTitle = new QLabel(Strings::DEALER_TITLE, this);
    dealerTitle->setStyleSheet(Styles::TITLE_LABEL);
    m_dealerLabel = new QLabel(Strings::EMPTY, this);
    m_dealerTotal = new QLabel(Strings::EMPTY, this);
    dealerBox->addWidget(dealerTitle);
    dealerBox->addWidget(m_dealerLabel);
    dealerBox->addWidget(m_dealerTotal);

    auto* playerBox = new QVBoxLayout();
    auto* playerTitle = new QLabel(Strings::PLAYER_TITLE, this);
    playerTitle->setStyleSheet(Styles::TITLE_LABEL);
    m_playerLabel = new QLabel(Strings::EMPTY, this);
    m_playerTotal = new QLabel(Strings::EMPTY, this);
    playerBox->addWidget(playerTitle);
    playerBox->addWidget(m_playerLabel);
    playerBox->addWidget(m_playerTotal);

    auto* mid = new QHBoxLayout();
    mid->addLayout(dealerBox);
    mid->addSpacing(Styles::MID_SPACING);
    mid->addLayout(playerBox);

    m_statusLabel = new QLabel(Strings::STATUS_START, this);
    m_statusLabel->setWordWrap(true);
    m_statusLabel->setStyleSheet(Styles::STATUS_LABEL);

    auto* controls = new QHBoxLayout();
    controls->setSpacing(Styles::CONTROLS_SPACING);
    m_dealBtn = new QPushButton(Strings::BTN_DEAL, this);
    m_hitBtn = new QPushButton(Strings::BTN_HIT, this);
    m_standBtn = new QPushButton(Strings::BTN_STAND, this);
    controls->addWidget(m_dealBtn);
    controls->addWidget(m_hitBtn);
    controls->addWidget(m_standBtn);

    m_chipsLabel = new QLabel(this);
    m_chipsLabel->setStyleSheet(Styles::CHIPS_LABEL);

    root->addLayout(mid, 1);
    root->addSpacing(Styles::ROOT_SECTION_SPACING);
    root->addWidget(m_statusLabel);
    root->addWidget(m_chipsLabel);
    root->addLayout(controls);

    resize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);

    // Wire view to viewmodel
    connect(m_dealBtn, &QPushButton::clicked, m_vm, &BlackjackViewModel::deal);
    connect(m_hitBtn, &QPushButton::clicked, m_vm, &BlackjackViewModel::hit);
    connect(m_standBtn, &QPushButton::clicked, m_vm, &BlackjackViewModel::stand);
    connect(m_vm, &BlackjackViewModel::viewDataChanged, this, &BlackjackWindow::refresh);

    refresh();
}

void BlackjackWindow::refresh() const
{
    // Pull state from VM
    m_dealerLabel->setText(m_vm->dealerText());
    m_dealerTotal->setText(m_vm->dealerTotalText());
    m_playerLabel->setText(m_vm->playerText());
    m_playerTotal->setText(m_vm->playerTotalText());
    m_statusLabel->setText(m_vm->statusText());
    m_chipsLabel->setText(m_vm->chipsText());

    m_dealBtn->setEnabled(m_vm->dealEnabled());
    m_hitBtn->setEnabled(m_vm->hitEnabled());
    m_standBtn->setEnabled(m_vm->standEnabled());
}
