#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GJRewardDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGJRewardDelegate : public cocos2d::CCObject, public GJRewardDelegate {
protected:
    std::function<void(LambdaGJRewardDelegate*, int)> m_rewardsStatusFinished;
    std::function<void(LambdaGJRewardDelegate*)> m_rewardsStatusFailed;
public:
    void rewardsStatusFinished(int p0) override {
        if (m_rewardsStatusFinished) return m_rewardsStatusFinished(this, p0);
    }
    void rewardsStatusFailed() override {
        if (m_rewardsStatusFailed) return m_rewardsStatusFailed(this);
    }

    static LambdaGJRewardDelegate* create(
        std::function<void(LambdaGJRewardDelegate*, int)> const& rewardsStatusFinished = [](auto*, auto) {},
        std::function<void(LambdaGJRewardDelegate*)> const& rewardsStatusFailed = [](auto*) {}
    ) {
        auto delegate = new LambdaGJRewardDelegate();
        delegate->m_rewardsStatusFinished = rewardsStatusFinished;
        delegate->m_rewardsStatusFailed = rewardsStatusFailed;
        delegate->autorelease();
        return delegate;
    }
};
