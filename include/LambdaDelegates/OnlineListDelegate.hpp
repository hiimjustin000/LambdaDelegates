#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/OnlineListDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaOnlineListDelegate : public cocos2d::CCObject, public OnlineListDelegate {
protected:
    std::function<void(LambdaOnlineListDelegate*, cocos2d::CCArray*, char const*)> m_loadListFinished;
    std::function<void(LambdaOnlineListDelegate*, char const*)> m_loadListFailed;
    std::function<void(LambdaOnlineListDelegate*, gd::string, char const*)> m_setupPageInfo;
public:
    void loadListFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadListFinished) return m_loadListFinished(this, p0, p1);
    }
    void loadListFailed(char const* p0) override {
        if (m_loadListFailed) return m_loadListFailed(this, p0);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        if (m_setupPageInfo) return m_setupPageInfo(this, p0, p1);
    }

    static LambdaOnlineListDelegate* create(
        std::function<void(LambdaOnlineListDelegate*, cocos2d::CCArray*, char const*)> const& loadListFinished = [](auto*, auto*, auto const*) {},
        std::function<void(LambdaOnlineListDelegate*, char const*)> const& loadListFailed = [](auto*, auto const*) {},
        std::function<void(LambdaOnlineListDelegate*, gd::string, char const*)> const& setupPageInfo = [](auto*, auto, auto const*) {}
    ) {
        auto delegate = new LambdaOnlineListDelegate();
        delegate->m_loadListFinished = loadListFinished;
        delegate->m_loadListFailed = loadListFailed;
        delegate->m_setupPageInfo = setupPageInfo;
        delegate->autorelease();
        return delegate;
    }
};
