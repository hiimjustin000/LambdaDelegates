#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/LeaderboardManagerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaLeaderboardManagerDelegate : public cocos2d::CCObject, public LeaderboardManagerDelegate {
protected:
    std::function<void(LambdaLeaderboardManagerDelegate*)> m_updateUserScoreFinished;
    std::function<void(LambdaLeaderboardManagerDelegate*)> m_updateUserScoreFailed;
    std::function<void(LambdaLeaderboardManagerDelegate*, cocos2d::CCArray*, char const*)> m_loadLeaderboardFinished;
    std::function<void(LambdaLeaderboardManagerDelegate*, char const*)> m_loadLeaderboardFailed;
public:
    void updateUserScoreFinished() override {
        if (m_updateUserScoreFinished) return m_updateUserScoreFinished(this);
    }
    void updateUserScoreFailed() override {
        if (m_updateUserScoreFailed) return m_updateUserScoreFailed(this);
    }
    void loadLeaderboardFinished(cocos2d::CCArray* p0, char const* p1) override {
        if (m_loadLeaderboardFinished) return m_loadLeaderboardFinished(this, p0, p1);
    }
    void loadLeaderboardFailed(char const* p0) override {
        if (m_loadLeaderboardFailed) return m_loadLeaderboardFailed(this, p0);
    }

    static LambdaLeaderboardManagerDelegate* create(
        std::function<void(LambdaLeaderboardManagerDelegate*)> const& updateUserScoreFinished = [](auto*) {},
        std::function<void(LambdaLeaderboardManagerDelegate*)> const& updateUserScoreFailed = [](auto*) {},
        std::function<void(LambdaLeaderboardManagerDelegate*, cocos2d::CCArray*, char const*)> const& loadLeaderboardFinished = [](auto*, auto*, auto const*) {},
        std::function<void(LambdaLeaderboardManagerDelegate*, char const*)> const& loadLeaderboardFailed = [](auto*, auto const*) {}
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
