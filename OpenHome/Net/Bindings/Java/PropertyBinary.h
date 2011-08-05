/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_openhome_net_core_PropertyBinary */

#ifndef _Included_org_openhome_net_core_PropertyBinary
#define _Included_org_openhome_net_core_PropertyBinary
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_openhome_net_core_PropertyBinary
 * Method:    ServicePropertyCreateBinaryCp
 * Signature: (Ljava/lang/String;Lorg/openhome/net/controlpoint/IPropertyChangeListener;)Lorg/openhome/net/core/Property/PropertyInitialised;
 */
JNIEXPORT jobject JNICALL Java_org_openhome_net_core_PropertyBinary_ServicePropertyCreateBinaryCp
  (JNIEnv *, jobject, jstring, jobject);

/*
 * Class:     org_openhome_net_core_PropertyBinary
 * Method:    ServicePropertyCreateBinaryDv
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_openhome_net_core_PropertyBinary_ServicePropertyCreateBinaryDv
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_openhome_net_core_PropertyBinary
 * Method:    ServicePropertyGetValueBinary
 * Signature: (J)[B
 */
JNIEXPORT jbyteArray JNICALL Java_org_openhome_net_core_PropertyBinary_ServicePropertyGetValueBinary
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_openhome_net_core_PropertyBinary
 * Method:    ServicePropertySetValueBinary
 * Signature: (J[BI)I
 */
JNIEXPORT jint JNICALL Java_org_openhome_net_core_PropertyBinary_ServicePropertySetValueBinary
  (JNIEnv *, jclass, jlong, jbyteArray, jint);

#ifdef __cplusplus
}
#endif
#endif