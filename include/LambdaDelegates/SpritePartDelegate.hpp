#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SpritePartDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaSpritePartDelegate : public cocos2d::CCObject, public SpritePartDelegate {
protected:
    std::function<void(LambdaSpritePartDelegate*, cocos2d::CCObject*, gd::string)> m_displayFrameChanged;
public:
    void displayFrameChanged(cocos2d::CCObject* p0, gd::string p1) override {
        if (m_displayFrameChanged) return m_displayFrameChanged(this, p0, p1);
    }

    static LambdaSpritePartDelegate* create(
        std::function<void(LambdaSpritePartDelegate*, cocos2d::CCObject*, gd::string)> const& displayFrameChanged = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaSpritePartDelegate();
        delegate->m_displayFrameChanged = displayFrameChanged;
        delegate->autorelease();
        return delegate;
    }
};
