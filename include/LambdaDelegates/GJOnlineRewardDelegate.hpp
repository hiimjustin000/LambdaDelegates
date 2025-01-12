#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJOnlineRewardDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/c++stl/gdstdlib.hpp>

class LambdaGJOnlineRewardDelegate : public cocos2d::CCObject, public GJOnlineRewardDelegate {
protected:
    std::function<void(LambdaGJOnlineRewardDelegate*, gd::string)> m_onlineRewardStatusFinished;
    std::function<void(LambdaGJOnlineRewardDelegate*)> m_onlineRewardStatusFailed;
public:
    void onlineRewardStatusFinished(gd::string p0) override {
        if (m_onlineRewardStatusFinished) return m_onlineRewardStatusFinished(this, p0);
    }
    void onlineRewardStatusFailed() override {
        if (m_onlineRewardStatusFailed) return m_onlineRewardStatusFailed(this);
    }

    static LambdaGJOnlineRewardDelegate* create(
        std::function<void(LambdaGJOnlineRewardDelegate*, gd::string)> const& onlineRewardStatusFinished = [](auto*, auto) {},
        std::function<void(LambdaGJOnlineRewardDelegate*)> const& onlineRewardStatusFailed = [](auto*) {}
    ) {
        auto delegate = new LambdaGJOnlineRewardDelegate();
        delegate->m_onlineRewardStatusFinished = onlineRewardStatusFinished;
        delegate->m_onlineRewardStatusFailed = onlineRewardStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
