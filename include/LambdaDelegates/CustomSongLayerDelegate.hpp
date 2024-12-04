#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CustomSongLayerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCustomSongLayerDelegate : public cocos2d::CCObject, public CustomSongLayerDelegate {
public:
    std::function<void()> m_customSongLayerClosed;

    void customSongLayerClosed() override {
        return m_customSongLayerClosed();
    }

    static LambdaCustomSongLayerDelegate* create(
        std::function<void()> const& customSongLayerClosed = []() {}
    ) {
        auto delegate = new LambdaCustomSongLayerDelegate();
        delegate->m_customSongLayerClosed = customSongLayerClosed;
        delegate->autorelease();
        return delegate;
    }
};
