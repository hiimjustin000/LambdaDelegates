#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CustomSFXDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCustomSFXDelegate : public cocos2d::CCObject, public CustomSFXDelegate {
protected:
    std::function<void(LambdaCustomSFXDelegate*, SFXInfoObject*)> m_sfxObjectSelected;
    std::function<int(LambdaCustomSFXDelegate*)> m_getActiveSFXID;
    std::function<bool(LambdaCustomSFXDelegate*, SFXInfoObject*)> m_overridePlaySFX;
public:
    void sfxObjectSelected(SFXInfoObject* p0) override {
        if (m_sfxObjectSelected) return m_sfxObjectSelected(this, p0);
    }
    int getActiveSFXID() override {
        if (m_getActiveSFXID) return m_getActiveSFXID(this);
        return 0;
    }
    bool overridePlaySFX(SFXInfoObject* p0) override {
        if (m_overridePlaySFX) return m_overridePlaySFX(this, p0);
        return false;
    }

    static LambdaCustomSFXDelegate* create(
        std::function<void(LambdaCustomSFXDelegate*, SFXInfoObject*)> const& sfxObjectSelected = [](auto*, auto*) {},
        std::function<int(LambdaCustomSFXDelegate*)> const& getActiveSFXID = [](auto*) { return 0; },
        std::function<bool(LambdaCustomSFXDelegate*, SFXInfoObject*)> const& overridePlaySFX = [](auto*, auto*) { return false; }
    ) {
        auto delegate = new LambdaCustomSFXDelegate();
        delegate->m_sfxObjectSelected = sfxObjectSelected;
        delegate->m_getActiveSFXID = getActiveSFXID;
        delegate->m_overridePlaySFX = overridePlaySFX;
        delegate->autorelease();
        return delegate;
    }
};
