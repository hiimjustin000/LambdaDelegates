#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SFXBrowserDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSFXBrowserDelegate : public cocos2d::CCObject, public SFXBrowserDelegate {
public:
    std::function<void(SFXBrowser*)> m_sfxBrowserClosed;

    void sfxBrowserClosed(SFXBrowser* p0) override {
        return m_sfxBrowserClosed(p0);
    }

    static LambdaSFXBrowserDelegate* create(
        std::function<void(SFXBrowser*)> const& sfxBrowserClosed = [](auto) {}
    ) {
        auto delegate = new LambdaSFXBrowserDelegate();
        delegate->m_sfxBrowserClosed = sfxBrowserClosed;
        delegate->autorelease();
        return delegate;
    }
};
