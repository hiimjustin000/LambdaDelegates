#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountRegisterDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountRegisterDelegate : public cocos2d::CCObject, public GJAccountRegisterDelegate {
public:
    std::function<void()> m_registerAccountFinished;
    std::function<void(AccountError)> m_registerAccountFailed;

    void registerAccountFinished() override {
        return m_registerAccountFinished();
    }
    void registerAccountFailed(AccountError p0) override {
        return m_registerAccountFailed(p0);
    }

    static LambdaGJAccountRegisterDelegate* create(
        std::function<void()> const& registerAccountFinished = []() {},
        std::function<void(AccountError)> const& registerAccountFailed = [](auto) {}
    ) {
        auto delegate = new LambdaGJAccountRegisterDelegate();
        delegate->m_registerAccountFinished = registerAccountFinished;
        delegate->m_registerAccountFailed = registerAccountFailed;
        delegate->autorelease();
        return delegate;
    }
};
