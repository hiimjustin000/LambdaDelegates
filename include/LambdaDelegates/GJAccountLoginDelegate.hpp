#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountLoginDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountLoginDelegate : public cocos2d::CCObject, public GJAccountLoginDelegate {
protected:
    std::function<void(LambdaGJAccountLoginDelegate*, int, int)> m_loginAccountFinished;
    std::function<void(LambdaGJAccountLoginDelegate*, AccountError)> m_loginAccountFailed;
public:
    void loginAccountFinished(int p0, int p1) override {
        if (m_loginAccountFinished) return m_loginAccountFinished(this, p0, p1);
    }
    void loginAccountFailed(AccountError p0) override {
        if (m_loginAccountFailed) return m_loginAccountFailed(this, p0);
    }

    static LambdaGJAccountLoginDelegate* create(
        std::function<void(LambdaGJAccountLoginDelegate*, int, int)> const& loginAccountFinished = [](auto*, auto, auto) {},
        std::function<void(LambdaGJAccountLoginDelegate*, AccountError)> const& loginAccountFailed = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaGJAccountLoginDelegate();
        delegate->m_loginAccountFinished = loginAccountFinished;
        delegate->m_loginAccountFailed = loginAccountFailed;
        delegate->autorelease();
        return delegate;
    }
};
