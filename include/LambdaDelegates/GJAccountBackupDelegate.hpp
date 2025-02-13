#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountBackupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountBackupDelegate : public cocos2d::CCObject, public GJAccountBackupDelegate {
protected:
    std::function<void(LambdaGJAccountBackupDelegate*)> m_backupAccountFinished;
    std::function<void(LambdaGJAccountBackupDelegate*, BackupAccountError, int)> m_backupAccountFailed;
public:
    void backupAccountFinished() override {
        if (m_backupAccountFinished) return m_backupAccountFinished(this);
    }
    void backupAccountFailed(BackupAccountError p0, int p1) override {
        if (m_backupAccountFailed) return m_backupAccountFailed(this, p0, p1);
    }

    static LambdaGJAccountBackupDelegate* create(
        std::function<void(LambdaGJAccountBackupDelegate*)> const& backupAccountFinished = [](auto*) {},
        std::function<void(LambdaGJAccountBackupDelegate*, BackupAccountError, int)> const& backupAccountFailed = [](auto*, auto, auto) {}
    ) {
        auto delegate = new LambdaGJAccountBackupDelegate();
        delegate->m_backupAccountFinished = backupAccountFinished;
        delegate->m_backupAccountFailed = backupAccountFailed;
        delegate->autorelease();
        return delegate;
    }
};
