#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/MusicBrowserDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaMusicBrowserDelegate : public cocos2d::CCObject, public MusicBrowserDelegate {
protected:
    std::function<void(LambdaMusicBrowserDelegate*, MusicBrowser*)> m_musicBrowserClosed;
public:
    void musicBrowserClosed(MusicBrowser* p0) override {
        if (m_musicBrowserClosed) return m_musicBrowserClosed(this, p0);
    }

    static LambdaMusicBrowserDelegate* create(
        std::function<void(LambdaMusicBrowserDelegate*, MusicBrowser*)> const& musicBrowserClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaMusicBrowserDelegate();
        delegate->m_musicBrowserClosed = musicBrowserClosed;
        delegate->autorelease();
        return delegate;
    }
};
