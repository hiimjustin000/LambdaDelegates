#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/MusicBrowserDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaMusicBrowserDelegate : public cocos2d::CCObject, public MusicBrowserDelegate {
public:
    std::function<void(MusicBrowser*)> m_musicBrowserClosed;

    void musicBrowserClosed(MusicBrowser* p0) override {
        return m_musicBrowserClosed(p0);
    }

    static LambdaMusicBrowserDelegate* create(
        std::function<void(MusicBrowser*)> const& musicBrowserClosed = [](auto) {}
    ) {
        auto delegate = new LambdaMusicBrowserDelegate();
        delegate->m_musicBrowserClosed = musicBrowserClosed;
        delegate->autorelease();
        return delegate;
    }
};
