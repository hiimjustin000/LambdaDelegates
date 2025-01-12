#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/RateLevelDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaRateLevelDelegate : public cocos2d::CCObject, public RateLevelDelegate {
protected:
    std::function<void(LambdaRateLevelDelegate*)> m_rateLevelClosed;
public:
    void rateLevelClosed() override {
        if (m_rateLevelClosed) return m_rateLevelClosed(this);
    }

    static LambdaRateLevelDelegate* create(
        std::function<void(LambdaRateLevelDelegate*)> const& rateLevelClosed = [](auto*) {}
    ) {
        auto delegate = new LambdaRateLevelDelegate();
        delegate->m_rateLevelClosed = rateLevelClosed;
        delegate->autorelease();
        return delegate;
    }
};
