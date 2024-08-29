#include "sf64audio_provisional.h"

#define RECOMP_EXPORT __attribute__((section(".recomp_export")))
#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#define RECOMP_FORCE_PATCH __attribute__((section(".recomp_force_patch")))

void AudioHeap_UnapplySampleCache(SampleCacheEntry* entry, Sample* sample);

// @recomp Fix undefined behaviour in audio, present in the original game
RECOMP_PATCH void AudioHeap_DiscardSampleCaches(void) {
    s32 fontId;
    s32 i;
    s32 numFonts = gSoundFontTable->base.numEntries;
    s32 pad;
    s32 sampleBankId2;
    s32 sampleBankId1;
    s32 instId;
    s32 drumId;
    Drum* drum;
    Instrument* instrument;
    SampleCacheEntry* entry;

    entry = gPersistentSampleCache.entries; // @recomp

    for (fontId = 0; fontId < numFonts; fontId++) {
        sampleBankId1 = gSoundFontList[fontId].sampleBankId1;
        sampleBankId2 = gSoundFontList[fontId].sampleBankId2;
        if (((sampleBankId1 != SAMPLES_NONE_U) && (entry->sampleBankId == sampleBankId1)) ||
            ((sampleBankId2 != SAMPLES_NONE) && (entry->sampleBankId == sampleBankId2)) ||
            (entry->sampleBankId == SAMPLES_SFX)) {
            if ((AudioHeap_SearchCaches(FONT_TABLE, CACHE_PERMANENT, fontId) != NULL) &&
                ((gFontLoadStatus[fontId] > 1) != 0)) {
                for (i = 0; i < gPersistentSampleCache.numEntries; i++) {
                    entry = &gPersistentSampleCache.entries[i];
                    for (instId = 0; instId < gSoundFontList[fontId].numInstruments; instId++) {
                        instrument = Audio_GetInstrument(fontId, instId);
                        if (instrument != NULL) {
                            if (instrument->normalRangeLo != 0) {
                                AudioHeap_UnapplySampleCache(entry, instrument->lowPitchTunedSample.sample);
                            }
                            if (instrument->normalRangeHi != 0x7F) {
                                AudioHeap_UnapplySampleCache(entry, instrument->highPitchTunedSample.sample);
                            }
                            AudioHeap_UnapplySampleCache(entry, instrument->normalPitchTunedSample.sample);
                        }
                    }
                    for (drumId = 0; drumId < gSoundFontList[fontId].numDrums; drumId++) {
                        drum = Audio_GetDrum(fontId, drumId);
                        if (drum != NULL) {
                            AudioHeap_UnapplySampleCache(entry, drum->tunedSample.sample);
                        }
                    }
                }
            }
        }
    }
}