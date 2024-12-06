#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/RewardedVideoDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaRewardedVideoDelegate : public cocos2d::CCObject, public RewardedVideoDelegate {
public:
    std::function<void()> m_rewardedVideoFinished;
    std::function<bool()> m_shouldOffsetRewardCurrency;

    void rewardedVideoFinished() override {
        if (m_rewardedVideoFinished) return m_rewardedVideoFinished();
    }
    bool shouldOffsetRewardCurrency() override {
        if (m_shouldOffsetRewardCurrency) return m_shouldOffsetRewardCurrency();
        return false;
    }

    static LambdaRewardedVideoDelegate* create(
        std::function<void()> const& rewardedVideoFinished = []() {},
        std::function<bool()> const& shouldOffsetRewardCurrency = []() { return false; }
    ) {
        auto delegate = new LambdaRewardedVideoDelegate();
        delegate->m_rewardedVideoFinished = rewardedVideoFinished;
        delegate->m_shouldOffsetRewardCurrency = shouldOffsetRewardCurrency;
        delegate->autorelease();
        return delegate;
    }
};
