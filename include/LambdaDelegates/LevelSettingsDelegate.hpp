#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelSettingsDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelSettingsDelegate : public cocos2d::CCObject, public LevelSettingsDelegate {
protected:
    std::function<void(LambdaLevelSettingsDelegate*)> m_levelSettingsUpdated;
public:
    void levelSettingsUpdated() override {
        if (m_levelSettingsUpdated) return m_levelSettingsUpdated(this);
    }

    static LambdaLevelSettingsDelegate* create(
        std::function<void(LambdaLevelSettingsDelegate*)> const& levelSettingsUpdated = [](auto*) {}
    ) {
        auto delegate = new LambdaLevelSettingsDelegate();
        delegate->m_levelSettingsUpdated = levelSettingsUpdated;
        delegate->autorelease();
        return delegate;
    }
};
