--- libvpl/src/mfx_dispatcher_vpl_loader.cpp.orig	2025-12-17 23:04:39 UTC
+++ libvpl/src/mfx_dispatcher_vpl_loader.cpp
@@ -432,7 +432,7 @@ mfxU32 LoaderCtxVPL::GetSearchPathsSystemDefault(std::
 mfxU32 LoaderCtxVPL::GetSearchPathsSystemDefault(std::list<STRING_TYPE> &searchDirs) {
     searchDirs.clear();
 
-#ifdef __linux__
+#ifdef __unix__
     // Add the standard path for libmfx1 install in Ubuntu
     searchDirs.push_back("/usr/lib/x86_64-linux-gnu");
 
@@ -450,7 +450,7 @@ mfxU32 LoaderCtxVPL::GetSearchPathsInstallDir(std::lis
 mfxU32 LoaderCtxVPL::GetSearchPathsInstallDir(std::list<STRING_TYPE> &searchDirs) {
     searchDirs.clear();
 
-    #ifdef __linux__
+    #ifdef __unix__
     STRING_TYPE install_dir = INSTALL_LIBDIR_SEARCH;
     searchDirs.push_back(install_dir);
     #endif
