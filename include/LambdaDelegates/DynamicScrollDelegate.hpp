#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DynamicScrollDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDynamicScrollDelegate : public cocos2d::CCObject, public DynamicScrollDelegate {
public:
    std::function<void(cocos2d::CCObject*, cocos2d::CCObject*)> m_updatePageWithObject;

    void updatePageWithObject(cocos2d::CCObject* p0, cocos2d::CCObject* p1) override {
        return m_updatePageWithObject(p0, p1);
    }

    static LambdaDynamicScrollDelegate* create(
        std::function<void(cocos2d::CCObject*, cocos2d::CCObject*)> const& updatePageWithObject
    ) {
        auto delegate = new LambdaDynamicScrollDelegate();
        delegate->m_updatePageWithObject = updatePageWithObject;
        delegate->autorelease();
        return delegate;
    }
};
