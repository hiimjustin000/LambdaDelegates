#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/MusicDownloadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaMusicDownloadDelegate : public cocos2d::CCObject, public MusicDownloadDelegate {
public:
    std::function<void(SongInfoObject*)> m_loadSongInfoFinished;
    std::function<void(int, GJSongError)> m_loadSongInfoFailed;
    std::function<void(int)> m_downloadSongFinished;
    std::function<void(int, GJSongError)> m_downloadSongFailed;
    std::function<void()> m_songStateChanged;
    std::function<void(int)> m_downloadSFXFinished;
    std::function<void(int, GJSongError)> m_downloadSFXFailed;
    std::function<void(GJMusicAction)> m_musicActionFinished;
    std::function<void(GJMusicAction)> m_musicActionFailed;

    void loadSongInfoFinished(SongInfoObject* p0) override {
        return m_loadSongInfoFinished(p0);
    }
    void loadSongInfoFailed(int p0, GJSongError p1) override {
        return m_loadSongInfoFailed(p0, p1);
    }
    void downloadSongFinished(int p0) override {
        return m_downloadSongFinished(p0);
    }
    void downloadSongFailed(int p0, GJSongError p1) override {
        return m_downloadSongFailed(p0, p1);
    }
    void songStateChanged() override {
        return m_songStateChanged();
    }
    void downloadSFXFinished(int p0) override {
        return m_downloadSFXFinished(p0);
    }
    void downloadSFXFailed(int p0, GJSongError p1) override {
        return m_downloadSFXFailed(p0, p1);
    }
    void musicActionFinished(GJMusicAction p0) override {
        return m_musicActionFinished(p0);
    }
    void musicActionFailed(GJMusicAction p0) override {
        return m_musicActionFailed(p0);
    }

    static LambdaMusicDownloadDelegate* create(
        std::function<void(SongInfoObject*)> const& loadSongInfoFinished = [](auto) {},
        std::function<void(int, GJSongError)> const& loadSongInfoFailed = [](auto, auto) {},
        std::function<void(int)> const& downloadSongFinished = [](auto) {},
        std::function<void(int, GJSongError)> const& downloadSongFailed = [](auto, auto) {},
        std::function<void()> const& songStateChanged = []() {},
        std::function<void(int)> const& downloadSFXFinished = [](auto) {},
        std::function<void(int, GJSongError)> const& downloadSFXFailed = [](auto, auto) {},
        std::function<void(GJMusicAction)> const& musicActionFinished = [](auto) {},
        std::function<void(GJMusicAction)> const& musicActionFailed = [](auto) {}
    ) {
        auto delegate = new LambdaMusicDownloadDelegate();
        delegate->m_loadSongInfoFinished = loadSongInfoFinished;
        delegate->m_loadSongInfoFailed = loadSongInfoFailed;
        delegate->m_downloadSongFinished = downloadSongFinished;
        delegate->m_downloadSongFailed = downloadSongFailed;
        delegate->m_songStateChanged = songStateChanged;
        delegate->m_downloadSFXFinished = downloadSFXFinished;
        delegate->m_downloadSFXFailed = downloadSFXFailed;
        delegate->m_musicActionFinished = musicActionFinished;
        delegate->m_musicActionFailed = musicActionFailed;
        delegate->autorelease();
        return delegate;
    }
};
