/*
* Audacity: A Digital Audio Editor
*/
#pragma once

#include <gmock/gmock.h>

#include "trackedit/iselectioncontroller.h"

namespace au::trackedit {
class SelectionControllerMock : public ISelectionController
{
public:
    MOCK_METHOD(void, resetSelectedTracks, (), (override));
    MOCK_METHOD(TrackIdList, selectedTracks, (), (const, override));
    MOCK_METHOD(void, setSelectedTracks, (const TrackIdList&, bool), (override));
    MOCK_METHOD(void, addSelectedTrack, (const trackedit::TrackId&), (override));
    MOCK_METHOD(muse::async::Channel<TrackIdList>, tracksSelected, (), (const, override));

    MOCK_METHOD(void, resetSelectedClips, (), (override));
    MOCK_METHOD(ClipKeyList, selectedClips, (), (const, override));
    MOCK_METHOD(void, setSelectedClips, (const ClipKeyList&), (override));
    MOCK_METHOD(void, addSelectedClip, (const ClipKey& clipKey), (override));
    MOCK_METHOD(muse::async::Channel<ClipKeyList>, clipsSelected, (), (const, override));
    MOCK_METHOD(double, selectedClipStartTime, (), (const, override));
    MOCK_METHOD(double, selectedClipEndTime, (), (const, override));

    MOCK_METHOD(void, setSelectedTrackAudioData, (TrackId), (override));
    MOCK_METHOD(void, setSelectedClipAudioData, (TrackId, secs_t), (override));
    MOCK_METHOD(void, resetDataSelection, (), (override));
    MOCK_METHOD(bool, timeSelectionIsNotEmpty, (), (const, override));
    MOCK_METHOD(bool, isDataSelectedOnTrack, (TrackId), (const, override));

    MOCK_METHOD(secs_t, dataSelectedStartTime, (), (const, override));
    MOCK_METHOD(void, setDataSelectedStartTime, (secs_t, bool), (override));
    MOCK_METHOD(muse::async::Channel<secs_t>, dataSelectedStartTimeChanged, (), (const, override));
    MOCK_METHOD(muse::async::Channel<secs_t>, dataSelectedStartTimeSelected, (), (const, override));

    MOCK_METHOD(secs_t, dataSelectedEndTime, (), (const, override));
    MOCK_METHOD(void, setDataSelectedEndTime, (secs_t, bool), (override));
    MOCK_METHOD(muse::async::Channel<secs_t>, dataSelectedEndTimeChanged, (), (const, override));
    MOCK_METHOD(muse::async::Channel<secs_t>, dataSelectedEndTimeSelected, (), (const, override));
};
}