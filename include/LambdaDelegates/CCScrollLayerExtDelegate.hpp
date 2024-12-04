#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CCScrollLayerExtDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCCScrollLayerExtDelegate : public cocos2d::CCObject, public CCScrollLayerExtDelegate {
public:
    std::function<void(CCScrollLayerExt*)> m_scrllViewWillBeginDecelerating;
    std::function<void(CCScrollLayerExt*)> m_scrollViewDidEndDecelerating;
    std::function<void(CCScrollLayerExt*)> m_scrollViewTouchMoving;
    std::function<void(CCScrollLayerExt*)> m_scrollViewDidEndMoving;
    std::function<void(CCScrollLayerExt*)> m_scrollViewTouchBegin;
    std::function<void(CCScrollLayerExt*)> m_scrollViewTouchEnd;

    void scrllViewWillBeginDecelerating(CCScrollLayerExt* p0) override {
        return m_scrllViewWillBeginDecelerating(p0);
    }
    void scrollViewDidEndDecelerating(CCScrollLayerExt* p0) override {
        return m_scrollViewDidEndDecelerating(p0);
    }
    void scrollViewTouchMoving(CCScrollLayerExt* p0) override {
        return m_scrollViewTouchMoving(p0);
    }
    void scrollViewDidEndMoving(CCScrollLayerExt* p0) override {
        return m_scrollViewDidEndMoving(p0);
    }
    void scrollViewTouchBegin(CCScrollLayerExt* p0) override {
        return m_scrollViewTouchBegin(p0);
    }
    void scrollViewTouchEnd(CCScrollLayerExt* p0) override {
        return m_scrollViewTouchEnd(p0);
    }

    static LambdaCCScrollLayerExtDelegate* create(
        std::function<void(CCScrollLayerExt*)> const& scrllViewWillBeginDecelerating = [](auto) {},
        std::function<void(CCScrollLayerExt*)> const& scrollViewDidEndDecelerating = [](auto) {},
        std::function<void(CCScrollLayerExt*)> const& scrollViewTouchMoving = [](auto) {},
        std::function<void(CCScrollLayerExt*)> const& scrollViewDidEndMoving = [](auto) {},
        std::function<void(CCScrollLayerExt*)> const& scrollViewTouchBegin = [](auto) {},
        std::function<void(CCScrollLayerExt*)> const& scrollViewTouchEnd = [](auto) {}
    ) {
        auto delegate = new LambdaCCScrollLayerExtDelegate();
        delegate->m_scrllViewWillBeginDecelerating = scrllViewWillBeginDecelerating;
        delegate->m_scrollViewDidEndDecelerating = scrollViewDidEndDecelerating;
        delegate->m_scrollViewTouchMoving = scrollViewTouchMoving;
        delegate->m_scrollViewDidEndMoving = scrollViewDidEndMoving;
        delegate->m_scrollViewTouchBegin = scrollViewTouchBegin;
        delegate->m_scrollViewTouchEnd = scrollViewTouchEnd;
        delegate->autorelease();
        return delegate;
    }
};
