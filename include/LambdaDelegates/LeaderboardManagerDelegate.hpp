#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LeaderboardManagerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLeaderboardManagerDelegate : public cocos2d::CCObject, public LeaderboardManagerDelegate {
public:
    std::function<void()> m_updateUserScoreFinished;
    std::function<void()> m_updateUserScoreFailed;
    std::function<void(cocos2d::CCArray*, char const*)> m_loadLeaderboardFinished;
    std::function<void(char const*)> m_loadLeaderboardFailed;

    void updateUserScoreFinished() override {
        if (m_updateUserScoreFinished) return m_updateUserScoreFinished();
    }
    void updateUserScoreFailed() override {
        if (m_updateUserScoreFailed) return m_updateUserScoreFailed();
    }
    void loadLeaderboardFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadLeaderboardFinished) return m_loadLeaderboardFinished(p0, p1);
    }
    void loadLeaderboardFailed(char const* p0) override {
        if (m_loadLeaderboardFailed) return m_loadLeaderboardFailed(p0);
    }

    static LambdaLeaderboardManagerDelegate* create(
        std::function<void()> const& updateUserScoreFinished = []() {},
        std::function<void()> const& updateUserScoreFailed = []() {},
        std::function<void(cocos2d::CCArray*, char const*)> const& loadLeaderboardFinished = [](auto, auto) {},
        std::function<void(char const*)> const& loadLeaderboardFailed = [](auto) {}
    ) {
        auto delegate = new LambdaLeaderboardManagerDelegate();
        delegate->m_updateUserScoreFinished = updateUserScoreFinished;
        delegate->m_updateUserScoreFailed = updateUserScoreFailed;
        delegate->m_loadLeaderboardFinished = loadLeaderboardFinished;
        delegate->m_loadLeaderboardFailed = loadLeaderboardFailed;
        delegate->autorelease();
        return delegate;
    }
};
