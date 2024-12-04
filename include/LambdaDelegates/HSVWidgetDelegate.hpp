#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/HSVWidgetDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaHSVWidgetDelegate : public cocos2d::CCObject, public HSVWidgetDelegate {
public:
    std::function<void(HSVWidgetPopup*, cocos2d::ccHSVValue)> m_hsvPopupClosed;
    std::function<void(ConfigureHSVWidget*)> m_hsvChanged;

    void hsvPopupClosed(HSVWidgetPopup* p0, cocos2d::ccHSVValue p1) override {
        return m_hsvPopupClosed(p0, p1);
    }
    void hsvChanged(ConfigureHSVWidget* p0) override {
        return m_hsvChanged(p0);
    }

    static LambdaHSVWidgetDelegate* create(
        std::function<void(HSVWidgetPopup*, cocos2d::ccHSVValue)> const& hsvPopupClosed = [](auto, auto) {},
        std::function<void(ConfigureHSVWidget*)> const& hsvChanged = [](auto) {}
    ) {
        auto delegate = new LambdaHSVWidgetDelegate();
        delegate->m_hsvPopupClosed = hsvPopupClosed;
        delegate->m_hsvChanged = hsvChanged;
        delegate->autorelease();
        return delegate;
    }
};
