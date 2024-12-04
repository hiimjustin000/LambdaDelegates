#include <Geode/Geode.hpp>
#include <LambdaDelegates.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
    struct Fields {
        LambdaLevelDownloadDelegate* m_levelDownloadDelegate;
        ~Fields() {
            auto glm = GameLevelManager::sharedState();
            if (glm->m_levelDownloadDelegate == m_levelDownloadDelegate) glm->m_levelDownloadDelegate = nullptr;
            CC_SAFE_RELEASE(m_levelDownloadDelegate);
        }
    };

    void onMoreGames(CCObject* sender) {
        MenuLayer::onMoreGames(sender);

        auto f = m_fields.self();
        f->m_levelDownloadDelegate = LambdaLevelDownloadDelegate::create([](GJGameLevel* p0) {
            FLAlertLayer::create("Success", fmt::format("Level {} downloaded successfully!", format_as(p0)).c_str(), "OK")->show();
        }, [](int p0) {
            FLAlertLayer::create("Error", fmt::format("Failed to download level: {}", p0).c_str(), "OK")->show();
        });
        f->m_levelDownloadDelegate->retain();
        auto glm = GameLevelManager::sharedState();
        glm->m_levelDownloadDelegate = f->m_levelDownloadDelegate;
        glm->downloadLevel(107134657, false); // NOMU by Uproxide
    }
};
