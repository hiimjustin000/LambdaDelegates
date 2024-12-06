#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountDelegate : public cocos2d::CCObject, public GJAccountDelegate {
public:
    std::function<void()> m_accountStatusChanged;

    void accountStatusChanged() override {
        if (m_accountStatusChanged) return m_accountStatusChanged();
    }

    static LambdaGJAccountDelegate* create(
        std::function<void()> const& accountStatusChanged = []() {}
    ) {
        auto delegate = new LambdaGJAccountDelegate();
        delegate->m_accountStatusChanged = accountStatusChanged;
        delegate->autorelease();
        return delegate;
    }
};
