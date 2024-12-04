#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CustomSFXDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCustomSFXDelegate : public cocos2d::CCObject, public CustomSFXDelegate {
public:
    std::function<void(SFXInfoObject*)> m_sfxObjectSelected;
    std::function<int()> m_getActiveSFXID;
    std::function<bool(SFXInfoObject*)> m_overridePlaySFX;

    void sfxObjectSelected(SFXInfoObject* p0) override {
        return m_sfxObjectSelected(p0);
    }
    int getActiveSFXID() override {
        return m_getActiveSFXID();
    }
    bool overridePlaySFX(SFXInfoObject* p0) override {
        return m_overridePlaySFX(p0);
    }

    static LambdaCustomSFXDelegate* create(
        std::function<void(SFXInfoObject*)> const& sfxObjectSelected = [](auto) {},
        std::function<int()> const& getActiveSFXID = []() { return 0; },
        std::function<bool(SFXInfoObject*)> const& overridePlaySFX = [](auto) { return false; }
    ) {
        auto delegate = new LambdaCustomSFXDelegate();
        delegate->m_sfxObjectSelected = sfxObjectSelected;
        delegate->m_getActiveSFXID = getActiveSFXID;
        delegate->m_overridePlaySFX = overridePlaySFX;
        delegate->autorelease();
        return delegate;
    }
};
