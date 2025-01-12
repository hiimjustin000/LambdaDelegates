#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJTransformControlDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJTransformControlDelegate : public cocos2d::CCObject, public GJTransformControlDelegate {
protected:
    std::function<void(LambdaGJTransformControlDelegate*, float)> m_transformScaleXChanged;
    std::function<void(LambdaGJTransformControlDelegate*, float)> m_transformScaleYChanged;
    std::function<void(LambdaGJTransformControlDelegate*, float, float)> m_transformScaleXYChanged;
    std::function<void(LambdaGJTransformControlDelegate*, float)> m_transformRotationXChanged;
    std::function<void(LambdaGJTransformControlDelegate*, float)> m_transformRotationYChanged;
    std::function<void(LambdaGJTransformControlDelegate*, float)> m_transformRotationChanged;
    std::function<void(LambdaGJTransformControlDelegate*)> m_transformResetRotation;
    std::function<void(LambdaGJTransformControlDelegate*)> m_transformRestoreRotation;
    std::function<void(LambdaGJTransformControlDelegate*, float)> m_transformSkewXChanged;
    std::function<void(LambdaGJTransformControlDelegate*, float)> m_transformSkewYChanged;
    std::function<void(LambdaGJTransformControlDelegate*)> m_transformChangeBegin;
    std::function<void(LambdaGJTransformControlDelegate*)> m_transformChangeEnded;
    std::function<void(LambdaGJTransformControlDelegate*)> m_updateTransformControl;
    std::function<void(LambdaGJTransformControlDelegate*, cocos2d::CCPoint)> m_anchorPointMoved;
    std::function<cocos2d::CCNode*(LambdaGJTransformControlDelegate*)> m_getTransformNode;
    std::function<cocos2d::CCLayer*(LambdaGJTransformControlDelegate*)> m_getUI;
public:
    void transformScaleXChanged(float p0) override {
        if (m_transformScaleXChanged) return m_transformScaleXChanged(this, p0);
    }
    void transformScaleYChanged(float p0) override {
        if (m_transformScaleYChanged) return m_transformScaleYChanged(this, p0);
    }
    void transformScaleXYChanged(float p0, float p1) override {
        if (m_transformScaleXYChanged) return m_transformScaleXYChanged(this, p0, p1);
    }
    void transformRotationXChanged(float p0) override {
        if (m_transformRotationXChanged) return m_transformRotationXChanged(this, p0);
    }
    void transformRotationYChanged(float p0) override {
        if (m_transformRotationYChanged) return m_transformRotationYChanged(this, p0);
    }
    void transformRotationChanged(float p0) override {
        if (m_transformRotationChanged) return m_transformRotationChanged(this, p0);
    }
    void transformResetRotation() override {
        if (m_transformResetRotation) return m_transformResetRotation(this);
    }
    void transformRestoreRotation() override {
        if (m_transformRestoreRotation) return m_transformRestoreRotation(this);
    }
    void transformSkewXChanged(float p0) override {
        if (m_transformSkewXChanged) return m_transformSkewXChanged(this, p0);
    }
    void transformSkewYChanged(float p0) override {
        if (m_transformSkewYChanged) return m_transformSkewYChanged(this, p0);
    }
    void transformChangeBegin() override {
        if (m_transformChangeBegin) return m_transformChangeBegin(this);
    }
    void transformChangeEnded() override {
        if (m_transformChangeEnded) return m_transformChangeEnded(this);
    }
    void updateTransformControl() override {
        if (m_updateTransformControl) return m_updateTransformControl(this);
    }
    void anchorPointMoved(cocos2d::CCPoint p0) override {
        if (m_anchorPointMoved) return m_anchorPointMoved(this, p0);
    }
    cocos2d::CCNode* getTransformNode() override {
        if (m_getTransformNode) return m_getTransformNode(this);
        return nullptr;
    }
    cocos2d::CCLayer* getUI() override {
        if (m_getUI) return m_getUI(this);
        return nullptr;
    }

    static LambdaGJTransformControlDelegate* create(
        std::function<void(LambdaGJTransformControlDelegate*, float)> const& transformScaleXChanged = [](auto*, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*, float)> const& transformScaleYChanged = [](auto*, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*, float, float)> const& transformScaleXYChanged = [](auto*, auto, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*, float)> const& transformRotationXChanged = [](auto*, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*, float)> const& transformRotationYChanged = [](auto*, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*, float)> const& transformRotationChanged = [](auto*, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*)> const& transformResetRotation = [](auto*) {},
        std::function<void(LambdaGJTransformControlDelegate*)> const& transformRestoreRotation = [](auto*) {},
        std::function<void(LambdaGJTransformControlDelegate*, float)> const& transformSkewXChanged = [](auto*, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*, float)> const& transformSkewYChanged = [](auto*, auto) {},
        std::function<void(LambdaGJTransformControlDelegate*)> const& transformChangeBegin = [](auto*) {},
        std::function<void(LambdaGJTransformControlDelegate*)> const& transformChangeEnded = [](auto*) {},
        std::function<void(LambdaGJTransformControlDelegate*)> const& updateTransformControl = [](auto*) {},
        std::function<void(LambdaGJTransformControlDelegate*, cocos2d::CCPoint)> const& anchorPointMoved = [](auto*, auto) {},
        std::function<cocos2d::CCNode*(LambdaGJTransformControlDelegate*)> const& getTransformNode = [](auto*) { return nullptr; },
        std::function<cocos2d::CCLayer*(LambdaGJTransformControlDelegate*)> const& getUI = [](auto*) { return nullptr; }
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
