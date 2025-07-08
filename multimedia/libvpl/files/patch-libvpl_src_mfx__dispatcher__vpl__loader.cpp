--- libvpl/src/mfx_dispatcher_vpl_loader.cpp.orig	2025-04-18 15:44:33 UTC
+++ libvpl/src/mfx_dispatcher_vpl_loader.cpp
@@ -426,13 +426,15 @@ mfxU32 LoaderCtxVPL::GetSearchPathsSystemDefault(std::
 
 #ifdef __linux__
     // Add the standard path for libmfx1 install in Ubuntu
-    searchDirs.push_back("/usr/lib/x86_64-linux-gnu");
+    searchDirs.push_back("/usr/local/lib/x86_64-linux-gnu");
+#endif
 
+#ifdef __unix__
     // Add other default paths
     searchDirs.push_back("/lib");
-    searchDirs.push_back("/usr/lib");
+    searchDirs.push_back("/usr/local/lib");
     searchDirs.push_back("/lib64");
-    searchDirs.push_back("/usr/lib64");
+    searchDirs.push_back("/usr/local/lib64");
 #endif
 
     return (mfxU32)searchDirs.size();
