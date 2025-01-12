#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountSyncDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountSyncDelegate : public cocos2d::CCObject, public GJAccountSyncDelegate {
protected:
    std::function<void(LambdaGJAccountSyncDelegate*)> m_syncAccountFinished;
    std::function<void(LambdaGJAccountSyncDelegate*, BackupAccountError, int)> m_syncAccountFailed;
public:
    void syncAccountFinished() override {
        if (m_syncAccountFinished) return m_syncAccountFinished(this);
    }
    void syncAccountFailed(BackupAccountError p0, int p1) override {
        if (m_syncAccountFailed) return m_syncAccountFailed(this, p0, p1);
    }

    static LambdaGJAccountSyncDelegate* create(
        std::function<void(LambdaGJAccountSyncDelegate*)> const& syncAccountFinished = [](auto*) {},
        std::function<void(LambdaGJAccountSyncDelegate*, BackupAccountError, int)> const& syncAccountFailed = [](auto*, auto, auto) {}
    ) {
        auto delegate = new LambdaGJAccountSyncDelegate();
        delegate->m_syncAccountFinished = syncAccountFinished;
        delegate->m_syncAccountFailed = syncAccountFailed;
        delegate->autorelease();
        return delegate;
    }
};
