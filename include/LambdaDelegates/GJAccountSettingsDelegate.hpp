#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJAccountSettingsDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJAccountSettingsDelegate : public cocos2d::CCObject, public GJAccountSettingsDelegate {
protected:
    std::function<void(LambdaGJAccountSettingsDelegate*)> m_updateSettingsFinished;
    std::function<void(LambdaGJAccountSettingsDelegate*)> m_updateSettingsFailed;
public:
    void updateSettingsFinished() override {
        if (m_updateSettingsFinished) return m_updateSettingsFinished(this);
    }
    void updateSettingsFailed() override {
        if (m_updateSettingsFailed) return m_updateSettingsFailed(this);
    }

    static LambdaGJAccountSettingsDelegate* create(
        std::function<void(LambdaGJAccountSettingsDelegate*)> const& updateSettingsFinished = [](auto*) {},
        std::function<void(LambdaGJAccountSettingsDelegate*)> const& updateSettingsFailed = [](auto*) {}
    ) {
        auto delegate = new LambdaGJAccountSettingsDelegate();
        delegate->m_updateSettingsFinished = updateSettingsFinished;
        delegate->m_updateSettingsFailed = updateSettingsFailed;
        delegate->autorelease();
        return delegate;
    }
};
