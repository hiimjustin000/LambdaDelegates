#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/OnlineListDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaOnlineListDelegate : public cocos2d::CCObject, public OnlineListDelegate {
public:
    std::function<void(cocos2d::CCArray*, char const*)> m_loadListFinished;
    std::function<void(char const*)> m_loadListFailed;
    std::function<void(gd::string, char const*)> m_setupPageInfo;

    void loadListFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadListFinished) return m_loadListFinished(p0, p1);
    }
    void loadListFailed(char const* p0) override {
        if (m_loadListFailed) return m_loadListFailed(p0);
    }
    void setupPageInfo(gd::string p0, char const* p1) override {
        if (m_setupPageInfo) return m_setupPageInfo(p0, p1);
    }

    static LambdaOnlineListDelegate* create(
        std::function<void(cocos2d::CCArray*, char const*)> const& loadListFinished = [](auto, auto) {},
        std::function<void(char const*)> const& loadListFailed = [](auto) {},
        std::function<void(gd::string, char const*)> const& setupPageInfo = [](auto, auto) {}
    ) {
        auto delegate = new LambdaOnlineListDelegate();
        delegate->m_loadListFinished = loadListFinished;
        delegate->m_loadListFailed = loadListFailed;
        delegate->m_setupPageInfo = setupPageInfo;
        delegate->autorelease();
        return delegate;
    }
};
