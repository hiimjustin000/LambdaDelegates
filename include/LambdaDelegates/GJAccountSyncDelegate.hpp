#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountSyncDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountSyncDelegate : public cocos2d::CCObject, public GJAccountSyncDelegate {
public:
    std::function<void()> m_syncAccountFinished;
    std::function<void(BackupAccountError, int)> m_syncAccountFailed;

    void syncAccountFinished() override {
        return m_syncAccountFinished();
    }
    void syncAccountFailed(BackupAccountError p0, int p1) override {
        return m_syncAccountFailed(p0, p1);
    }

    static LambdaGJAccountSyncDelegate* create(
        std::function<void()> const& syncAccountFinished = []() {},
        std::function<void(BackupAccountError, int)> const& syncAccountFailed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaGJAccountSyncDelegate();
        delegate->m_syncAccountFinished = syncAccountFinished;
        delegate->m_syncAccountFailed = syncAccountFailed;
        delegate->autorelease();
        return delegate;
    }
};
