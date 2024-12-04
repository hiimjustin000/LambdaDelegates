#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CharacterColorDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCharacterColorDelegate : public cocos2d::CCObject, public CharacterColorDelegate {
public:
    std::function<void()> m_playerColorChanged;
    std::function<void(int, UnlockType)> m_showUnlockPopup;

    void playerColorChanged() override {
        return m_playerColorChanged();
    }
    void showUnlockPopup(int p0, UnlockType p1) override {
        return m_showUnlockPopup(p0, p1);
    }

    static LambdaCharacterColorDelegate* create(
        std::function<void()> const& playerColorChanged = []() {},
        std::function<void(int, UnlockType)> const& showUnlockPopup = [](auto, auto) {}
    ) {
        auto delegate = new LambdaCharacterColorDelegate();
        delegate->m_playerColorChanged = playerColorChanged;
        delegate->m_showUnlockPopup = showUnlockPopup;
        delegate->autorelease();
        return delegate;
    }
};
