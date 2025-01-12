#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ShareCommentDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaShareCommentDelegate : public cocos2d::CCObject, public ShareCommentDelegate {
protected:
    std::function<void(LambdaShareCommentDelegate*, gd::string, ShareCommentLayer*)> m_shareCommentClosed;
public:
    void shareCommentClosed(gd::string p0, ShareCommentLayer* p1) override {
        if (m_shareCommentClosed) return m_shareCommentClosed(this, p0, p1);
    }

    static LambdaShareCommentDelegate* create(
        std::function<void(LambdaShareCommentDelegate*, gd::string, ShareCommentLayer*)> const& shareCommentClosed = [](auto*, auto, auto*) {}
    ) {
        auto delegate = new LambdaShareCommentDelegate();
        delegate->m_shareCommentClosed = shareCommentClosed;
        delegate->autorelease();
        return delegate;
    }
};
