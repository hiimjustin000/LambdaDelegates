#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/AnimatedSpriteDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaAnimatedSpriteDelegate : public cocos2d::CCObject, public AnimatedSpriteDelegate {
protected:
    std::function<void(LambdaAnimatedSpriteDelegate*, char const*)> m_animationFinished;
public:
    void animationFinished(char const* p0) override {
        if (m_animationFinished) return m_animationFinished(this, p0);
    }

    static LambdaAnimatedSpriteDelegate* create(
        std::function<void(LambdaAnimatedSpriteDelegate*, char const*)> const& animationFinished = [](auto*, auto const*) {}
    ) {
        auto delegate = new LambdaAnimatedSpriteDelegate();
        delegate->m_animationFinished = animationFinished;
        delegate->autorelease();
        return delegate;
    }
};
