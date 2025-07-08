--- libvpl/src/mfx_dispatcher_vpl_msdk.cpp.orig	2025-07-08 02:12:04 UTC
+++ libvpl/src/mfx_dispatcher_vpl_msdk.cpp
@@ -11,7 +11,7 @@
     #include "src/mfx_dispatcher_vpl_win.h"
 #endif
 
-#ifdef __linux__
+#ifdef __unix__
     #include <pthread.h>
     #define strncpy_s(dst, size, src, cnt) strncpy((dst), (src), (cnt)) // NOLINT
 #endif
@@ -97,7 +97,7 @@ static const mfxImplementedFunctions msdkImplFuncs = {
     (mfxChar**)msdkImplFuncsNames
 };
 
-#ifdef __linux__
+#ifdef __unix__
 // optional extBuf to limit threads created in MSDK session creation
 // to enable, set vplParam.NumExtParam and vplParam.ExtParam before calling MFXInitEx2()
 static const mfxExtThreadsParam extThreadParam = {
@@ -142,7 +142,7 @@ mfxStatus LoaderCtxMSDK::OpenSession(mfxSession *sessi
     mfxInitializationParam vplParam = {};
     vplParam.AccelerationMode       = accelMode;
 
-#ifdef __linux__
+#ifdef __unix__
     vplParam.ExtParam    = (mfxExtBuffer **)&extParams;
     vplParam.NumExtParam = 1;
 #else
@@ -183,7 +183,7 @@ mfxStatus LoaderCtxMSDK::GetDefaultAccelType(mfxU32 ad
 }
 
 mfxStatus LoaderCtxMSDK::GetDefaultAccelType(mfxU32 adapterID, mfxIMPL *implDefault, mfxU64 *luid) {
-#ifdef __linux__
+#ifdef __unix__
     // VAAPI only
     *implDefault = MFX_IMPL_VIA_VAAPI;
     *luid        = 0;
@@ -235,7 +235,7 @@ mfxStatus LoaderCtxMSDK::QueryAPIVersion(STRING_TYPE l
         vplParam.AccelerationMode =
             (mfxAccelerationMode)CvtAccelType(MFX_IMPL_HARDWARE, implDefault & 0xFF00);
 
-#ifdef __linux__
+#ifdef __unix__
         vplParam.ExtParam    = (mfxExtBuffer **)&extParams;
         vplParam.NumExtParam = 1;
 #else
@@ -279,7 +279,7 @@ mfxStatus LoaderCtxMSDK::QueryMSDKCaps(STRING_TYPE lib
     m_libNameFull = libNameFull;
     m_deviceID    = 0;
 
-#ifdef __linux__
+#ifdef __unix__
     // require pthreads to be linked in for MSDK RT to load
     pthread_key_t pkey;
     if (pthread_key_create(&pkey, NULL) == 0) {
