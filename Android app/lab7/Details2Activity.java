package com.example.l7;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class Details2Activity extends AppCompatActivity {

	TextView textView;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_details2);

		Intent intent = getIntent();
		String stringData = intent.getStringExtra("itemName2");

		textView = findViewById(R.id.detailsName2);
		textView.setText(stringData);

		stringData = intent.getStringExtra("itemDept2");
		textView = findViewById(R.id.detailsDept2);
		textView.setText(stringData);

		stringData = intent.getStringExtra("itemYear2");
		textView = findViewById(R.id.detailsYear2);
		textView.setText(stringData);
	}
}
