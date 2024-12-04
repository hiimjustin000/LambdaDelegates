#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CCCircleWaveDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCCCircleWaveDelegate : public cocos2d::CCObject, public CCCircleWaveDelegate {
public:
    std::function<void(CCCircleWave*)> m_circleWaveWillBeRemoved;

    void circleWaveWillBeRemoved(CCCircleWave* p0) override {
        return m_circleWaveWillBeRemoved(p0);
    }

    static LambdaCCCircleWaveDelegate* create(
        std::function<void(CCCircleWave*)> const& circleWaveWillBeRemoved = [](auto) {}
    ) {
        auto delegate = new LambdaCCCircleWaveDelegate();
        delegate->m_circleWaveWillBeRemoved = circleWaveWillBeRemoved;
        delegate->autorelease();
        return delegate;
    }
};
