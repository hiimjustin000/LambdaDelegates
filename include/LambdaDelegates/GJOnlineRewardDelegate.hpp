#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJOnlineRewardDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaGJOnlineRewardDelegate : public cocos2d::CCObject, public GJOnlineRewardDelegate {
public:
    std::function<void(gd::string)> m_onlineRewardStatusFinished;
    std::function<void()> m_onlineRewardStatusFailed;

    void onlineRewardStatusFinished(gd::string p0) override {
        return m_onlineRewardStatusFinished(p0);
    }
    void onlineRewardStatusFailed() override {
        return m_onlineRewardStatusFailed();
    }

    static LambdaGJOnlineRewardDelegate* create(
        std::function<void(gd::string)> const& onlineRewardStatusFinished = [](auto) {},
        std::function<void()> const& onlineRewardStatusFailed = []() {}
    ) {
        auto delegate = new LambdaGJOnlineRewardDelegate();
        delegate->m_onlineRewardStatusFinished = onlineRewardStatusFinished;
        delegate->m_onlineRewardStatusFailed = onlineRewardStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
