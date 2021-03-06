package com.dd.ndk;

import java.io.File;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {
	
	/**
	 * ndk 开发流程 
	 * 1. 编写 java 层 Native 方法 
	 * 2. 使用 javah 命令生成头文件(进入到scr javah com.dd.ndk.NDKFileUtils) 
	 * 3. 创建 jni 文件夹 , 将2生成的文件复制进去
	 * 4. 添加本地支持 android Tools -> add native support --这样就可以弹出提示, 而且不会有警告
	 * 5. 实现头文件中定义的方法
	 * 6. 编译生成 so 动态库
	 * 7. 加载动态库
	 */
	
	/**
	 * 文件说明:
	 * Android.mk -- 配置导出so包名, 开始文件
	 * Application.mk -- 配置生成支持
	 */

	/**
	 * 日志输入需要在 Android.mk 文件下添加 LOCAL_LDLIBS := -llog
	 */
	
	/**
	 * 如果 4 配置完还不行 
	 * 配置 properties -> c/c++ general -> path and symbols .
	 * D:\Develop\Android\sdk\ndk-bound-r10\toolchains\arm-linux-androideabi-4.6\prebuilt\windows-x86_64\lib\gcc\arm-linux-androideabi\4.6\include .
	 * D:\Develop\Android\sdk\ndk-bound-r10\toolhains\arm-linux-androideabi-4.6\prebuilt\windows-x86_64\lib\gcc\arm-linux-androideabi\4.6\include-fixed .
	 * D:\Develop\Android\sdk\ndk-bound-r10\platfcorms\android-18\arch-arm下usr的include
	 */
	
	/**
	 * 每次运行都需要重新build so 包
	 * 配置 properties -> c/c++ build -> behaviour -> 去掉 build, clean
	 */
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	/**
	 * 加密
	 */
	public void crypt(View view) {
		String normal = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "1.jpg";
		String crypt = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "2.jpg";
		Cryptor.crypt(normal, crypt);
	}

	/**
	 * 解密
	 */
	public void decrypt(View view) {
		String crypt = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "2.jpg";
		String decrypt = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "3.jpg";
		Cryptor.decrypt(crypt, decrypt);
	}
	
	/**
	 * 拆分
	 */
	public void diff(View view){
		String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "1.jpg";
		String path_pattern = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "1_%d.jpg";
		Cryptor.diff(path, path_pattern, 3);
	}
	
	/**
	 * 合并
	 */
	public void path(View view){
		String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "1_patch.jpg";
		String path_pattern = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator + "1_%d.jpg";
		
		Cryptor.patch(path_pattern, 3, path);
		
	}
}
