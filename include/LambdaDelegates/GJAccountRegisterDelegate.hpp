#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountRegisterDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountRegisterDelegate : public cocos2d::CCObject, public GJAccountRegisterDelegate {
protected:
    std::function<void(LambdaGJAccountRegisterDelegate*)> m_registerAccountFinished;
    std::function<void(LambdaGJAccountRegisterDelegate*, AccountError)> m_registerAccountFailed;
public:
    void registerAccountFinished() override {
        if (m_registerAccountFinished) return m_registerAccountFinished(this);
    }
    void registerAccountFailed(AccountError p0) override {
        if (m_registerAccountFailed) return m_registerAccountFailed(this, p0);
    }

    static LambdaGJAccountRegisterDelegate* create(
        std::function<void(LambdaGJAccountRegisterDelegate*)> const& registerAccountFinished = [](auto*) {},
        std::function<void(LambdaGJAccountRegisterDelegate*, AccountError)> const& registerAccountFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaGJAccountRegisterDelegate();
        delegate->m_registerAccountFinished = registerAccountFinished;
        delegate->m_registerAccountFailed = registerAccountFailed;
        delegate->autorelease();
        return delegate;
    }
};
