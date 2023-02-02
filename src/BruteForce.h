#pragma once

class BruteForce : public RE::BSTEventSink<RE::TESHitEvent> {
    BruteForce() = default;
    BruteForce(const BruteForce&) = delete;
    BruteForce(BruteForce&&) = delete;
    BruteForce& operator=(const BruteForce&) = delete;
    BruteForce& operator=(BruteForce&&) = delete;

    public:
        [[nodiscard]] static BruteForce* GetSingleton();
        RE::BSEventNotifyControl ProcessEvent(const RE::TESHitEvent* event, RE::BSTEventSource<RE::TESHitEvent>*);
        enum WEAP_MATERIAL {
            kIron,
            kSteel,
            kSilver,
            kImperial,
            kElven,
            kDwarven,
            kOrcish,
            kNordic,
            kEbony,
            kStalhrim,
            kGlass,
            kDaedric,
            kDragonbone,
        };

    private:
        void UnlockObject(RE::TESObjectREFR* refr);
        void HitThatLock(RE::TESObjectREFR* refr, RE::TESObjectWEAP* weapon, std::string_view formList);
        std::string_view GetFormList(RE::TESObjectREFRPtr refr);
        void UnlockWithTwoHandedOnly(RE::TESObjectREFR* refr, RE::TESObjectWEAP* weapon, bool PlayerSkillMatches,
                                     bool IsUsingSkillRequirement);
        void UnlockWithBluntOnly(RE::TESObjectREFR* refr, RE::TESObjectWEAP* weapon, bool PlayerSkillMatches,
                                 bool IsUsingSkillRequirement);
        void UnlockWithBluntAndTwoHanded(RE::TESObjectREFR* refr, RE::TESObjectWEAP* weapon, bool PlayerSkillMatches,
                                         bool IsUsingSkillRequirement);
        void UnlockBasedOnMaterial(RE::TESObjectREFR* refr, bool IsUsingSkillRequirement, bool PlayerSkillMatches);
};