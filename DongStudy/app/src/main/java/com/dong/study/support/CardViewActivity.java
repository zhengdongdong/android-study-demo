package com.dong.study.support;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;

import com.dong.study.R;

/**
 * Created by Zdd on 2016/7/7.
 */
public class CardViewActivity extends AppCompatActivity {

    /**
     * foreground + clickable = 水波纹效果
     * stateListAnimator = 下沉效果
     */

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_card_view);

    }
}
