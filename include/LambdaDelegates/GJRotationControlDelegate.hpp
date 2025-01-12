#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJRotationControlDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJRotationControlDelegate : public cocos2d::CCObject, public GJRotationControlDelegate {
protected:
    std::function<void(LambdaGJRotationControlDelegate*, float)> m_angleChanged;
    std::function<void(LambdaGJRotationControlDelegate*)> m_angleChangeBegin;
    std::function<void(LambdaGJRotationControlDelegate*)> m_angleChangeEnded;
public:
    void angleChanged(float p0) override {
        if (m_angleChanged) return m_angleChanged(this, p0);
    }
    void angleChangeBegin() override {
        if (m_angleChangeBegin) return m_angleChangeBegin(this);
    }
    void angleChangeEnded() override {
        if (m_angleChangeEnded) return m_angleChangeEnded(this);
    }

    static LambdaGJRotationControlDelegate* create(
        std::function<void(LambdaGJRotationControlDelegate*, float)> const& angleChanged = [](auto*, auto) {},
        std::function<void(LambdaGJRotationControlDelegate*)> const& angleChangeBegin = [](auto*) {},
        std::function<void(LambdaGJRotationControlDelegate*)> const& angleChangeEnded = [](auto*) {}
    ) {
        auto delegate = new LambdaGJRotationControlDelegate();
        delegate->m_angleChanged = angleChanged;
        delegate->m_angleChangeBegin = angleChangeBegin;
        delegate->m_angleChangeEnded = angleChangeEnded;
        delegate->autorelease();
        return delegate;
    }
};
