#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/AnimatedSpriteDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaAnimatedSpriteDelegate : public cocos2d::CCObject, public AnimatedSpriteDelegate {
public:
    std::function<void(char const*)> m_animationFinished;

    void animationFinished(char const* p0) override {
        return m_animationFinished(p0);
    }

    static LambdaAnimatedSpriteDelegate* create(
        std::function<void(char const*)> const& animationFinished = [](auto) {}
    ) {
        auto delegate = new LambdaAnimatedSpriteDelegate();
        delegate->m_animationFinished = animationFinished;
        delegate->autorelease();
        return delegate;
    }
};
