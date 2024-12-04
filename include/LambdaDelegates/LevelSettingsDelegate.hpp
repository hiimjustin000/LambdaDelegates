#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LevelSettingsDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLevelSettingsDelegate : public cocos2d::CCObject, public LevelSettingsDelegate {
public:
    std::function<void()> m_levelSettingsUpdated;

    void levelSettingsUpdated() override {
        return m_levelSettingsUpdated();
    }

    static LambdaLevelSettingsDelegate* create(
        std::function<void()> const& levelSettingsUpdated = []() {}
    ) {
        auto delegate = new LambdaLevelSettingsDelegate();
        delegate->m_levelSettingsUpdated = levelSettingsUpdated;
        delegate->autorelease();
        return delegate;
    }
};
