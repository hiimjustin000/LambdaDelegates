#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/CCScrollLayerExtDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaCCScrollLayerExtDelegate : public cocos2d::CCObject, public CCScrollLayerExtDelegate {
protected:
    std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> m_scrllViewWillBeginDecelerating;
    std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> m_scrollViewDidEndDecelerating;
    std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> m_scrollViewTouchMoving;
    std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> m_scrollViewDidEndMoving;
    std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> m_scrollViewTouchBegin;
    std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> m_scrollViewTouchEnd;
public:
    void scrllViewWillBeginDecelerating(CCScrollLayerExt* p0) override {
        if (m_scrllViewWillBeginDecelerating) return m_scrllViewWillBeginDecelerating(this, p0);
    }
    void scrollViewDidEndDecelerating(CCScrollLayerExt* p0) override {
        if (m_scrollViewDidEndDecelerating) return m_scrollViewDidEndDecelerating(this, p0);
    }
    void scrollViewTouchMoving(CCScrollLayerExt* p0) override {
        if (m_scrollViewTouchMoving) return m_scrollViewTouchMoving(this, p0);
    }
    void scrollViewDidEndMoving(CCScrollLayerExt* p0) override {
        if (m_scrollViewDidEndMoving) return m_scrollViewDidEndMoving(this, p0);
    }
    void scrollViewTouchBegin(CCScrollLayerExt* p0) override {
        if (m_scrollViewTouchBegin) return m_scrollViewTouchBegin(this, p0);
    }
    void scrollViewTouchEnd(CCScrollLayerExt* p0) override {
        if (m_scrollViewTouchEnd) return m_scrollViewTouchEnd(this, p0);
    }

    static LambdaCCScrollLayerExtDelegate* create(
        std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> const& scrllViewWillBeginDecelerating = [](auto*, auto*) {},
        std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> const& scrollViewDidEndDecelerating = [](auto*, auto*) {},
        std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> const& scrollViewTouchMoving = [](auto*, auto*) {},
        std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> const& scrollViewDidEndMoving = [](auto*, auto*) {},
        std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> const& scrollViewTouchBegin = [](auto*, auto*) {},
        std::function<void(LambdaCCScrollLayerExtDelegate*, CCScrollLayerExt*)> const& scrollViewTouchEnd = [](auto*, auto*) {}
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
