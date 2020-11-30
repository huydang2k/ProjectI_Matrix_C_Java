	
#include <jni.h>
#include <stdio.h>
JNIEnv* create_vm(JavaVM **jvm)
{
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options;
    args.version = JNI_VERSION_1_6;
    args.nOptions = 1;
    options.optionString = "-Djava.class.path=./";
    args.options = &options;
    args.ignoreUnrecognized = 0;
    int rv;
    rv = JNI_CreateJavaVM(jvm, (void**)&env, &args);
    if (rv < 0 || !env)
        printf("Unable to Launch JVM %d\n",rv);
    else
        printf("Launched JVM! :)\n");
    return env;
}

int main(int argc, char **argv)
{
  	JavaVM *jvm;
   	JNIEnv *env;
   	env = create_vm(&jvm);
   	if(env == NULL)
       	return 1;

    	//Input
	printf("Nhap m,n,k: ");
	int m,n,k;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&k);

	int arr1[m][n];
	int arr2[n][k];
	//Input
	jclass jintarr = (*env)->FindClass(env,"[I");
	jobjectArray jarr1 = (*env)->NewObjectArray(env,m,jintarr,NULL);
	jobjectArray jarr2 = (*env)->NewObjectArray(env,n,jintarr,NULL);

	printf("Input matrix 1:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		scanf("%d",&arr1[i][j]);

		jintArray intArray  = (*env)->NewIntArray(env,n);
    		(*env)->SetIntArrayRegion(env,intArray,0,n,arr1[i]);
     		(*env)->SetObjectArrayElement(env,jarr1,i,intArray);
	}
	printf("Input Matrix 2:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		scanf("%d",&arr2[i][j]);

		jintArray intArray  = (*env)->NewIntArray(env,k);
    		(*env)->SetIntArrayRegion(env,intArray,0,k,arr2[i]);
     		(*env)->SetObjectArrayElement(env,jarr2,i,intArray);
	}
	//Call java
	jclass jmatrixclass =  (*env)->FindClass(env,"MatrixUtil");
	jmethodID constructId = (*env)->GetMethodID(env, jmatrixclass, "<init>", "()V");
	jobject jutilobject = (*env)->NewObject(env, jmatrixclass, constructId);

	jmethodID multiplyMethodId = (*env)->GetMethodID(env, jmatrixclass, "multiply", "([[I[[IIII)[[I");;
	jobjectArray jarr3 = (*env)->CallObjectMethod(env,jutilobject,multiplyMethodId,jarr1,jarr2,m,n,k);

	printf("The product of two matrices:\n");
	int arr3[m][k];
	for(int i = 0; i <= m -1; i++)
  	  {
    		jintArray tmp = (jintArray) (*env)->GetObjectArrayElement(env,jarr3,i);
     		(*env)->GetIntArrayRegion(env,tmp,0,k,arr3[i]);

            for (int j = 0; j <= k-1; j++)
    			printf("%d ",arr3[i][j]);
     		 printf("\n");
     }


    return 0;
}

