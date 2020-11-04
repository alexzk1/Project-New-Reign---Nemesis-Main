// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "stdafx.h"
#include "hkbSetWorldFromModelModifier_0.h"

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


static const hkInternalClassMember hkbSetWorldFromModelModifierClass_Members[] =
{
   { "translation",HK_NULL,HK_NULL,hkClassMember::TYPE_VECTOR4,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbSetWorldFromModelModifier,m_translation) /*48*/,HK_NULL},
   { "rotation",HK_NULL,HK_NULL,hkClassMember::TYPE_QUATERNION,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbSetWorldFromModelModifier,m_rotation) /*64*/,HK_NULL},
   { "setTranslation",HK_NULL,HK_NULL,hkClassMember::TYPE_BOOL,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbSetWorldFromModelModifier,m_setTranslation) /*80*/,HK_NULL},
   { "setRotation",HK_NULL,HK_NULL,hkClassMember::TYPE_BOOL,hkClassMember::TYPE_VOID,0,hkClassMember::FLAGS_NONE,HK_OFFSET_OF(hkbSetWorldFromModelModifier,m_setRotation) /*81*/,HK_NULL},
};

// Signature:  afcfa211
extern const hkClass hkbModifierClass;
extern const hkClass hkbSetWorldFromModelModifierClass;
const hkClass hkbSetWorldFromModelModifierClass(
    "hkbSetWorldFromModelModifier",
    &hkbModifierClass, // parent
    sizeof(hkbSetWorldFromModelModifier),
    HK_NULL, 0, // interfaces
    HK_NULL, 0, // enums
    reinterpret_cast<const hkClassMember*>(hkbSetWorldFromModelModifierClass_Members), HK_COUNT_OF(hkbSetWorldFromModelModifierClass_Members),
    HK_NULL, // defaults
    HK_NULL, // attributes
    0, // flags
    0 // version
 );
HK_REFLECTION_DEFINE_VIRTUAL(hkbSetWorldFromModelModifier, hkbSetWorldFromModelModifier);

