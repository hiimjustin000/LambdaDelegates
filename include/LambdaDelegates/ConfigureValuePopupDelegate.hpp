#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ConfigureValuePopupDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaConfigureValuePopupDelegate : public cocos2d::CCObject, public ConfigureValuePopupDelegate {
public:
    std::function<void(ConfigureValuePopup*, float)> m_valuePopupClosed;

    void valuePopupClosed(ConfigureValuePopup* p0, float p1) override {
        if (m_valuePopupClosed) return m_valuePopupClosed(p0, p1);
    }

    static LambdaConfigureValuePopupDelegate* create(
        std::function<void(ConfigureValuePopup*, float)> const& valuePopupClosed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaConfigureValuePopupDelegate();
        delegate->m_valuePopupClosed = valuePopupClosed;
        delegate->autorelease();
        return delegate;
    }
};
