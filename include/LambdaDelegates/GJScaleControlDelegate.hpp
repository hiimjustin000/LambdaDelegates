#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJScaleControlDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJScaleControlDelegate : public cocos2d::CCObject, public GJScaleControlDelegate {
public:
    std::function<void(float, bool)> m_scaleXChanged;
    std::function<void(float, bool)> m_scaleYChanged;
    std::function<void(float, float, bool)> m_scaleXYChanged;
    std::function<void()> m_scaleChangeBegin;
    std::function<void()> m_scaleChangeEnded;
    std::function<void()> m_updateScaleControl;
    std::function<void(cocos2d::CCPoint)> m_anchorPointMoved;

    void scaleXChanged(float p0, bool p1) override {
        if (m_scaleXChanged) return m_scaleXChanged(p0, p1);
    }
    void scaleYChanged(float p0, bool p1) override {
        if (m_scaleYChanged) return m_scaleYChanged(p0, p1);
    }
    void scaleXYChanged(float p0, float p1, bool p2) override {
        if (m_scaleXYChanged) return m_scaleXYChanged(p0, p1, p2);
    }
    void scaleChangeBegin() override {
        if (m_scaleChangeBegin) return m_scaleChangeBegin();
    }
    void scaleChangeEnded() override {
        if (m_scaleChangeEnded) return m_scaleChangeEnded();
    }
    void updateScaleControl() override {
        if (m_updateScaleControl) return m_updateScaleControl();
    }
    void anchorPointMoved(cocos2d::CCPoint p0) override {
        if (m_anchorPointMoved) return m_anchorPointMoved(p0);
    }

    static LambdaGJScaleControlDelegate* create(
        std::function<void(float, bool)> const& scaleXChanged = [](auto, auto) {},
        std::function<void(float, bool)> const& scaleYChanged = [](auto, auto) {},
        std::function<void(float, float, bool)> const& scaleXYChanged = [](auto, auto, auto) {},
        std::function<void()> const& scaleChangeBegin = []() {},
        std::function<void()> const& scaleChangeEnded = []() {},
        std::function<void()> const& updateScaleControl = []() {},
        std::function<void(cocos2d::CCPoint)> const& anchorPointMoved = [](auto) {}
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
