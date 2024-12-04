#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/RateLevelDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaRateLevelDelegate : public cocos2d::CCObject, public RateLevelDelegate {
public:
    std::function<void()> m_rateLevelClosed;

    void rateLevelClosed() override {
        return m_rateLevelClosed();
    }

    static LambdaRateLevelDelegate* create(
        std::function<void()> const& rateLevelClosed = []() {}
    ) {
        auto delegate = new LambdaRateLevelDelegate();
        delegate->m_rateLevelClosed = rateLevelClosed;
        delegate->autorelease();
        return delegate;
    }
};
