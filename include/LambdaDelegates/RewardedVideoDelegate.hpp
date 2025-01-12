#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/RewardedVideoDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaRewardedVideoDelegate : public cocos2d::CCObject, public RewardedVideoDelegate {
protected:
    std::function<void(LambdaRewardedVideoDelegate*)> m_rewardedVideoFinished;
    std::function<bool(LambdaRewardedVideoDelegate*)> m_shouldOffsetRewardCurrency;
public:
    void rewardedVideoFinished() override {
        if (m_rewardedVideoFinished) return m_rewardedVideoFinished(this);
    }
    bool shouldOffsetRewardCurrency() override {
        if (m_shouldOffsetRewardCurrency) return m_shouldOffsetRewardCurrency(this);
        return false;
    }

    static LambdaRewardedVideoDelegate* create(
        std::function<void(LambdaRewardedVideoDelegate*)> const& rewardedVideoFinished = [](auto*) {},
        std::function<bool(LambdaRewardedVideoDelegate*)> const& shouldOffsetRewardCurrency = [](auto*) { return false; }
    ) {
        auto delegate = new LambdaRewardedVideoDelegate();
        delegate->m_rewardedVideoFinished = rewardedVideoFinished;
        delegate->m_shouldOffsetRewardCurrency = shouldOffsetRewardCurrency;
        delegate->autorelease();
        return delegate;
    }
};
