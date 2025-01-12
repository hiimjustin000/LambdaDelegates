#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJScaleControlDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJScaleControlDelegate : public cocos2d::CCObject, public GJScaleControlDelegate {
protected:
    std::function<void(LambdaGJScaleControlDelegate*, float, bool)> m_scaleXChanged;
    std::function<void(LambdaGJScaleControlDelegate*, float, bool)> m_scaleYChanged;
    std::function<void(LambdaGJScaleControlDelegate*, float, float, bool)> m_scaleXYChanged;
    std::function<void(LambdaGJScaleControlDelegate*)> m_scaleChangeBegin;
    std::function<void(LambdaGJScaleControlDelegate*)> m_scaleChangeEnded;
    std::function<void(LambdaGJScaleControlDelegate*)> m_updateScaleControl;
    std::function<void(LambdaGJScaleControlDelegate*, cocos2d::CCPoint)> m_anchorPointMoved;
public:
    void scaleXChanged(float p0, bool p1) override {
        if (m_scaleXChanged) return m_scaleXChanged(this, p0, p1);
    }
    void scaleYChanged(float p0, bool p1) override {
        if (m_scaleYChanged) return m_scaleYChanged(this, p0, p1);
    }
    void scaleXYChanged(float p0, float p1, bool p2) override {
        if (m_scaleXYChanged) return m_scaleXYChanged(this, p0, p1, p2);
    }
    void scaleChangeBegin() override {
        if (m_scaleChangeBegin) return m_scaleChangeBegin(this);
    }
    void scaleChangeEnded() override {
        if (m_scaleChangeEnded) return m_scaleChangeEnded(this);
    }
    void updateScaleControl() override {
        if (m_updateScaleControl) return m_updateScaleControl(this);
    }
    void anchorPointMoved(cocos2d::CCPoint p0) override {
        if (m_anchorPointMoved) return m_anchorPointMoved(this, p0);
    }

    static LambdaGJScaleControlDelegate* create(
        std::function<void(LambdaGJScaleControlDelegate*, float, bool)> const& scaleXChanged = [](auto*, auto, auto) {},
        std::function<void(LambdaGJScaleControlDelegate*, float, bool)> const& scaleYChanged = [](auto*, auto, auto) {},
        std::function<void(LambdaGJScaleControlDelegate*, float, float, bool)> const& scaleXYChanged = [](auto*, auto, auto, auto) {},
        std::function<void(LambdaGJScaleControlDelegate*)> const& scaleChangeBegin = [](auto*) {},
        std::function<void(LambdaGJScaleControlDelegate*)> const& scaleChangeEnded = [](auto*) {},
        std::function<void(LambdaGJScaleControlDelegate*)> const& updateScaleControl = [](auto*) {},
        std::function<void(LambdaGJScaleControlDelegate*, cocos2d::CCPoint)> const& anchorPointMoved = [](auto*, auto) {}
    ) {
        auto delegate = new LambdaGJScaleControlDelegate();
        delegate->m_scaleXChanged = scaleXChanged;
        delegate->m_scaleYChanged = scaleYChanged;
        delegate->m_scaleXYChanged = scaleXYChanged;
        delegate->m_scaleChangeBegin = scaleChangeBegin;
        delegate->m_scaleChangeEnded = scaleChangeEnded;
        delegate->m_updateScaleControl = updateScaleControl;
        delegate->m_anchorPointMoved = anchorPointMoved;
        delegate->autorelease();
        return delegate;
    }
};
