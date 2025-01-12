#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SFXBrowserDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSFXBrowserDelegate : public cocos2d::CCObject, public SFXBrowserDelegate {
protected:
    std::function<void(LambdaSFXBrowserDelegate*, SFXBrowser*)> m_sfxBrowserClosed;
public:
    void sfxBrowserClosed(SFXBrowser* p0) override {
        if (m_sfxBrowserClosed) return m_sfxBrowserClosed(this, p0);
    }

    static LambdaSFXBrowserDelegate* create(
        std::function<void(LambdaSFXBrowserDelegate*, SFXBrowser*)> const& sfxBrowserClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaSFXBrowserDelegate();
        delegate->m_sfxBrowserClosed = sfxBrowserClosed;
        delegate->autorelease();
        return delegate;
    }
};
