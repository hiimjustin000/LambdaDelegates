#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJRewardDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJRewardDelegate : public cocos2d::CCObject, public GJRewardDelegate {
public:
    std::function<void(int)> m_rewardsStatusFinished;
    std::function<void()> m_rewardsStatusFailed;

    void rewardsStatusFinished(int p0) override {
        if (m_rewardsStatusFinished) return m_rewardsStatusFinished(p0);
    }
    void rewardsStatusFailed() override {
        if (m_rewardsStatusFailed) return m_rewardsStatusFailed();
    }

    static LambdaGJRewardDelegate* create(
        std::function<void(int)> const& rewardsStatusFinished = [](auto) {},
        std::function<void()> const& rewardsStatusFailed = []() {}
    ) {
        auto delegate = new LambdaGJRewardDelegate();
        delegate->m_rewardsStatusFinished = rewardsStatusFinished;
        delegate->m_rewardsStatusFailed = rewardsStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
