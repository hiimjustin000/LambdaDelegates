#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJSpecialColorSelectDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJSpecialColorSelectDelegate : public cocos2d::CCObject, public GJSpecialColorSelectDelegate {
protected:
    std::function<void(LambdaGJSpecialColorSelectDelegate*, GJSpecialColorSelect*, int)> m_colorSelectClosed;
public:
    void colorSelectClosed(GJSpecialColorSelect* p0, int p1) override {
        if (m_colorSelectClosed) return m_colorSelectClosed(this, p0, p1);
    }

    static LambdaGJSpecialColorSelectDelegate* create(
        std::function<void(LambdaGJSpecialColorSelectDelegate*, GJSpecialColorSelect*, int)> const& colorSelectClosed = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaGJSpecialColorSelectDelegate();
        delegate->m_colorSelectClosed = colorSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
