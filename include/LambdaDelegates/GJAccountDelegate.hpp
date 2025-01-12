#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountDelegate : public cocos2d::CCObject, public GJAccountDelegate {
protected:
    std::function<void(LambdaGJAccountDelegate*)> m_accountStatusChanged;
public:
    void accountStatusChanged() override {
        if (m_accountStatusChanged) return m_accountStatusChanged(this);
    }

    static LambdaGJAccountDelegate* create(
        std::function<void(LambdaGJAccountDelegate*)> const& accountStatusChanged = [](auto*) {}
    ) {
        auto delegate = new LambdaGJAccountDelegate();
        delegate->m_accountStatusChanged = accountStatusChanged;
        delegate->autorelease();
        return delegate;
    }
};
