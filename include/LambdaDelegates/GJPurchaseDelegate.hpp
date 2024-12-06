#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJPurchaseDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJPurchaseDelegate : public cocos2d::CCObject, public GJPurchaseDelegate {
public:
    std::function<void(GJStoreItem*)> m_didPurchaseItem;

    void didPurchaseItem(GJStoreItem* p0) override {
        if (m_didPurchaseItem) return m_didPurchaseItem(p0);
    }

    static LambdaGJPurchaseDelegate* create(
        std::function<void(GJStoreItem*)> const& didPurchaseItem = [](auto) {}
    ) {
        auto delegate = new LambdaGJPurchaseDelegate();
        delegate->m_didPurchaseItem = didPurchaseItem;
        delegate->autorelease();
        return delegate;
    }
};
