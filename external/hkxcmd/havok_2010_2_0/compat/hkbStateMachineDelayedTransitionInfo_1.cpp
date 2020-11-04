// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "stdafx.h"
#include "hkbStateMachineDelayedTransitionInfo_1.h"

#include <Common/Serialize/hkSerialize.h>
#include <Common/Serialize/Util/hkSerializeUtil.h>
#include <Common/Serialize/Version/hkVersionPatchManager.h>
#include <Common/Serialize/Data/Dict/hkDataObjectDict.h>
#include <Common/Serialize/Data/Native/hkDataObjectNative.h>
#include <Common/Serialize/Data/Util/hkDataObjectUtil.h>
#include <Common/Base/Reflection/Registry/hkDynamicClassNameRegistry.h>
#include <Common/Base/Reflection/Registry/hkVtableClassRegistry.h>
#include <Common/Base/Reflection/hkClass.h>
#include <Common/Base/Reflection/hkInternalClassMember.h>
#include <Common/Serialize/Util/hkSerializationCheckingUtils.h>
#include <Common/Serialize/Util/hkVersionCheckingUtils.h>


static const hkInternalClassMember hkbStateMachineDelayedTransitionInfoClass_Members[] =
{
   { "delayedTransition",&hkbStateMachineProspectiveTransitionInfoClass,HK_NULL,hkClassMember::TYPE_STRUCT,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbStateMachineDelayedTransitionInfo,m_delayedTransition) /*0*/,HK_NULL},
   { "timeDelayed",HK_NULL,HK_NULL,hkClassMember::TYPE_REAL,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbStateMachineDelayedTransitionInfo,m_timeDelayed) /*16*/,HK_NULL},
   { "isDelayedTransitionReturnToPreviousState",HK_NULL,HK_NULL,hkClassMember::TYPE_BOOL,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbStateMachineDelayedTransitionInfo,m_isDelayedTransitionReturnToPreviousState) /*20*/,HK_NULL},
   { "wasInAbutRangeLastFrame",HK_NULL,HK_NULL,hkClassMember::TYPE_BOOL,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbStateMachineDelayedTransitionInfo,m_wasInAbutRangeLastFrame) /*21*/,HK_NULL},
};

// Signature:  026d5499
extern const hkClass hkbStateMachineDelayedTransitionInfoClass;
const hkClass hkbStateMachineDelayedTransitionInfoClass(
    "hkbStateMachineDelayedTransitionInfo",
    HK_NULL, // parent
    sizeof(hkbStateMachineDelayedTransitionInfo),
    HK_NULL, 0, // interfaces
    HK_NULL, 0, // enums
    reinterpret_cast<const hkClassMember*>(hkbStateMachineDelayedTransitionInfoClass_Members), HK_COUNT_OF(hkbStateMachineDelayedTransitionInfoClass_Members),
    HK_NULL, // defaults
    HK_NULL, // attributes
    0, // flags
    1 // version
 );
HK_REFLECTION_DEFINE_SIMPLE(hkbStateMachineDelayedTransitionInfo, hkbStateMachineDelayedTransitionInfo);

