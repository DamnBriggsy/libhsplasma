/* This file is part of HSPlasma.
 *
 * HSPlasma is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HSPlasma is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PDUNIFIEDTYPEMAP_H
#define _PDUNIFIEDTYPEMAP_H

#include "PlasmaDefs.h"
#include "Util/PlasmaVersions.h"

#define TYPESPACE_MAX 0x500

DllClass pdUnifiedTypeMap {
private:
    static short fUruM2PTable[TYPESPACE_MAX];
    static short fPotSM2PTable[TYPESPACE_MAX];
    static short fLiveM2PTable[TYPESPACE_MAX];
    static short fEoaM2PTable[TYPESPACE_MAX];
    static short fHexM2PTable[TYPESPACE_MAX];
    static short fUruP2MTable[TYPESPACE_MAX];
    static short fPotSP2MTable[TYPESPACE_MAX];
    static short fLiveP2MTable[TYPESPACE_MAX];
    static short fEoaP2MTable[TYPESPACE_MAX];
    static short fHexP2MTable[TYPESPACE_MAX];

    static short fEoaVerTable[TYPESPACE_MAX];
    static short fHexVerTable[TYPESPACE_MAX];   // TODO: Probably incorrect
    static const char* fClassNames[TYPESPACE_MAX];

public:
    static const char* ClassName(short typeIdx);
    static const char* ClassName(short typeIdx, PlasmaVer ver);
    static short ClassIndex(const char* typeName);

    static short PlasmaToMapped(short typeIdx, PlasmaVer ver);
    static short MappedToPlasma(short typeIdx, PlasmaVer ver);

    static short ClassVersion(short typeIdx, PlasmaVer ver);
};

// This is the internal mapped types list:
typedef enum {
    kSceneNode, kSceneObject, kKeyedObject, kBitmap, kMipmap, kCubicEnvironmap,
    kLayer, kGMaterial, kParticleSystem, kParticleEffect,
    kParticleCollisionEffectBeat, kParticleFadeVolumeEffect, kBoundInterface,
    kRenderTarget, kCubicRenderTarget, kCubicRenderTargetModifier,
    kObjInterface, kAudioInterface, kAudible, kAudibleNull, kWinAudible,
    kCoordinateInterface, kDrawInterface, kDrawable, kDrawableMesh,
    kDrawableIce, kPhysical, kPhysicalMesh, kSimulationInterface,
    kCameraModifier, kModifier, kSingleModifier, kSimpleModifier,
    kSimpleTMModifier, kRandomTMModifier, kInterestingModifier,
    kDetectorModifier, kSimplePhysicalMesh, kCompoundPhysicalMesh,
    kMultiModifier, kSynchedObject, kSoundBuffer, kAliasModifier,
    kPickingDetector, kCollisionDetector, kLogicModifier, kConditionalObject,
    kANDConditionalObject, kORConditionalObject, kPickedConditionalObject,
    kActivatorConditionalObject, kTimerCallbackManager,
    kKeyPressConditionalObject, kAnimationEventConditionalObject,
    kControlEventConditionalObject, kObjectInBoxConditionalObject,
    kLocalPlayerInBoxConditionalObject, kObjectIntersectPlaneConditionalObject,
    kLocalPlayerIntersectPlaneConditionalObject, kPortalDrawable,
    kPortalPhysical, kSpawnModifier, kFacingConditionalObject, kGenericPhysical,
    kViewFaceModifier, kLayerInterface, kLayerWrapper, kLayerAnimation,
    kLayerDepth, kLayerMovie, kLayerBink, kLayerAVI, kSound, kWin32Sound,
    kLayerOr, kAudioSystem, kDrawableSpans, kDrawablePatchSet, kInputManager,
    kLogicModBase, kFogEnvironment, kNetApp, kNetClientMgr, k2WayWinAudible,
    kLightInfo, kDirectionalLightInfo, kOmniLightInfo, kSpotLightInfo,
    kLightSpace, kNetClientApp, kNetServerApp, kClient, kCompoundTMModifier,
    kCameraBrain, kCameraBrain_Default, kCameraBrain_Drive, kCameraBrain_Fixed,
    kCameraBrain_FixedPan, kGUIClickMapCtrl, kListener, kAvatarMod, kAvatarAnim,
    kAvatarAnimMgr, kOccluder, kMobileOccluder, kLayerShadowBase,
    kLimitedDirLightInfo, kAGAnim, kAGModifier, kAGMasterMod,
    kCameraBrain_Avatar, kCameraRegionDetector, kCameraBrain_FP, kLineFollowMod,
    kLightModifier, kOmniModifier, kSpotModifier, kLtdDirModifier,
    kSeekPointMod, kOneShotMod, kRandomCommandMod, kRandomSoundMod,
    kPostEffectMod, kObjectInVolumeDetector, kResponderModifier,
    kAxisAnimModifier, kLayerLightBase, kFollowMod, kTransitionMgr,
    kInventoryMod, kInventoryObjMod, kLinkEffectsMgr, kWin32StreamingSound,
    kPythonMod, kActivatorActivatorConditionalObject, kSoftVolume,
    kSoftVolumeSimple, kSoftVolumeComplex, kSoftVolumeUnion,
    kSoftVolumeIntersect, kSoftVolumeInvert, kWin32LinkSound,
    kLayerLinkAnimation, kArmatureMod, kCameraBrain_Freelook,
    kHavokConstraintsMod, kHingeConstraintMod, kWheelConstraintMod,
    kStrongSpringConstraintMod, kArmatureLODMod, kWin32StaticSound, kGameGUIMgr,
    kGUIDialogMod, kCameraBrain1, kVirtualCam1, kCameraModifier1_UNUSED,
    kCameraBrain1_Drive, kCameraBrain1_POA, kCameraBrain1_Avatar,
    kCameraBrain1_Fixed, kCameraBrain1_POAFixed, kGUIButtonMod, kPythonFileMod,
    kGUIControlMod, kExcludeRegionModifier, kGUIDraggableMod,
    kVolumeSensorConditionalObject, kVolActivatorConditionalObject,
    kMsgForwarder, kBlower, kGUIListBoxMod, kGUITextBoxMod, kGUIEditBoxMod,
    kDynamicTextMap, kSittingModifier, kGUIUpDownPairMod, kGUIValueCtrl,
    kGUIKnobCtrl, kAvLadderMod, kCameraBrain1_FirstPerson, kCloneSpawnModifier,
    kClothingItem, kClothingOutfit, kClothingBase, kClothingMgr,
    kGUIDragBarCtrl, kGUICheckBoxCtrl, kGUIRadioGroupCtrl, kPlayerBookMod,
    kGUIDynDisplayCtrl, kLayerProject, kInputInterfaceMgr, kRailCameraMod,
    kMultistageBehMod, kCameraBrain1_Circle, kParticleWindEffect,
    kAnimEventModifier, kAutoProfile, kGUISkin, kAVIWriter,
    kParticleCollisionEffect, kParticleCollisionEffectDie,
    kParticleCollisionEffectBounce, kInterfaceInfoModifier, kSharedMesh,
    kArmatureEffectsMgr, kMarkerMgr, kVehicleModifier, kParticleLocalWind,
    kParticleUniformWind, kInstanceDrawInterface, kShadowMaster, kShadowCaster,
    kPointShadowMaster, kDirectShadowMaster, kSDLModifier, kPhysicalSDLModifier,
    kClothingSDLModifier, kAvatarSDLModifier, kAGMasterSDLModifier,
    kPythonSDLModifier, kLayerSDLModifier, kAnimTimeConvertSDLModifier,
    kResponderSDLModifier, kSoundSDLModifier, kResManagerHelper, kHKSubWorld,
    kArmatureEffect, kArmatureEffectFootSound, kEAXListenerMod, kDynaDecalMgr,
    kObjectInVolumeAndFacingDetector, kDynaFootMgr, kDynaRippleMgr,
    kDynaBulletMgr, kDecalEnableMod, kPrintShape, kDynaPuddleMgr,
    kGUIMultiLineEditCtrl, kLayerAnimationBase, kLayerSDLAnimation, kATCAnim,
    kAgeGlobalAnim, kSubworldRegionDetector, kAvatarMgr, kNPCSpawnMod,
    kActivePrintShape, kExcludeRegionSDLModifier, kLOSDispatch, kDynaWakeMgr,
    kSimulationMgr, kWaveSet7, kPanicLinkRegion, kWin32GroupedSound,
    kFilterCoordInterface, kStereizer, kCCRMgr, kCCRSpecialist,
    kCCRSeniorSpecialist, kCCRShiftSupervisor, kCCRGameOperator, kShader,
    kDynamicEnvMap, kSimpleRegionSensor, kMorphSequence, kEmoteAnim,
    kDynaRippleVSMgr, kWaveSet6, kGUIProgressCtrl, kMaintainersMarkerModifier,
    kMorphSequenceSDLMod, kMorphDataSet, kHardRegion, kHardRegionPlanes,
    kHardRegionComplex, kHardRegionUnion, kHardRegionIntersect,
    kHardRegionInvert, kVisRegion, kVisMgr, kRegionBase, kGUIPopUpMenu,
    kGUIMenuItem, kCoopCoordinator, kFont, kFontCache, kRelevanceRegion,
    kRelevanceMgr, kJournalBook, kLayerTargetContainer, kImageLibMod,
    kParticleFlockEffect, kParticleSDLMod, kAgeLoader, kWaveSetBase,
    kPhysicalSndGroup, kBookData, kDynaTorpedoMgr, kDynaTorpedoVSMgr,
    kClusterGroup, kGameMarkerModifier, kLODMipmap, kSwimDetector,
    kFadeOpacityMod, kFadeOpacityLay, kDistOpacityMod, kArmatureModBase,
    kSwimRegionInterface, kSwimCircularCurrentRegion,
    kParticleFollowSystemEffect, kSwimStraightCurrentRegion, kObjectFlocker,
    kGrassShaderMod, kDynamicCamMap, kSwimRegion_UNUSED, kPXPhysical_UNUSED,
    kODEPhysical_UNUSED, kAutoWalkRegion, kCrossfade, kParticleFadeOutEffect,
    kSecurePreloader, kWindBoneMod, kCameraBrain_NovicePlus, kSubtitleMgr,
    kPythonFileModConditionalObject, kLayerTransform, kBubbleShaderMod,
    kLineFollowModBase, kClientApp, kGUICreditsCtrl, kCameraBrainUru,
    kVirtualCamera, kCameraBrainUru_Drive, kCameraBrainUru_Follow,
    kCameraBrainUru_Fixed, kGUISketchCtrl, kLadderModifier,
    kCameraBrainUru_FirstPerson, kCameraBrainUru_Circle, kEAXReverbEffect,
    kSpawnMod, kCameraBrain_Novice, kAvatarPhysicalSDLModifier,
    kDirectMusicSound, kClientSessionMgr, kSDLVarChangeNotifier,
    kInterestWellModifier, kElevatorModifier, kCameraBrain_Expert,
    kPagingRegionModifier, kGuidepathModifier, kNodeMgr, kEAXEffect,
    kEAXPitchShifter, kIKModifier, kCameraBrain_M5, kAGAnimBink, kTreeShader,
    kNodeRegionModifier, kPiranhaRegionModifier,
    kRidingAnimatedPhysicalDetector,
    kVolumeSensorConditionalObjectNoArbitration, kFXMaterial, kMovableMod,
    kMaterial, kEffect, kParticleBulletEffect, kCameraBrain_Ground,
    kCameraBrain_Flight,
    
    kObjRefMsg = 0x200, kNodeRefMsg, kMessage, kRefMsg, kGenRefMsg, kTimeMsg,
    kAnimCmdMsg, kParticleUpdateMsg, kLayRefMsg, kMatRefMsg, kCameraMsg,
    kInputEventMsg, kKeyEventMsg, kMouseEventMsg, kEvalMsg, kTransformMsg,
    kControlEventMsg, kVaultCCRNode, kLOSRequestMsg, kLOSHitMsg, kSingleModMsg,
    kMultiModMsg, kAvatarPhysicsEnableCallbackMsg, kMemberUpdateMsg,
    kNetMsgPagingRoom, kActivatorMsg, kDispatch, kReceiver, kMeshRefMsg,
    kGRenderProcs, kSfxAngleFade, kSfxDistFade, kSfxDistShade, kSfxGlobalShade,
    kSfxIntenseAlpha, kSfxObjDistFade, kSfxObjDistShade, kDynamicValue,
    kDynamicScalar, kDynamicColorRGBA, kDynamicMatrix33, kDynamicMatrix44,
    kController, kLeafController, kScaleController, kRotController,
    kPosController, kScalarController, kPoint3Controller, kScaleValueController,
    kQuatController, kMatrix33Controller, kMatrix44Controller, kEaseController,
    kSimpleScaleController, kSimpleRotController, kCompoundRotController,
    kSimplePosController, kCompoundPosController, kTMController, kFogControl,
    kIntRefMsg, kCollisionReactor, kCorrectionMsg, kPhysicalModifier,
    kPickedMsg, kCollideMsg, kTriggerMsg, kInterestingModMsg, kDebugKeyEventMsg,
    kPhysicalProperties, kSimplePhys, kMatrixUpdateMsg, kCondRefMsg,
    kTimerCallbackMsg, kEventCallbackMsg, kSpawnModMsg, kSpawnRequestMsg,
    kLoadCloneMsg, kEnableMsg, kWarpMsg, kAttachMsg, kConsole, kRenderMsg,
    kAnimTimeConvert, kSoundMsg, kInterestingPing, kNodeCleanupMsg, kSpaceTree,
    kNetMessage, kNetMsgJoinReq, kNetMsgJoinAck, kNetMsgLeave, kNetMsgPing,
    kNetMsgRoomsList, kNetMsgGroupOwner, kNetMsgGameStateRequest,
    kNetMsgSessionReset, kNetMsgOmnibus, kNetMsgObject, kCCRInvisibleMsg,
    kLinkInDoneMsg, kNetMsgGameMessage, kNetMsgStream, kAudioSysMsg,
    kDispatchBase, kServerReplyMsg, kDeviceRecreateMsg, kNetMsgStreamHelper,
    kNetMsgObjectHelper, kIMouseXEventMsg, kIMouseYEventMsg, kIMouseBEventMsg,
    kLogicTriggerMsg, kPipeline, kDX8Pipeline, kNetMsgVoice, kLightRefMsg,
    kNetMsgStreamedObject, kNetMsgSharedState, kNetMsgTestAndSet,
    kNetMsgGetSharedState, kSharedStateMsg, kNetGenericServerTask,
    kNetLookupServerGetAgeInfoFromVaultTask, kLoadAgeMsg, kMessageWithCallbacks,
    kClientMsg, kClientRefMsg, kNetMsgObjStateRequest, kCCRPetitionMsg,
    kVaultCCRInitializationTask, kNetServerMsg, kNetServerMsgWithContext,
    kNetServerMsgRegisterServer, kNetServerMsgUnregisterServer,
    kNetServerMsgStartProcess, kNetServerMsgRegisterProcess,
    kNetServerMsgUnregisterProcess, kNetServerMsgFindProcess,
    kNetServerMsgProcessFound, kNetMsgRoutingInfo, kNetServerSessionInfo,
    kSimulationMsg, kSimulationSynchMsg, kHKSimulationSynchMsg, kAvatarMsg,
    kAvTaskMsg, kAvSeekMsg, kAvOneShotMsg, kSatisfiedMsg,
    kNetMsgObjectListHelper, kNetMsgObjectUpdateFilter, kProxyDrawMsg,
    kSelfDestructMsg, kSimInfluenceMsg, kForceMsg, kOffsetForceMsg, kTorqueMsg,
    kImpulseMsg, kOffsetImpulseMsg, kAngularImpulseMsg, kDampMsg, kShiftMassMsg,
    kSimStateMsg, kFreezeMsg, kEventGroupMsg, kSuspendEventMsg,
    kNetMsgMembersListReq, kNetMsgMembersList, kNetMsgMemberInfoHelper,
    kNetMsgMemberListHelper, kNetMsgMemberUpdate, kNetMsgServerToClient,
    kNetMsgCreatePlayer, kNetMsgAuthenticateHello, kNetMsgAuthenticateChallenge,
    kConnectedToVaultMsg, kCCRCommunicationMsg, kNetMsgInitialAgeStateSent,
    kInitialAgeStateLoadedMsg, kNetServerMsgFindServerBase,
    kNetServerMsgFindServerReplyBase, kNetServerMsgFindAuthServer,
    kNetServerMsgFindAuthServerReply, kNetServerMsgFindVaultServer,
    kNetServerMsgFindVaultServerReply, kAvTaskSeekDoneMsg,
    kAvatarSpawnNotifyMsg, kNetServerMsgVaultTask, kNetMsgVaultTask,
    kAgeLinkStruct, kVaultAgeInfoNode, kNetMsgStreamableHelper,
    kNetMsgReceiversListHelper, kNetMsgListenListUpdate, kNetServerMsgPing,
    kNetMsgAlive, kNetMsgTerminated, kSDLModifierMsg, kNetMsgSDLState,
    kNetServerMsgSessionReset, kCCRBanLinkingMsg, kCCRSilencePlayerMsg,
    kRenderRequestMsg, kRenderRequestAck, kNetMember, kNetGameMember,
    kNetTransportMember, kConvexVolume, kParticleGenerator,
    kSimpleParticleGenerator, kParticleEmitter, kAGChannel, kMatrixChannel,
    kMatrixTimeScale, kMatrixBlend, kMatrixControllerChannel, kQuatPointCombine,
    kPointChannel, kPointConstant, kPointBlend, kQuatChannel, kQuatConstant,
    kQuatBlend, kLinkToAgeMsg, kPlayerPageMsg, kCmdIfaceModMsg,
    kNetServerMsgPlsUpdatePlayer, kListenerMsg, kAnimPath, kClothingUpdateBCMsg,
    kNotifyMsg, kFakeOutMsg, kCursorChangeMsg, kNodeChangeMsg, kAvEnableMsg,
    kLinkCallbackMsg, kTransitionMsg, kConsoleMsg, kVolumeIsect, kSphereIsect,
    kConeIsect, kCylinderIsect, kParallelIsect, kConvexIsect, kComplexIsect,
    kUnionIsect, kIntersectionIsect, kModulator, kInventoryMsg,
    kLinkEffectsTriggerMsg, kLinkEffectBCMsg, kResponderEnableMsg,
    kNetServerMsgHello, kNetServerMsgHelloReply, kNetServerMember,
    kResponderMsg, kOneShotMsg, kVaultAgeInfoListNode,
    kNetServerMsgServerRegistered, kPointTimeScale, kPointControllerChannel,
    kQuatTimeScale, kAGApplicator, kMatrixChannelApplicator,
    kPointChannelApplicator, kLightDiffuseApplicator, kLightAmbientApplicator,
    kLightSpecularApplicator, kOmniApplicator, kQuatChannelApplicator,
    kScalarChannel, kScalarTimeScale, kScalarBlend, kScalarControllerChannel,
    kScalarChannelApplicator, kSpotInnerApplicator, kSpotOuterApplicator,
    kNetServerMsgPlsRoutableMsg, kPuppetBrainMsg, kATCEaseCurve,
    kConstAccelEaseCurve, kSplineEaseCurve, kVaultAgeInfoInitializationTask,
    kGameGUIMsg, kNetServerMsgVaultRequestGameState,
    kNetServerMsgVaultGameState, kNetServerMsgVaultGameStateSave,
    kNetServerMsgVaultGameStateSaved, kNetServerMsgVaultGameStateLoad,
    kNetClientTask, kNetMsgSDLStateBCast, kReplaceGeometryMsg,
    kNetServerMsgExitProcess, kNetServerMsgSaveGameState, kDniCoordinateInfo,
    kNetMsgGameMessageDirected, kLinkOutUnloadMsg, kScalarConstant,
    kMatrixConstant, kAGCmdMsg, kParticleTransferMsg, kParticleKillMsg,
    kExcludeRegionMsg, kOneTimeParticleGenerator, kParticleApplicator,
    kParticleLifeMinApplicator, kParticleLifeMaxApplicator,
    kParticlePPSApplicator, kParticleAngleApplicator, kParticleVelMinApplicator,
    kParticleVelMaxApplicator, kParticleScaleMinApplicator,
    kParticleScaleMaxApplicator, kDynamicTextMsg, kCameraTargetFadeMsg,
    kAgeLoadedMsg, kPointControllerCacheChannel, kScalarControllerCacheChannel,
    kLinkEffectsTriggerPrepMsg, kLinkEffectPrepBCMsg, kAvatarInputStateMsg,
    kAgeInfoStruct, kSDLNotificationMsg, kNetClientConnectAgeVaultTask,
    kLinkingMgrMsg, kVaultNotifyMsg, kPlayerInfo, kSwapSpansRefMsg, kKI,
    kDISpansMsg, kNetMsgCreatableHelper, kServerGuid,
    kNetMsgRequestMyVaultPlayerList, kDelayedTransformMsg,
    kSuperVNodeMgrInitTask, kElementRefMsg, kClothingMsg, kEventGroupEnableMsg,
    kGUINotifyMsg, kAvBrain, kArmatureBrain, kAvBrainHuman, kAvBrainCritter,
    kAvBrainDrive, kAvBrainSample, kAvBrainGeneric, kAvBrainPuppet,
    kAvBrainLadder, kInputIfaceMgrMsg, kKIMsg, kRemoteAvatarInfoMsg,
    kMatrixDelayedCorrectionApplicator, kAvPushBrainMsg, kAvPopBrainMsg,
    kRoomLoadNotifyMsg, kAvTask, kAvAnimTask, kAvSeekTask, kAvBlendedSeekTask,
    kAvOneShotTask, kAvEnableTask, kAvTaskBrain, kAnimStage, kNetClientMember,
    kNetClientCommTask, kNetServerMsgAuthRequest, kNetServerMsgAuthReply,
    kNetClientCommAuthTask, kClientGuid, kNetMsgVaultPlayerList,
    kNetMsgSetMyActivePlayer, kNetServerMsgRequestAccountPlayerList,
    kNetServerMsgAccountPlayerList, kNetMsgPlayerCreated,
    kNetServerMsgVaultCreatePlayer, kNetServerMsgVaultPlayerCreated,
    kNetMsgFindAge, kNetMsgFindAgeReply, kNetClientConnectPrepTask,
    kNetClientAuthTask, kNetClientGetPlayerVaultTask,
    kNetClientSetActivePlayerTask, kNetClientFindAgeTask, kNetClientLeaveTask,
    kNetClientJoinTask, kNetClientCalibrateTask, kNetMsgDeletePlayer,
    kNetServerMsgVaultDeletePlayer, kNetCoreStatsSummary,
    kCreatableGenericValue, kCreatableListHelper, kCreatableStream,
    kAvBrainGenericMsg, kAvTaskSeek, kAGInstanceCallbackMsg, kArmatureEffectMsg,
    kArmatureEffectStateMsg, kShadowCastMsg, kBoundsIsect,
    kNetClientCommLeaveTask, kResMgrHelperMsg, kNetMsgAuthenticateResponse,
    kNetMsgAccountAuthenticated, kNetClientCommSendPeriodicAliveTask,
    kNetClientCommCheckServerSilenceTask, kNetClientCommPingTask,
    kNetClientCommFindAgeTask, kNetClientCommSetActivePlayerTask,
    kNetClientCommGetPlayerListTask, kNetClientCommCreatePlayerTask,
    kNetClientCommJoinAgeTask, kVaultAdminInitializationTask, kMultistageModMsg,
    kSoundVolumeApplicator, kCutter, kBulletMsg, kDynaDecalEnableMsg,
    kOmniCutoffApplicator, kArmatureUpdateMsg, kAvatarFootMsg, kNetOwnershipMsg,
    kNetMsgRelevanceRegions, kParticleFlockMsg, kAvatarBehaviorNotifyMsg,
    kATCChannel, kScalarSDLChannel, kLoadAvatarMsg, kAvatarSetTypeMsg,
    kNetMsgLoadClone, kNetMsgPlayerPage, kVNodeInitTask, kRippleShapeMsg,
    kEventManager, kVaultNeighborhoodInitializationTask,
    kNetServerMsgAgentRecoveryRequest, kNetServerMsgFrontendRecoveryRequest,
    kNetServerMsgBackendRecoveryRequest, kNetServerMsgAgentRecoveryData,
    kNetServerMsgFrontendRecoveryData, kNetServerMsgBackendRecoveryData,
    kSubWorldMsg, kMatrixDifferenceApp, kAvBrainUser, kDX9Pipeline, kDXPipeline,
    kPlayerMsg, kAvBrainPirahna, kAxisEventMsg, kCrossfadeMsg, kSubtitleMsg,
    kSDLStoreMsg, kOmniSqApplicator, kPreResourceMsg, kUNUSED_DynamicColorRGB,
    kUNUSED_DynamicMatrix33, kUNUSED_DynamicMatrix44, kCompoundController,
    kNetClientMgrMsg, kAgeLoaderMsg, kAvBrainAvatar, kPythonNotifyMsg,
    kNCAgeJoinerMsg, kAvTaskDumbSeek, kAvTaskSmartSeek, kCreatableUuid,
    kPreloaderMsg, kNetCommAuthConnectedMsg, kNetCommAuthMsg,
    kNetCommFileListMsg, kNetCommFileDownloadMsg, kNetCommLinkToAgeMsg,
    kNetCommPlayerListMsg, kNetCommActivePlayerMsg, kNetCommCreatePlayerMsg,
    kNetCommDeletePlayerMsg, kNetCommPublicAgeListMsg, kNetCommPublicAgeMsg,
    kNetCommRegisterAgeMsg, kAnimEvalMsg, kAvBrainFlight, kAvBrainNPC,
    kAvBrainBlimp, kAvBrainFlightNPC, kParticleBulletHitMsg, kPanicLinkMsg,
    kAvTaskOneShot,
    
    kVaultGameServerInitializationTask = 0x421, kNetClientFindDefaultAgeTask,
    kVaultAgeNode, kVaultAgeInitializationTask, kSetListenerMsg,
    kVaultSystemNode, kAvBrainSwim, kNetMsgVault, kNetServerMsgVault,
    kVaultTask, kVaultConnectTask, kVaultNegotiateManifestTask,
    kVaultFetchNodesTask, kVaultSaveNodeTask, kVaultFindNodeTask,
    kVaultAddNodeRefTask, kVaultRemoveNodeRefTask, kVaultSendNodeTask,
    kVaultNotifyOperationCallbackTask, kVNodeMgrInitializationTask,
    kVaultPlayerInitializationTask, kNetVaultServerInitializationTask,
    kCommonNeighborhoodsInitTask, kVaultNodeRef, kVaultNode, kVaultFolderNode,
    kVaultImageNode, kVaultTextNoteNode, kVaultSDLNode, kVaultAgeLinkNode,
    kVaultChronicleNode, kVaultPlayerInfoNode, kVaultMgrNode, kVaultPlayerNode,
    kSynchEnableMsg, kNetVaultServerNode, kVaultAdminNode, kVaultGameServerNode,
    kVaultPlayerInfoListNode, kAvatarStealthModeMsg, kEventCallbackInterceptMsg,
    kDynamicEnvMapMsg, kClimbMsg, kIfaceFadeAvatarMsg, kAvBrainClimb,
    kSharedMeshBCMsg, kNetVoiceListMsg, kSwimMsg, kMorphDelta,
    kMatrixControllerCacheChannel, kVaultMarkerNode, kMarkerMsg,
    kPipeResMakeMsg, kPipeRTMakeMsg, kPipeGeoMakeMsg, kAvCoopMsg, kAvBrainCoop,
    kSimSuppressMsg, kVaultMarkerListNode, kAvTaskOrient, kAgeBeginLoadingMsg,
    kSetNetGroupIDMsg, kBackdoorMsg, kNetMsgPython, kPythonMsg,
    kStateDataRecord, kNetClientCommDeletePlayerTask, kNetMsgSetTimeout,
    kNetMsgActivePlayerSet, kNetClientCommSetTimeoutTask,
    kNetRoutableMsgOmnibus, kNetMsgGetPublicAgeList, kNetMsgPublicAgeList,
    kNetMsgCreatePublicAge, kNetMsgPublicAgeCreated, kNetServerMsgEnvelope,
    kNetClientCommGetPublicAgeListTask, kNetClientCommCreatePublicAgeTask,
    kNetServerMsgPendingMsgs, kNetServerMsgRequestPendingMsgs, kDbInterface,
    kDbProxyInterface, kDBGenericSQLDB, kMySqlDB, kNetGenericDatabase,
    kNetVaultDatabase, kNetServerMsgPlsUpdatePlayerReply, kVaultDisconnectTask,
    kNetClientCommSetAgePublicTask, kNetClientCommRegisterOwnedAge,
    kNetClientCommUnregisterOwnerAge, kNetClientCommRegisterVisitAge,
    kNetClientCommUnregisterVisitAge, kNetMsgRemovePublicAge,
    kNetMsgPublicAgeRemoved, kNetClientCommRemovePublicAgeTask, kCCRMessage,
    kAvOneShotLinkTask, kNetAuthDatabase, kAvatarOpacityCallbackMsg,
    kAGDetachCallbackMsg, kMovieEventMsg, kMovieMsg, kPipeTexMakeMsg, kEventLog,
    kDbEventLog, kSyslogEventLog, kCaptureRenderMsg, kAgeLoaded2Msg,
    kPseudoLinkEffectMsg, kPseudoLinkAnimTriggerMsg, kPseudoLinkAnimCallbackMsg,
    kClimbingWallMsg, kClimbEventMsg, kAvBrainQuab, kSDLGameTimeElapsedVar,
    kLinkEffectsDoneMsg, kSDLVar, kSDLStructVar, kSDLBoolVar, kSDLCharVar,
    kSDLByteVar, kSDLIntVar, kSDLUIntVar, kSDLFloatVar, kSDLDoubleVar,
    kSDLStringVar, kSDLTimeVar, kSDLUoidVar, kSDLVector3Var, kSDLPoint3Var,
    kSDLQuaternionVar, kSDLMatrix44Var, kSDLRGBAVar, kSDLAgeTimeOfDayVar,
    kSDLAgeTimeElapsedVar, kSDLMetaDoubleVar, kSDLFixedArrayStructVar,
    kSDLFixedArrayBoolVar, kSDLFixedArrayCharVar, kSDLFixedArrayByteVar,
    kSDLFixedArrayIntVar, kSDLFixedArrayUIntVar, kSDLFixedArrayFloatVar,
    kSDLFixedArrayDoubleVar, kSDLFixedArrayStringVar, kSDLFixedArrayTimeVar,
    kSDLFixedArrayUoidVar, kSDLFixedArrayVector3Var, kSDLFixedArrayPoint3Var,
    kSDLFixedArrayQuaternionVar, kSDLFixedArrayMatrix44Var,
    kSDLFixedArrayRGBAVar, kSDLDynArrayStructVar, kSDLDynArrayBoolVar,
    kSDLDynArrayCharVar, kSDLDynArrayByteVar, kSDLDynArrayIntVar,
    kSDLDynArrayUIntVar, kSDLDynArrayFloatVar, kSDLDynArrayDoubleVar,
    kSDLDynArrayStringVar, kSDLDynArrayTimeVar, kSDLDynArrayUoidVar,
    kSDLDynArrayVector3Var, kSDLDynArrayPoint3Var, kSDLDynArrayQuaternionVar,
    kSDLDynArrayMatrix44Var, kSDLDynArrayRGBAVar, kSDLArrayVar,
    kSDLVarChangeMsg, kAvBrainPath, kSDLBufferVar, kSDLFixedArrayBufferVar,
    kSDLDynArrayBufferVar, kMatrixBorrowedChannel, kNodeRegionMsg,
    kEventCallbackSetupMsg, kRelativeMatrixChannelApplicator, kPiranhaRegionMsg,
    kGameMgrMsg, kGameCliMsg, kGameCli, kGmTicTacToe, kGmHeek, kGmMarker,
    kGmBlueSpiral, kAccountUpdateMsg, kAIMsg, kAIBrainCreatedMsg,
    kGmClimbingWall, kAIArrivedAtGoalMsg, kGmVarSync, kLinearVelocityMsg,
    kAngularVelocityMsg, kRideAnimatedPhysMsg, kAvBrainRideAnimatedPhysical
} pdClassType;

#endif
