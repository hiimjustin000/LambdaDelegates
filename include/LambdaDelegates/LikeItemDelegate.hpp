#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LikeItemDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLikeItemDelegate : public cocos2d::CCObject, public LikeItemDelegate {
public:
    std::function<void(LikeItemType, int, bool)> m_likedItem;

    void likedItem(LikeItemType p0, int p1, bool p2) override {
        return m_likedItem(p0, p1, p2);
    }

    static LambdaLikeItemDelegate* create(
        std::function<void(LikeItemType, int, bool)> const& likedItem = [](auto, auto, auto) {}
    ) {
        auto delegate = new LambdaLikeItemDelegate();
        delegate->m_likedItem = likedItem;
        delegate->autorelease();
        return delegate;
    }
};
