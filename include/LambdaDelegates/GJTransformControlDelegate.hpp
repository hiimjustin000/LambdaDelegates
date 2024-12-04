#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJTransformControlDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJTransformControlDelegate : public cocos2d::CCObject, public GJTransformControlDelegate {
public:
    std::function<void(float)> m_transformScaleXChanged;
    std::function<void(float)> m_transformScaleYChanged;
    std::function<void(float, float)> m_transformScaleXYChanged;
    std::function<void(float)> m_transformRotationXChanged;
    std::function<void(float)> m_transformRotationYChanged;
    std::function<void(float)> m_transformRotationChanged;
    std::function<void()> m_transformResetRotation;
    std::function<void()> m_transformRestoreRotation;
    std::function<void(float)> m_transformSkewXChanged;
    std::function<void(float)> m_transformSkewYChanged;
    std::function<void()> m_transformChangeBegin;
    std::function<void()> m_transformChangeEnded;
    std::function<void()> m_updateTransformControl;
    std::function<void(cocos2d::CCPoint)> m_anchorPointMoved;
    std::function<cocos2d::CCNode*()> m_getTransformNode;
    std::function<cocos2d::CCLayer*()> m_getUI;

    void transformScaleXChanged(float p0) override {
        return m_transformScaleXChanged(p0);
    }
    void transformScaleYChanged(float p0) override {
        return m_transformScaleYChanged(p0);
    }
    void transformScaleXYChanged(float p0, float p1) override {
        return m_transformScaleXYChanged(p0, p1);
    }
    void transformRotationXChanged(float p0) override {
        return m_transformRotationXChanged(p0);
    }
    void transformRotationYChanged(float p0) override {
        return m_transformRotationYChanged(p0);
    }
    void transformRotationChanged(float p0) override {
        return m_transformRotationChanged(p0);
    }
    void transformResetRotation() override {
        return m_transformResetRotation();
    }
    void transformRestoreRotation() override {
        return m_transformRestoreRotation();
    }
    void transformSkewXChanged(float p0) override {
        return m_transformSkewXChanged(p0);
    }
    void transformSkewYChanged(float p0) override {
        return m_transformSkewYChanged(p0);
    }
    void transformChangeBegin() override {
        return m_transformChangeBegin();
    }
    void transformChangeEnded() override {
        return m_transformChangeEnded();
    }
    void updateTransformControl() override {
        return m_updateTransformControl();
    }
    void anchorPointMoved(cocos2d::CCPoint p0) override {
        return m_anchorPointMoved(p0);
    }
    cocos2d::CCNode* getTransformNode() override {
        return m_getTransformNode();
    }
    cocos2d::CCLayer* getUI() override {
        return m_getUI();
    }

    static LambdaGJTransformControlDelegate* create(
        std::function<void(float)> const& transformScaleXChanged = [](auto) {},
        std::function<void(float)> const& transformScaleYChanged = [](auto) {},
        std::function<void(float, float)> const& transformScaleXYChanged = [](auto, auto) {},
        std::function<void(float)> const& transformRotationXChanged = [](auto) {},
        std::function<void(float)> const& transformRotationYChanged = [](auto) {},
        std::function<void(float)> const& transformRotationChanged = [](auto) {},
        std::function<void()> const& transformResetRotation = []() {},
        std::function<void()> const& transformRestoreRotation = []() {},
        std::function<void(float)> const& transformSkewXChanged = [](auto) {},
        std::function<void(float)> const& transformSkewYChanged = [](auto) {},
        std::function<void()> const& transformChangeBegin = []() {},
        std::function<void()> const& transformChangeEnded = []() {},
        std::function<void()> const& updateTransformControl = []() {},
        std::function<void(cocos2d::CCPoint)> const& anchorPointMoved = [](auto) {},
        std::function<cocos2d::CCNode*()> const& getTransformNode = []() { return nullptr; },
        std::function<cocos2d::CCLayer*()> const& getUI = []() { return nullptr; }
    ) {
        auto delegate = new LambdaGJTransformControlDelegate();
        delegate->m_transformScaleXChanged = transformScaleXChanged;
        delegate->m_transformScaleYChanged = transformScaleYChanged;
        delegate->m_transformScaleXYChanged = transformScaleXYChanged;
        delegate->m_transformRotationXChanged = transformRotationXChanged;
        delegate->m_transformRotationYChanged = transformRotationYChanged;
        delegate->m_transformRotationChanged = transformRotationChanged;
        delegate->m_transformResetRotation = transformResetRotation;
        delegate->m_transformRestoreRotation = transformRestoreRotation;
        delegate->m_transformSkewXChanged = transformSkewXChanged;
        delegate->m_transformSkewYChanged = transformSkewYChanged;
        delegate->m_transformChangeBegin = transformChangeBegin;
        delegate->m_transformChangeEnded = transformChangeEnded;
        delegate->m_updateTransformControl = updateTransformControl;
        delegate->m_anchorPointMoved = anchorPointMoved;
        delegate->m_getTransformNode = getTransformNode;
        delegate->m_getUI = getUI;
        delegate->autorelease();
        return delegate;
    }
};
