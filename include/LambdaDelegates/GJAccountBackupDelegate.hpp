#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountBackupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountBackupDelegate : public cocos2d::CCObject, public GJAccountBackupDelegate {
public:
    std::function<void()> m_backupAccountFinished;
    std::function<void(BackupAccountError, int)> m_backupAccountFailed;

    void backupAccountFinished() override {
        if (m_backupAccountFinished) return m_backupAccountFinished();
    }
    void backupAccountFailed(BackupAccountError p0, int p1) override {
        if (m_backupAccountFailed) return m_backupAccountFailed(p0, p1);
    }

    static LambdaGJAccountBackupDelegate* create(
        std::function<void()> const& backupAccountFinished = []() {},
        std::function<void(BackupAccountError, int)> const& backupAccountFailed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaGJAccountBackupDelegate();
        delegate->m_backupAccountFinished = backupAccountFinished;
        delegate->m_backupAccountFailed = backupAccountFailed;
        delegate->autorelease();
        return delegate;
    }
};
