#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CharacterColorDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCharacterColorDelegate : public cocos2d::CCObject, public CharacterColorDelegate {
protected:
    std::function<void(LambdaCharacterColorDelegate*)> m_playerColorChanged;
    std::function<void(LambdaCharacterColorDelegate*, int, UnlockType)> m_showUnlockPopup;
public:
    void playerColorChanged() override {
        if (m_playerColorChanged) return m_playerColorChanged(this);
    }
    void showUnlockPopup(int p0, UnlockType p1) override {
        if (m_showUnlockPopup) return m_showUnlockPopup(this, p0, p1);
    }

    static LambdaCharacterColorDelegate* create(
        std::function<void(LambdaCharacterColorDelegate*)> const& playerColorChanged = [](auto*) {},
        std::function<void(LambdaCharacterColorDelegate*, int, UnlockType)> const& showUnlockPopup = [](auto*, auto, auto) {}
    ) {
        auto delegate = new LambdaCharacterColorDelegate();
        delegate->m_playerColorChanged = playerColorChanged;
        delegate->m_showUnlockPopup = showUnlockPopup;
        delegate->autorelease();
        return delegate;
    }
};
