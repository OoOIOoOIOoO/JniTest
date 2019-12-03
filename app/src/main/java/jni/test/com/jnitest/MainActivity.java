package jni.test.com.jnitest;

import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        sendData("dddddddseef");
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

    }
    public void sendData(String pkgName) {
        Bundle bundle = this.getApplicationContext().getContentResolver().call(Uri.parse("content://com.bangcle.db.provider"),"uploadForCheck",pkgName,null);
        if(bundle!=null){
             Log.e("ss","dddd:==="+bundle.getBoolean("result"));
        }else {
            Log.e("ss","va:eeeeeeeeeee==" + pkgName);
        }
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
