package com.example.l7;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class DetailsActivity extends AppCompatActivity {
	TextView textView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_details);

		Intent intent = getIntent();
		String stringData = intent.getStringExtra("itemName");

		textView = findViewById(R.id.detailsName);
		textView.setText(stringData);

		stringData = intent.getStringExtra("itemDept");
		textView = findViewById(R.id.detailsDept);
		textView.setText(stringData);

		stringData = intent.getStringExtra("itemYear");
		textView = findViewById(R.id.detailsYear);
		textView.setText(stringData);

	}
}
