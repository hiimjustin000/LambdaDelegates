#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SongPlaybackDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSongPlaybackDelegate : public cocos2d::CCObject, public SongPlaybackDelegate {
public:
    std::function<void(SongInfoObject*)> m_onPlayback;

    void onPlayback(SongInfoObject* p0) override {
        if (m_onPlayback) return m_onPlayback(p0);
    }

    static LambdaSongPlaybackDelegate* create(
        std::function<void(SongInfoObject*)> const& onPlayback = [](auto) {}
    ) {
        auto delegate = new LambdaSongPlaybackDelegate();
        delegate->m_onPlayback = onPlayback;
        delegate->autorelease();
        return delegate;
    }
};
