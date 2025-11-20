#pragma once

#include <QObject>
#include <QString>
#include <vector>
#include "BlackjackModel.h"

class BlackjackViewModel : public QObject {
    Q_OBJECT
public:
    explicit BlackjackViewModel(QObject* parent = nullptr);

public slots:
    void deal();
    void hit();
    void stand();

signals:
    void viewDataChanged();

public:
    // Getters for View
    QString dealerText() const;
    QString dealerTotalText() const;
    QString playerText() const;
    QString playerTotalText() const;
    QString chipsText() const;
    QString statusText() const;

    bool dealEnabled() const;
    bool hitEnabled() const;
    bool standEnabled() const;

private:
    QString m_statusMessage;
    BlackjackModel m_model; // actual model

    static QString outcomeToMessage(BlackjackModel::Outcome o);
    void finishRound(BlackjackModel::Outcome outcome, const QString& customMessage = QString());
    static QString handToText(const std::vector<int>& hand, bool hideFirst);
};
