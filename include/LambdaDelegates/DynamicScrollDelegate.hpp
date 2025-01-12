#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DynamicScrollDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDynamicScrollDelegate : public cocos2d::CCObject, public DynamicScrollDelegate {
protected:
    std::function<void(LambdaDynamicScrollDelegate*, cocos2d::CCObject*, cocos2d::CCObject*)> m_updatePageWithObject;
public:
    void updatePageWithObject(cocos2d::CCObject* p0, cocos2d::CCObject* p1) override {
        if (m_updatePageWithObject) return m_updatePageWithObject(this, p0, p1);
        throw std::runtime_error("Lambda Delegates: DynamicScrollDelegate::updatePageWithObject not implemented");
    }

    static LambdaDynamicScrollDelegate* create(
        std::function<void(LambdaDynamicScrollDelegate*, cocos2d::CCObject*, cocos2d::CCObject*)> const& updatePageWithObject = nullptr
    ) {
        auto delegate = new LambdaDynamicScrollDelegate();
        delegate->m_updatePageWithObject = updatePageWithObject;
        delegate->autorelease();
        return delegate;
    }
};
