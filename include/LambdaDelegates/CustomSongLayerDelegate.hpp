#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CustomSongLayerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCustomSongLayerDelegate : public cocos2d::CCObject, public CustomSongLayerDelegate {
protected:
    std::function<void(LambdaCustomSongLayerDelegate*)> m_customSongLayerClosed;
public:
    void customSongLayerClosed() override {
        if (m_customSongLayerClosed) return m_customSongLayerClosed(this);
    }

    static LambdaCustomSongLayerDelegate* create(
        std::function<void(LambdaCustomSongLayerDelegate*)> const& customSongLayerClosed = [](auto*) {}
    ) {
        auto delegate = new LambdaCustomSongLayerDelegate();
        delegate->m_customSongLayerClosed = customSongLayerClosed;
        delegate->autorelease();
        return delegate;
    }
};
