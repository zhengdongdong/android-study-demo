LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := AndroidNdk
LOCAL_SRC_FILES := AndroidNdk.c

include $(BUILD_SHARED_LIBRARY)
