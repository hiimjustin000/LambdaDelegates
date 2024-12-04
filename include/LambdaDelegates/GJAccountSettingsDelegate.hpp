#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountSettingsDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountSettingsDelegate : public cocos2d::CCObject, public GJAccountSettingsDelegate {
public:
    std::function<void()> m_updateSettingsFinished;
    std::function<void()> m_updateSettingsFailed;

    void updateSettingsFinished() override {
        return m_updateSettingsFinished();
    }
    void updateSettingsFailed() override {
        return m_updateSettingsFailed();
    }

    static LambdaGJAccountSettingsDelegate* create(
        std::function<void()> const& updateSettingsFinished = []() {},
        std::function<void()> const& updateSettingsFailed = []() {}
    ) {
        auto delegate = new LambdaGJAccountSettingsDelegate();
        delegate->m_updateSettingsFinished = updateSettingsFinished;
        delegate->m_updateSettingsFailed = updateSettingsFailed;
        delegate->autorelease();
        return delegate;
    }
};
